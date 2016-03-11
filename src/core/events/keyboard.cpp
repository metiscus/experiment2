#include "keyboard.h"
#include <cassert>
#include <SDL.h>

const Event::Type KeyboardEvent::type = 0x1001;

KeyboardEvent::KeyboardEvent(KeyEvent event, SDL_Keycode key)
    : Event(type)
    , event_(event)
    , key_(key)
{
}

const KeyboardEvent::KeyEvent KeyboardEvent::GetKeyEvent() const
{
    return event_;
}

const SDL_Keycode KeyboardEvent::GetKey() const
{
    return key_;
}
