#include "vector3.h"
#include <cassert>
#include <cmath>

Vector3::Vector3(float x_, float y_, float z_)
    : x(x_)
    , y(y_)
    , z(z_)
{
    ;
}

float Vector3::Dot(const Vector3& other) const
{
    return x*other.x + y*other.y + z*other.z;
}

Vector3 Vector3::Cross(const Vector3& other) const
{
    return Vector3( y*other.z-z*other.y,
                    x*other.z+z*other.x,
                    x*other.y-y*other.x );
}

float Vector3::Length2() const
{
    return x*x+y*y+z*z;
}

float Vector3::Length() const
{
    return sqrtf(x*x+y*y+z*z);
}

Vector3 Vector3::AsUnit() const
{
    float iLen = 1.0f / (Length() + 0.0001f);
    return Vector3(x*iLen, y*iLen, z*iLen);
}

void Vector3::ToUnit()
{
    float iLen = 1.0f / (Length() + 0.0001f);
    x*=iLen;
    y*=iLen;
    z*=iLen;
}

Vector3 Vector3::operator+(const Vector3& rhs) const
{
    return Vector3(x+rhs.x, y+rhs.y, z+rhs.z);
}

Vector3 Vector3::operator-(const Vector3& rhs) const
{
    return Vector3(x-rhs.x, y-rhs.y, z-rhs.z);
}

Vector3& Vector3::operator+=(const Vector3& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
}

Vector3& Vector3::operator-=(const Vector3& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
}

Vector3 Vector3::operator*(const float& rhs) const
{
    return Vector3(x*rhs, y*rhs, z*rhs);
}

Vector3 Vector3::operator/(const float& rhs) const
{
    float iVal = 1.0f / rhs;
    return Vector3(x*iVal, y*iVal, z*iVal);
}

Vector3& Vector3::operator*=(const float& rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

Vector3& Vector3::operator/=(const float& rhs)
{
    float iVal = 1.0f / rhs;
    x *= iVal;
    y *= iVal;
    z *= iVal;
    return *this;
}

float Vector3::operator[] (const uint32_t& idx) const
{
    assert(idx < 3);
    switch(idx)
    {
        case 0: return x; break;
        case 1: return y; break;
        case 2: return z; break;
        default: return 0.0f;
    }
}

void Vector3::Set(const float& x_, const float& y_, const float& z_)
{
    x = x_;
    y = y_;
    z = z_;
}

Vector3 operator*(float lhs, const Vector3& rhs)
{
    return Vector3(rhs.x * lhs, rhs.y*lhs, rhs.z*lhs);
}
