#pragma once

#include <core/math.h>
#include <cstdint>
#include <list>
#include <memory>
#include "state.h"

class Drawable;
class Group;
class Transform;
class Sprite;

class Node;
typedef std::shared_ptr<Node> NodePtr;
typedef std::weak_ptr<Node> NodeWeakPtr;

class Node
{
public:
    Node();
    virtual ~Node();

    Node(const Node&) = delete;
    Node& operator=(Node&) = delete;

    virtual Group* AsGroup();
    virtual Drawable* AsDrawable();
    virtual Sprite* AsSprite();
    virtual Transform* AsTransform();

    virtual const Group* AsGroup() const;
    virtual const Drawable* AsDrawable() const;
    virtual const Sprite* AsSprite() const;
    virtual const Transform* AsTransform() const;

    std::shared_ptr<State> GetOrCreateState();
    void SetState(std::shared_ptr<State> state);
    
    uint32_t GetNumParents() const;
    std::weak_ptr<Group> GetParent(uint32_t idx);

protected:
    void AddParent(NodePtr parent);
    void RemoveParent(NodePtr parent);

private:
    std::shared_ptr<State> state_;
    std::list<NodeWeakPtr> parents_;
};
