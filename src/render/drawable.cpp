#include "drawable.h"
#include "state.h"

Drawable::Drawable(Type type)
    : type_(type)
{
    
}

std::shared_ptr<State> Drawable::GetOrCreateState()
{
    if(!state_)
    {
        state_.reset(new State());
    }
    return state_;
}

void Drawable::SetState(std::shared_ptr<State> state)
{
    state_ = state;
}

const Drawable::Type Drawable::GetType() const
{
    return type_;
}
