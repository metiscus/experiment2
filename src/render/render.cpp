#include "render.h"

Render::Render()
{
    
}

Render::~Render()
{
    
}

void Render::SetWindow(std::shared_ptr<Window> window)
{
    window_ = window;
}

std::shared_ptr<Window> Render::GetWindow()
{
    return window_;
}
