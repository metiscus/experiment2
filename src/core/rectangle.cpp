#include "rectangle.h"

Rectangle::Rectangle()
{
    
}

Rectangle::Rectangle(const Vector2& center, const Vector2& extents)
    : center_(center)
    , extents_(extents)
{
    UpdateMinMax();
}

Rectangle::Rectangle(float x, float y, float w, float h)
    : center_(x, y)
    , extents_(w, h)
{
    UpdateMinMax();
}

void Rectangle::SetCenter(const Vector2& center)
{
    center_ = center;
    UpdateMinMax();
}

void Rectangle::SetExtents(const Vector2& extents)
{
    extents_ = extents;
    UpdateMinMax();
}

const Vector2& Rectangle::GetCenter() const
{
    return center_;
}

const Vector2& Rectangle::GetExtents() const
{
    return extents_;
}

const Vector2& Rectangle::GetMin() const
{
    return min_;
}

const Vector2& Rectangle::GetMax() const
{
    return max_;
}

bool Rectangle::ContainsPoint(const Vector2& point) const
{
    if(point.x < min_.x) return false;
    if(point.x > max_.x) return false;
    if(point.y < min_.y) return false;
    if(point.y > max_.y) return false;
    return true;
}

bool Rectangle::Intersects(const Rectangle& other) const
{
    return !( min_.x > other.min_.x
        || max_.x < other.min_.x
        || max_.y > other.min_.y
        || min_.y < other.max_.y
    );
}

void Rectangle::UpdateMinMax()
{
    min_ = center_ - 0.5f * extents_;
    max_ = center_ + 0.5f * extents_;
}
