#ifndef HEADER
#define HEADER


#define Up 1
#define Down 2
#define Right 3
#define Left 4


#define _Width 600
#define _Height 600
#define CELL_W 50
#define true 1
#define false 0
#define Nb_CELL_X (_Width / CELL_W)
#define Nb_CELL_Y (_Height / CELL_W)
typedef int bol;

#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_test_images.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_render.h>


typedef struct snake_t
{
	int board[Nb_CELL_X * Nb_CELL_Y];
	int dots;
} snake_t;

int init(SDL_Window **win, SDL_Renderer **win_renderer);
void handle_render(SDL_Renderer * win_Rendered, snake_t *game);
void logic_game(int keyPressed, snake_t *game);
#endif
