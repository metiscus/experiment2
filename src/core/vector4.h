#pragma once
#include "vector3.h"

#include <cstdint>

struct Vector4
{
    float w;
    float x;
    float y;
    float z;

    Vector4(float w_ = 0.0f, float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f);

    float Dot(const Vector4& other) const;
    
    float Length2() const;
    float Length() const;
    Vector4 AsUnit() const;
    void ToUnit();
    
    Vector4 Conjugate() const;
    
    Vector4 operator+(const Vector4& rhs) const;
    Vector4 operator-(const Vector4& rhs) const;
    Vector4& operator+=(const Vector4& rhs);
    Vector4& operator-=(const Vector4& rhs);
    Vector4 operator*(const float& rhs) const;
    Vector4 operator/(const float& rhs) const;
    Vector4& operator*=(const float& rhs);
    Vector4& operator/=(const float& rhs);
    
    float operator[] (const uint32_t& idx) const;
    
    void Set(const float& w_, const float& x_, const float& y_, const float& z_);
    
    Vector4 operator*(const Vector4& rhs) const;
    Vector3 Rotate(const Vector3& rhs) const;
};

Vector4 operator*(float lhs, const Vector4& rhs);
