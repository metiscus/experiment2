#include "state.h"

#include "glad/glad.h"
#include <GL/gl.h>

#include "texture.h"
#include "program.h"

State::State()
    : program_(0)
    , texture_enabled_(false)
    , blend_enabled_(false)
{
    ;
}

bool State::operator==(const State& rhs) const
{
    
}

void State::SetTexture(uint32_t unit, std::shared_ptr<Texture> texture)
{
    auto itr = textures_.find(unit);
    if(itr != textures_.end())
    {
        textures_.insert(std::make_pair(unit, texture));
    }
    else
    {
        textures_.at(unit) = texture;
    }
}

void State::SetProgram(std::shared_ptr<Program> program)
{
    program_ = program;
}

void State::EnableBlending()
{
    blend_enabled_ = true;
}

void State::DisableBlending()
{
    blend_enabled_ = false;
}

void State::EnableTexturing()
{
    texture_enabled_ = true;
}

void State::DisableTexturing()
{
    texture_enabled_ = false;
}

void State::EnableTextureUnit(uint32_t unit)
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glEnable(GL_TEXTURE_2D);
}

void State::DisableTextureUnit(uint32_t unit)
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glDisable(GL_TEXTURE_2D);
}
