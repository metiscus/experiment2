#pragma once

#include <cstdint>

class Sampler
{
public:
    Sampler();
    ~Sampler();
    
    Sampler(Sampler&) = delete;
    Sampler& operator=(Sampler&) = delete;
    
    void Bind(int unit);

    uint32_t GetGLObject() const;

private:
    uint32_t unit_;
    uint32_t sampler_;
};
