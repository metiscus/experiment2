#pragma once

#include <core/math.h>
#include <core/rectangle.h>
#include "drawable.h"
#include <memory>

class Sprite : public Drawable
{
public:
    Sprite();

    void SetTexture(uint32_t unit, const std::shared_ptr<Texture>& texture);
    void SetRegion(const Rectangle& region);
    void SetSize(Vector2 size);

private:
    Vector2 size_;
    Rectangle region_;
};
