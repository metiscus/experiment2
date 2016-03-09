#include "eventsystem.h"
#include <cassert>
#include "event.h"
#include "eventhandler.h"
#include "events/quit.h"
#include <SDL.h>

std::thread::id EventSystem::main_id_;
std::unique_ptr<EventSystem> EventSystem::system_(nullptr);

EventSystem::EventSystem()
    : current_queue_(0)
{
    ;
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
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                AddEvent(new QuitEvent());
                break;
            default:
                //TODO
                break;
        }
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
    //TODO
}
