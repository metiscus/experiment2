#pragma once

#include <cstdint>

struct Vector2
{
    float w;
    float x;
    float y;
    float z;

    Vector2(float x_ = 0.0f, float y_ = 0.0f);

    float Dot(const Vector2& other) const;
    
    float Length2() const;
    float Length() const;
    Vector2 AsUnit() const;
    void ToUnit();
    
    Vector2 operator+(const Vector2& rhs) const;
    Vector2 operator-(const Vector2& rhs) const;
    Vector2& operator+=(const Vector2& rhs);
    Vector2& operator-=(const Vector2& rhs);
    Vector2 operator*(const float& rhs) const;
    Vector2 operator/(const float& rhs) const;
    Vector2& operator*=(const float& rhs);
    Vector2& operator/=(const float& rhs);
    
    float operator[] (const uint32_t& idx) const;
    
    void Set(const float& x_, const float& y_);
};

Vector2 operator*(float lhs, const Vector2& rhs);
