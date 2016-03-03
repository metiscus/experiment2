#include <cstdio>
#include <cstdint>
#include "window.h"
#include <SDL.h>

int main(int argc, char** argv)
{
    printf("Hello World!\n");

    Window::SetOpenGLHint(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    Window::SetOpenGLHint(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    Window::SetOpenGLHint(SDL_GL_DOUBLEBUFFER, 1);
    std::unique_ptr<Window> window(new Window("", 640, 480));
    
 
    SDL_Delay(100000);
    return 0;
}
