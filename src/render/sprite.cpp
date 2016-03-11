#include "sprite.h"

Sprite::Sprite()
    : Drawable(Drawable::Triangles)
{
    ;
}

void Sprite::SetTexture(uint32_t unit, const std::shared_ptr<Texture>& texture)
{
    auto state = GetOrCreateState();
    state->SetTexture(unit, texture);
}

void Sprite::SetRegion(const Rectangle& region)
{
    region_ = region;
}

void Sprite::SetSize(Vector2 size)
{
    size_ = size;
}
