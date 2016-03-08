#pragma once

#include <core/math.h>
#include <cstdint>
#include <string>

class Uniform
{
public:
    enum Type {
        Uniform_1f,
        Uniform_2f,
        Uniform_3f,
        Uniform_4f,
        Uniform_mat2,
        Uniform_mat3,
        Uniform_mat4
    };

    Uniform(Type type, const char* name);
    ~Uniform();

    void Set(const Vector2& v);
    void Set(const Vector3& v);
    void Set(const Vector4& v);
    void Set(const Matrix3& m);
    void Set(const Matrix4& m);
    void Set(int x);
    
    void SetGLObject(uint32_t obj);
    const std::string& GetName() const;

protected:
    Uniform(const Uniform&)      = delete;
    Uniform& operator=(Uniform&) = delete;

private:
    Type type_;
    std::string name_;
    uint32_t uniform_;
};
