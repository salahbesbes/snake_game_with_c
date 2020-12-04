#include "header.h"
#include <SDL2/SDL_render.h>



/**
* X - 
* @a: 
*
* Return:
*/

int init(SDL_Window **win, SDL_Renderer **win_renderer)
{
	bol success = true;

	//Initialize SDL
	if( SDL_Init(SDL_INIT_EVERYTHING) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window 
		*win = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				_Width, _Height,
				0);
		if (*win == NULL)
		{
			printf( "Window could not be created! SDL_Error: %s\n",
					SDL_GetError() );
			success = false;
		}
		else
		{
			// Create a renderer for window
			*win_renderer = SDL_CreateRenderer(*win, -1,
					SDL_RENDERER_ACCELERATED |
					SDL_RENDERER_PRESENTVSYNC);
			if (!win_renderer)
			{
				fprintf(stderr, "cant init renderer : %s\n",
						SDL_GetError());
				success = false;
			}
			else
			{
				//initialize renderer color
				SDL_SetRenderDrawColor(*win_renderer,
						0xFF, 0xFF, 0xFF, 0xFF);

			}
		}
	}
	return (success);
}

	
void closeee(SDL_Window *window, SDL_Surface *Image,
		SDL_Surface *screenSurface, SDL_Renderer *win_render)
{

	//Deallocate surface

	SDL_FreeSurface(Image);
	Image = NULL;

	SDL_FreeSurface(screenSurface);
	screenSurface = NULL;
	//Destroy window

	SDL_DestroyWindow(window);
	window = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}
