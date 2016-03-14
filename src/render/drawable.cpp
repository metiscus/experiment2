#include "drawable.h"
#include "state.h"

Drawable::Drawable(Type type)
    : type_(type)
{
    
}

const Drawable::Type Drawable::GetType() const
{
    return type_;
}
