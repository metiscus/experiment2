#include "program.h"
#include "glad/glad.h"
#include <GL/gl.h>

#include "shader.h"
#include "uniform.h"

Program::Program()
    : program_(0)
{
    program_ = glCreateProgram();
}

Program::~Program()
{
    glDeleteProgram(program_);
}

void Program::AddShader(std::shared_ptr<Shader> ptr)
{
    shaders_.push_back(ptr);
}

void Program::AddUniform(std::shared_ptr<Uniform> uniform)
{
    uniforms_.push_back(uniform);
}

bool Program::Link()
{
    std::vector<std::shared_ptr<Shader>>::iterator itr;
    for (itr = shaders_.begin(); itr != shaders_.end(); ++itr)
    {
        glAttachShader(program_, (*itr)->GetGLObject());
    }

    glLinkProgram(program_);

    GLint program_ok;
    glGetProgramiv(program_, GL_LINK_STATUS, &program_ok);
    if (!program_ok)
    {
        GLint log_length;
        char *log;
        glGetProgramiv(program_, GL_INFO_LOG_LENGTH, &log_length);
        log = (char *)malloc(log_length);
        glGetProgramInfoLog(program_, log_length, NULL, log);
        // debug
        errors_ = log;
        free(log);
        return false;
    }

    // for each uniform attached, find it in the linked program
    for (unsigned int ii = 0; ii < uniforms_.size(); ++ii)
    {
        uniforms_[ii]->SetGLObject(glGetUniformLocation(program_, uniforms_[ii]->GetName().c_str()));
    }

    // DEBUG: we shouldn't keep these around, so let's free them.
    uniforms_.clear();
    shaders_.clear();

    return true;
}

void Program::Use()
{
    glUseProgram(program_);
}

const std::string Program::GetLinkErrors() const
{
    return errors_;
}
