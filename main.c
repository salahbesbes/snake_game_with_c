#include "header.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_video.h>
#include <stdlib.h>

/**
 * init_snake - initialize the struct => filling the board with 0
 * @game: p to struct
 *
 * Return: void
 */
void init_snake(snake_t *game)
{

	int *board = game->board;

	game->dots = 1;
	for (int i = 0; i < Nb_CELL_Y; i++)
	{
		for (int j = 0; j < Nb_CELL_X; j++)
		{
			board[i * Nb_CELL_Y + j] = 0;
		}
	}
	board[20] = -1;
	board[24] = 1;
}

/**
 * main - desc
 * @argc: nb of args
 * @argv: array of strings
 *
 * Return: 0
 * Error: -1
 */
int main(int argc, char *argv[])
{

	SDL_Window *window = NULL;
	SDL_Renderer *win_Rendered = NULL;
	SDL_Event e;
	bol success = true;
	bol stop = false;
	snake_t game;

	success = init(&window, &win_Rendered);
	if (!success)
		fprintf(stderr, "cant init()\n");
	else
	{
		init_snake(&game);

		while (!stop)
		{
			while (SDL_PollEvent(&e))
			{
				switch (e.type)
				{
				case SDL_QUIT:
					stop = true;
					break;
				case SDL_KEYDOWN:
					logic_game(e.key.keysym.sym, &game);
					break;
				}
			}

			SDL_SetRenderDrawColor(win_Rendered, 255, 255, 255, 255);
			SDL_RenderClear(win_Rendered);
			handle_render(win_Rendered, &game);
			SDL_RenderPresent(win_Rendered);
		}
	}
	return (0);
}
