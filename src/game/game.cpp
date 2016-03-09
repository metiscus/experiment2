#include <core/math.h>
#include <render/window.h>

int main(int argc, char** argv)
{
    WindowPtr window = std::make_shared<Window>("Test", 800, 600);
    window->MakeCurrent();
    
    glClearColor(0.1, 0.2, 0.2, 0.4);
    while(true)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        window->SwapBuffers();
    }
    return 0;
}
