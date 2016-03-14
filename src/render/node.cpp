#include "node.h"
#include <cassert>

Node::Node()
{
    
}

Node::~Node()
{
    
}

Group* Node::AsGroup()
{
    return nullptr;
}

Drawable* Node::AsDrawable()
{
    return nullptr;
}

Sprite* Node::AsSprite()
{
    return nullptr;
}

Transform* Node::AsTransform()
{
    return nullptr;
}

const Group* Node::AsGroup() const
{
    return nullptr;
}

const Drawable* Node::AsDrawable() const
{
    return nullptr;
}

const Sprite* Node::AsSprite() const
{
    return nullptr;
}

const Transform* Node::AsTransform() const
{
    return nullptr;
}

std::shared_ptr<State> Node::GetOrCreateState()
{
    if(!state_)
    {
        state_.reset(new State());
    }
}

void Node::SetState(std::shared_ptr<State> state)
{
    state_ = state;
}

uint32_t Node::GetNumParents() const
{
    return parents_.size();
}

std::weak_ptr<Group> Node::GetParent(uint32_t idx)
{
    
}

void Node::AddParent(NodePtr parent)
{
    parents_.push_back(NodeWeakPtr(parent));
}

void Node::RemoveParent(NodePtr parent)
{
    for(auto itr = parents_.begin(); itr!=parents.end(); ++itr)
    {
        NodePtr node = itr->lock();

        if(node == parent)
        {
            parents.erase(itr);
            break;
        }
    }
}
