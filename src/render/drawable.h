#pragma once

#include "array.h"
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

    std::shared_ptr<State> GetOrCreateState();
    void SetState(std::shared_ptr<State> state);

    const Type GetType() const;

private:
    Type type_;
    std::shared_ptr<State> state_;
};
