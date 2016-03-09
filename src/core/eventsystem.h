#pragma once

#include <list>
#include <memory>
#include <thread>

class Event;
class EventHandler;

class EventSystem
{
public:
    static void Initialize();
    static void Shutdown();
    
    static void CreateInstance();
    static void DestroyInstance();
    static EventSystem& GetInstance();

    void AddEvent(Event* event);
    void AddEventHandler(std::weak_ptr<EventHandler> handler);
    void PumpGlobalEvents();
    void ProcessEvents();
    void RemoveEventHandler(std::shared_ptr<EventHandler> handler);

private:
    uint32_t current_queue_;
    std::list<Event*> event_queues_[2];
    std::list<std::weak_ptr<EventHandler> > handlers_;
    
    static std::thread::id main_id_;
    static std::unique_ptr<EventSystem> system_;
    
    EventSystem();
};
