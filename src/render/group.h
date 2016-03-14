#pragma once

#include "node.h"
#include <list>

class Group : public Node
{
public:
    Group();
    virtual ~Group();

    Group(const Group&) = delete;
    Group& operator=(Group&) = delete;
    
    virtual Group* AsGroup();
    virtual const Group* AsGroup() const;
    
    void AddChild(NodePtr node);
    uint32_t GetNumChildren() const;
    NodePtr GetChildIdx(uint32_t idx);
    void RemoveChild(NodePtr node);
    
private:
    std::list<NodePtr> children_;
};
