#include "eventsystem.h"
#include <cassert>
#include "event.h"
#include "eventhandler.h"
#include "events/quit.h"
#include "events/keyboard.h"
#include "events/mouse.h"
#include <SDL.h>
#include <cstdio>

std::thread::id EventSystem::main_id_;
std::unique_ptr<EventSystem> EventSystem::system_(nullptr);

EventSystem::EventSystem()
    : current_queue_(0)
{
    SDL_InitSubSystem(SDL_INIT_EVENTS);
    SDL_InitSubSystem(SDL_INIT_TIMER);
    SDL_InitSubSystem(SDL_INIT_JOYSTICK);
    SDL_InitSubSystem(SDL_INIT_GAMECONTROLLER);
}

void EventSystem::CreateInstance()
{
    system_ = std::unique_ptr<EventSystem>(new EventSystem());
}

void EventSystem::DestroyInstance()
{
    system_.release();
}

EventSystem& EventSystem::GetInstance()
{
    return *system_;
}

void EventSystem::Initialize()
{
    main_id_ = std::this_thread::get_id();
    CreateInstance();
}

void EventSystem::Shutdown()
{
    // no-op
    DestroyInstance();
}

void EventSystem::AddEvent(Event* event)
{
    assert(event);
    event_queues_[current_queue_].push_back(event);
}

void EventSystem::AddEventHandler(std::weak_ptr<EventHandler> handler)
{
    handlers_.push_back(handler);
}

void EventSystem::PumpGlobalEvents()
{
    assert(main_id_ == std::this_thread::get_id());
    SDL_Event event;
    uint32_t start = SDL_GetTicks();
    while(SDL_PollEvent(&event) == 1)
    {
        switch(event.type)
        {
            case SDL_QUIT:
                AddEvent(new QuitEvent());
                break;
            case SDL_KEYDOWN:
                AddEvent(new KeyboardEvent(KeyboardEvent::KeyDown, event.key.keysym.sym));
                break;
            case SDL_KEYUP:
                AddEvent(new KeyboardEvent(KeyboardEvent::KeyUp, event.key.keysym.sym));
                break;
            case SDL_MOUSEMOTION:
            {
                MouseEvent::ButtonState state;
                state.left   = event.motion.state & SDL_BUTTON(1);
                state.middle = event.motion.state & SDL_BUTTON(2);
                state.right  = event.motion.state & SDL_BUTTON(3);
                AddEvent(new MouseEvent(state, event.motion.x, event.motion.y)); 
                break;
            }
            default:
                fprintf(stderr, "EventSystem::PumpGlobalEvents Received an unhandled event.\n");
                break;
        }
        
#if 0
        if(SDL_GetTicks() - start > 5)
        {
            fprintf(stderr, "EventSystem::PumpGlobalEvents is overrunning.\n");
            break;
        }
#endif
    }
}

void EventSystem::ProcessEvents()
{
    // Lock all of the weak pointers so nothing drops off during the event processing
    std::list< std::shared_ptr<EventHandler> > handlers;
    for(auto weak_handler : handlers_)
    {
        auto handler = weak_handler.lock();
        if(handler)
        {
            handlers.push_back(handler);
        }
    }

    // Process events
    for(auto event : event_queues_[current_queue_])
    {
        for(auto handler : handlers)
        {
            if(handler->HandlesEventType(event->GetType()))
            {
                handler->HandleEvent(event);
            }
        }
        delete event;
    }

    handlers.clear();
    event_queues_[current_queue_].clear();

    if(current_queue_ == 0)
    {
        current_queue_ = 1;
    }
    else
    {
        current_queue_ = 0;
    }
}

void EventSystem::RemoveEventHandler(std::shared_ptr<EventHandler> handler)
{
    for(auto itr = handlers_.begin(); itr != handlers_.end(); ++itr)
    {
        auto ptr_handler = itr->lock();
        if(ptr_handler == handler)
        {
            handlers_.erase(itr);
            break;
        }
    }
}
