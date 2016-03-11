#pragma once

#include <cstdint>
#include "../event.h"

#include <SDL.h>

class KeyboardEvent : public Event
{
public:
    enum KeyEvent
    {
        KeyDown,
        KeyUp
    };

    static const Event::Type type;
    KeyboardEvent(KeyEvent event, SDL_Keycode key);
    const KeyEvent GetKeyEvent() const;
    const SDL_Keycode GetKey() const;

private:
    const KeyEvent event_;
    const SDL_Keycode key_;
};
