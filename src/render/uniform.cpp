#include "uniform.h"
#include "glad/glad.h"
#include <GL/gl.h>

Uniform::Uniform(Type type, const char *name)
    : type_(type)
    , name_(name)
    , uniform_(-1)
{
    ;
}

Uniform::~Uniform()
{
}

void Uniform::Set(int x)
{
    glUniform1i(uniform_, x);
}

void Uniform::Set(const Vector2& v)
{
    glUniform2f(uniform_, v.x, v.y);
}

void Uniform::Set(const Vector3& v)
{
    glUniform3f(uniform_, v.x, v.y, v.z);
}

void Uniform::Set(const Vector4& v)
{
    glUniform4f(uniform_, v.x, v.y, v.z, v.w);
}

void Uniform::Set(const Matrix3& m)
{
    glUniformMatrix3fv(uniform_, 1, GL_FALSE, glm::value_ptr(m));
}

void Uniform::Set(const Matrix4& m)
{
    glUniformMatrix4fv(uniform_, 1, GL_FALSE, glm::value_ptr(m));
}

void Uniform::SetGLObject(uint32_t obj)
{
    uniform_ = obj;
}

const std::string& Uniform::GetName() const
{
    return name_;
}
