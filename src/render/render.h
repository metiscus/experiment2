#pragma once

#include <memory>

class Window;

class Render
{
public:
    Render();
    ~Render();
    
    void SetWindow(std::shared_ptr<Window> window);
    std::shared_ptr<Window> GetWindow();
    
    
private:
    std::shared_ptr<Window> window_;
};
