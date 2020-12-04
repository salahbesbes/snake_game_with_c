#include "header.h"
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <stdlib.h>
#include <time.h>

/**
* render_grid - render grid
* @render: renderer
*
* Return: void
*/
void render_grid(SDL_Renderer *render)
{

	SDL_SetRenderDrawColor(render, 50, 80, 90, 255);

	for (int i = 1; i < Nb_CELL_X; i++)
	{
		SDL_RenderDrawLine(render, 0, CELL_W * i, _Width, CELL_W * i);
		SDL_RenderDrawLine(render, CELL_W * i, 0, CELL_W * i, _Height);
	}
}

/**
 * render_snake - render a red Rect
 * @renderer: sdl renderer
 * @row: row
 * @col: column
 *
 * Return: void
 */
void render_snake(SDL_Renderer *renderer, int row, int col)
{
	SDL_Rect newRec = {CELL_W * col, CELL_W * row, CELL_W, CELL_W };

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &newRec);
}


/**
 * render_food - render a blue Rect
 * @renderer: sdl renderer
 * @row: row
 * @col: column
 *
 * Return: void
 */
void render_food(SDL_Renderer *renderer, int row, int col)
{
	SDL_Rect newRec = {CELL_W * col, CELL_W * row, CELL_W, CELL_W };

	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderFillRect(renderer, &newRec);
}

/**
 * handle_render - loop thrwo all the board if found -1 rendre blue Rect (food)
 * if found > 0 render red Rect (core of the snake )
 * @win_Rendered: sdl renderer
 * @game: p to struct
 *
 * Return: void
 */

void handle_render(SDL_Renderer *win_Rendered, snake_t *game)
{
	render_grid(win_Rendered);
	int *board = game->board;

	for (int i = 0; i < Nb_CELL_X; i++)
	{
		for (int j = 0; j < Nb_CELL_X; j++)
		{
			if (board[i * Nb_CELL_X + j] > 0)
			{
				render_snake(win_Rendered, i, j);
			}
			else if (board[i * Nb_CELL_X + j] < 0)
			{
				render_food(win_Rendered, i, j);
			}
		}
	}
}
