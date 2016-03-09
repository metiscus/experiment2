#pragma once

#include "event.h"
#include <vector>

class EventHandler
{
public:
    EventHandler() = default;
    virtual ~EventHandler() = default;

    virtual bool HandlesEventType(const Event::Type& type) const = 0;
    virtual void HandleEvent(const Event* ptr) = 0;
};
