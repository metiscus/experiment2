#pragma once

#include <cstdint>

struct Vector3
{
    float w;
    float x;
    float y;
    float z;

    Vector3(float x_ = 0.0f, float y_ = 0.0f, float z_ = 0.0f);

    float Dot(const Vector3& other) const;
    Vector3 Cross(const Vector3& other) const;
    
    float Length2() const;
    float Length() const;
    Vector3 AsUnit() const;
    void ToUnit();
    
    Vector3 operator+(const Vector3& rhs) const;
    Vector3 operator-(const Vector3& rhs) const;
    Vector3& operator+=(const Vector3& rhs);
    Vector3& operator-=(const Vector3& rhs);
    Vector3 operator*(const float& rhs) const;
    Vector3 operator/(const float& rhs) const;
    Vector3& operator*=(const float& rhs);
    Vector3& operator/=(const float& rhs);
    
    float operator[] (const uint32_t& idx) const;
    
    void Set(const float& x_, const float& y_, const float& z_);
};

Vector3 operator*(float lhs, const Vector3& rhs);
