#include "vbo.h"

#include "glad/glad.h"
#include <GL/gl.h>

VBO::VBO(BindMode mode)
    : mode_(mode)
    , vbo_(0)
{
    glGenBuffers(1, &vbo_);
}

VBO::~VBO()
{
    glDeleteBuffers(1, &vbo_);
}

void VBO::SetData(void *data, uint32_t dataSize, UsageType usage)
{
    int32_t mode = _bindToGL(mode_);
    glBindBuffer(mode, vbo_);
    glBufferData(mode, dataSize, data, _usageToGL(usage));
}

void VBO::SetDataOffset(int offset, void *data, uint32_t dataSize)
{
    int32_t mode = _bindToGL(mode_);
    glBindBuffer(mode, vbo_);
    glBufferSubData(mode, offset, dataSize, data);
}

void *VBO::MapBuffer(MappingType type)
{
    int32_t mode = _bindToGL(mode_);
    glBindBuffer(mode, vbo_);
    return glMapBuffer(mode, _mappingToGL(type));
}

void VBO::UnmapBuffer()
{
    glUnmapBuffer(_bindToGL(mode_));
}

void VBO::Bind()
{
    glBindBuffer(_bindToGL(mode_), vbo_);
}

void VBO::Unbind()
{
    glBindBuffer(_bindToGL(mode_), 0);
}

int32_t VBO::_bindToGL(BindMode mode)
{
    switch (mode)
    {
        case ArrayBuffer:
        {
            return GL_ARRAY_BUFFER;
            break;
        }
        case ElementArrayBuffer:
        {
            return GL_ELEMENT_ARRAY_BUFFER;
            break;
        }
    }

    return 0;
}

int32_t VBO::_usageToGL(UsageType usage)
{
    int32_t usageEnum = 0;
    switch (usage)
    {
        case StaticDraw:
        {
            usageEnum = GL_STATIC_DRAW;
            break;
        }
        case StaticRead:
        {
            usageEnum = GL_STATIC_READ;
            break;
        }
        case DynamicDraw:
        {
            usageEnum = GL_DYNAMIC_DRAW;
            break;
        }
        case DynamicRead:
        {
            usageEnum = GL_DYNAMIC_READ;
            break;
        }
        case StreamDraw:
        {
            usageEnum = GL_STREAM_DRAW;
            break;
        }
        case StreamRead:
        {
            usageEnum = GL_STREAM_READ;
            break;
        }
    }

    return usageEnum;
}

int32_t VBO::_mappingToGL(MappingType type)
{
    switch (type)
    {
        case ReadOnly:
        {
            return GL_READ_ONLY;
            break;
        }
        case WriteOnly:
        {
            return GL_WRITE_ONLY;
            break;
        }
        case ReadWrite:
        {
            return GL_READ_WRITE;
            break;
        }
    }

    return 0;
}
