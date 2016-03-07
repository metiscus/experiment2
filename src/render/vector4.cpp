#include "vector4.h"
#include <cassert>
#include <cmath>

Vector4::Vector4(float w_, float x_, float y_, float z_)
    : w(w_)
    , x(x_)
    , y(y_)
    , z(z_)
{
    ;
}

float Vector4::Dot(const Vector4& other) const
{
    return w*other.w + x*other.x + y*other.y + z*other.z;
}

float Vector4::Length2() const
{
    return w*w+x*x+y*y+z*z;
}

float Vector4::Length() const
{
    return sqrtf(w*w+x*x+y*y+z*z);
}

Vector4 Vector4::AsUnit() const
{
    float iLen = 1.0f / (Length() + 0.0001f);
    return Vector4(w*iLen, x*iLen, y*iLen, z*iLen);
}

void Vector4::ToUnit()
{
    float iLen = 1.0f / (Length() + 0.0001f);
    w*=iLen;
    x*=iLen;
    y*=iLen;
    z*=iLen;
}

Vector4 Vector4::Conjugate() const
{
    return Vector4(w, -x, -y, -z);
}

Vector4 Vector4::operator+(const Vector4& rhs) const
{
    return Vector4(w+rhs.w, x+rhs.x, y+rhs.y, z+rhs.z);
}

Vector4 Vector4::operator-(const Vector4& rhs) const
{
    return Vector4(w-rhs.w, x-rhs.x, y-rhs.y, z-rhs.z);
}

Vector4& Vector4::operator+=(const Vector4& rhs)
{
    w += rhs.w;
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
}

Vector4& Vector4::operator-=(const Vector4& rhs)
{
    w -= rhs.w;
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
}

Vector4 Vector4::operator*(const float& rhs) const
{
    return Vector4(w*rhs, x*rhs, y*rhs, z*rhs);
}

Vector4 Vector4::operator/(const float& rhs) const
{
    float iVal = 1.0f / rhs;
    return Vector4(w*iVal, x*iVal, y*iVal, z*iVal);
}

Vector4& Vector4::operator*=(const float& rhs)
{
    w *= rhs;
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

Vector4& Vector4::operator/=(const float& rhs)
{
    float iVal = 1.0f / rhs;
    w *= iVal;
    x *= iVal;
    y *= iVal;
    z *= iVal;
    return *this;
}

float Vector4::operator[] (const uint32_t& idx) const
{
    assert(idx < 4);
    switch(idx)
    {
        case 0: return w; break;
        case 1: return x; break;
        case 2: return y; break;
        case 3: return z; break;
        default: return 0.0f;
    }
}

void Vector4::Set(const float& w_, const float& x_, const float& y_, const float& z_)
{
    w = w_;
    x = x_;
    y = y_;
    z = z_;
}

Vector4 Vector4::operator*(const Vector4& rhs) const
{
    // performs the hamiltonian product
    return Vector4((w*rhs.w - x*rhs.x - y*rhs.y - z*rhs.z),
            (w*rhs.x + x*rhs.w + y*rhs.z - z*rhs.y),
            (w*rhs.y - x*rhs.z + y*rhs.w + z*rhs.x),
            (w*rhs.z - x*rhs.y - y*rhs.x + z*rhs.w));
}

Vector3 Vector4::Rotate(const Vector3& rhs) const
{
    Vector4 obj(0.0, rhs.x, rhs.y, rhs.z);
    Vector4 ret = (*this) * obj * Conjugate();
    return Vector3(ret.x, ret.y, ret.z);
}

Vector4 operator*(float lhs, const Vector4& rhs)
{
    return Vector4(rhs.w*lhs, rhs.x*lhs, rhs.y*lhs, rhs.z*lhs);
}

