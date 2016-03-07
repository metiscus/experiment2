#include "vector2.h"
#include <cassert>
#include <cfloat>
#include <cmath>

Vector2::Vector2(float x_, float y_)
    : x(x_)
    , y(y_)
{
    ;
}

float Vector2::Dot(const Vector2& other) const
{
    return x*other.x + y*other.y;
}

float Vector2::Length2() const
{
    return x*x+y*y;
}

float Vector2::Length() const
{
    return sqrtf(x*x+y*y);
}

Vector2 Vector2::AsUnit() const
{
    float iLen = 1.0f / (Length() + FLT_EPSILON);
    return Vector2(x*iLen, y*iLen);
}

void Vector2::ToUnit()
{
    float iLen = 1.0f / (Length() + FLT_EPSILON);
    x*=iLen;
    y*=iLen;
}

Vector2 Vector2::operator+(const Vector2& rhs) const
{
    return Vector2(x+rhs.x, y+rhs.y);
}

Vector2 Vector2::operator-(const Vector2& rhs) const
{
    return Vector2(x-rhs.x, y-rhs.y);
}

Vector2& Vector2::operator+=(const Vector2& rhs)
{
    x += rhs.x;
    y += rhs.y;
}

Vector2& Vector2::operator-=(const Vector2& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
}

Vector2 Vector2::operator*(const float& rhs) const
{
    return Vector2(x*rhs, y*rhs);
}

Vector2 Vector2::operator/(const float& rhs) const
{
    return Vector2(x/(rhs+FLT_EPSILON), y/(rhs+FLT_EPSILON));
}

Vector2& Vector2::operator*=(const float& rhs)
{
    x *= rhs;
    y *= rhs;
    return *this;
}

Vector2& Vector2::operator/=(const float& rhs)
{
    float iVal = 1.0f / (rhs + FLT_EPSILON);
    x *= iVal;
    y *= iVal;
    return *this;
}

float Vector2::operator[] (const uint32_t& idx) const
{
    assert(idx < 2);
    switch(idx)
    {
        case 0: return x; break;
        case 1: return y; break;
        default: return 0.0f;
    }
}

void Vector2::Set(const float& x_, const float& y_)
{
    x = x_;
    y = y_;
}

Vector2 operator*(float lhs, const Vector2& rhs)
{
    return Vector2(rhs.x * lhs, rhs.y*lhs);
}
