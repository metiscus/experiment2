#include "event.h"

Event::Event(const Type& type)
    : type_(type)
{
    
}

const Event::Type& Event::GetType() const
{
    return type_;
}
