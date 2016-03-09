#include "quit.h"

const Event::Type QuitEvent::type = 0x1000;

QuitEvent::QuitEvent()
    : Event(type)
{
}
