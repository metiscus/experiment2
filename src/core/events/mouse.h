#pragma once

#include <cstdint>
#include "../event.h"

class MouseEvent : public Event
{
public:
    static const Event::Type type;
    
    struct ButtonState
    {
        uint32_t left : 1;
        uint32_t middle : 1;
        uint32_t right : 1;
        uint32_t empty : 29;
    };

    MouseEvent(ButtonState btn, uint32_t x, uint32_t y)
        : Event(type)
        , x_(x)
        , y_(y)
        , button_(btn)
    {
        
    }

    inline uint32_t GetX() const
    {
        return x_;
    }
    
    inline uint32_t GetY() const
    {
        return y_;
    }

private:
    uint32_t x_;
    uint32_t y_;
    ButtonState button_;
};
