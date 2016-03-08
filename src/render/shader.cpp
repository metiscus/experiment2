#include "shader.h"
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <string>

#include "glad/glad.h"
#include <GL/gl.h>

Shader::Shader(Type type)
    : shader_(0)
{
    switch (type)
    {
        case Vertex:
        {
            shader_ = glCreateShader(GL_VERTEX_SHADER);
            break;
        }
        case Fragment:
        {
            shader_ = glCreateShader(GL_FRAGMENT_SHADER);
            break;
        }
        case Geometry:
        {
            shader_ = glCreateShader(GL_GEOMETRY_SHADER);
            break;
        }
        default:
        {
            assert(false);
        }
    }
}

Shader::~Shader()
{
    text_ = "";
    glDeleteShader(shader_);
}

void Shader::LoadFile(const char *filename)
{
    std::string line;
    std::ifstream infile(filename);

    while (infile.is_open() && !infile.eof())
    {
        std::getline(infile, line);
        text_ += line + "\n";
    }
    infile.close();
}

void Shader::SetText(const char *text)
{
    text_ = text;
}

bool Shader::Compile()
{
    bool ret = true;
    char *shaderSource = strdup(text_.c_str());
    glShaderSource(shader_, 1, (const GLchar**)&shaderSource, NULL);
    glCompileShader(shader_);

    GLint shader_ok;
    glGetShaderiv(shader_, GL_COMPILE_STATUS, &shader_ok);
    if (!shader_ok)
    {
        GLint log_length;
        char *log;
        glGetShaderiv(shader_, GL_INFO_LOG_LENGTH, &log_length);
        log = (char *)malloc(log_length);
        glGetShaderInfoLog(shader_, log_length, NULL, log);
        // debug
        errors_ = log;
        fprintf(stderr, "%s", log);
        free(log);

        ret = false;
    }
    free(shaderSource);

    return ret;
}

unsigned int Shader::GetGLObject()
{
    return shader_;
}

const std::string &Shader::GetCompileErrors() const
{
    return errors_;
}
