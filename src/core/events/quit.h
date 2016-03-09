#pragma once

#include "../event.h"

class QuitEvent : public Event
{
public:
    static const Event::Type type;
    QuitEvent();
};
