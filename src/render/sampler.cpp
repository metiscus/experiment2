#include "sampler.h"
#include "glad/glad.h"
#include <GL/gl.h>

Sampler::Sampler()
    : sampler_(0)
{
    glGenSamplers(1, &sampler_);
    glSamplerParameteri(sampler_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glSamplerParameteri(sampler_, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glSamplerParameteri(sampler_, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
}

Sampler::~Sampler()
{
    glDeleteSamplers(1, &sampler_);
}

void Sampler::Bind(int unit)
{
    glBindSampler(unit, sampler_);
    unit_ = unit;
}

uint32_t Sampler::GetGLObject() const
{
    return sampler_;
}
