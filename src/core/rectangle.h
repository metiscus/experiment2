#pragma once

#include "math.h"

class Rectangle
{
public:
    Rectangle();
    Rectangle(const Vector2& center, const Vector2& extents);
    Rectangle(float x, float y, float w, float h);
    void SetCenter(const Vector2& center);
    void SetExtents(const Vector2& extents);
    const Vector2& GetCenter() const;
    const Vector2& GetExtents() const;
    const Vector2& GetMin() const;
    const Vector2& GetMax() const;
    
    bool ContainsPoint(const Vector2& point) const;
    bool Intersects(const Rectangle& other) const;
private:
    Vector2 center_;
    Vector2 extents_;
    Vector2 min_;
    Vector2 max_;

    void UpdateMinMax();
};
