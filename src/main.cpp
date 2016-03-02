#include <cstdio>
#include <cstdint>
#include <SDL.h>

int main(int argc, char** argv)
{
    printf("Hello World!\n");

   	if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0) 
	{
    	fprintf(stderr, "\nUnable to initialize SDL:  %s\n", SDL_GetError());
        return 1;
    }
 
    return 0;
}
