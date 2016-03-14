#pragma once

#include "array.h"
#include "node.h"
#include "state.h"

class Drawable
{
public:
    enum Type
    {
        Triangles,
        Lines,
        Points
    };

    Drawable(Type type);
    virtual ~Drawable() = default;

    const Type GetType() const;

private:
    Type type_;
};
