#include "header.h"
#include <stdlib.h>
#include <time.h>



/**
* generate_dots - generate one dot on the board containing the value -1
* @game: p to struct
*
* Return: void
*/
void generate_dots(snake_t *game)
{

	int *board = game->board;
	int i = 0, j = 0;

	srand(time(NULL));

	for (int k = 1; k > 0 ; k++)
	{
		j = rand() % Nb_CELL_X;
		i = rand() % Nb_CELL_X;
		
		if (board[i * Nb_CELL_X + j] == 0)
		{
			board[i * Nb_CELL_X + j] = -1;
			return;
		}
	}

}
/**
* get_coodinate - get the row and the col of an val in the grid if found
* @game: p to struct
* @row: p to an integer
* @col: p to an integer
* @val: val to search
*
* Return: void
*/
void get_coodinate(snake_t *game, int *row, int *col, int val)
{
	int *board = game->board;

	for (int i = 0; i < Nb_CELL_X; i++)
	{
		for (int j = 0; j < Nb_CELL_X; j++)
		{
			if (board[i * Nb_CELL_X + j] == val)
			{
				*row = i;
				*col = j;
				return;
			}
		}
	}
}

/**
* check_wall - check_wall
* @row: head row
* @col: head col
* Return: void
*/
int check_wall(int row, int col)
{
	if ((row) == 12 || (col) == 12)
		return (0);
	else if ((row) < 0 || (col) < 0)
		return (0);
	else
		return (1);
}


/**
* search_for_tail - search_for_tail
* @game: p to struct
*
* Return: void
*/
int search_for_tail(snake_t *game)
{
	int tail = 1;
	int *board = game->board;

	for (int i = 0; i < Nb_CELL_X; i++)
	{
		for (int j = 0; j < Nb_CELL_X; j++)
		{
			if (board[i * Nb_CELL_X + j] >= 1)
			{
				if (board[i * Nb_CELL_X + j] > tail)
					tail = board[i * Nb_CELL_X + j];
			}
		}
	}
	return (tail);
}

/**
* modify_board - substract the tail of the snake form the core and update the
* core
* @game: p struct
*
* Return: void
*/
void modify_board(snake_t *game)
{
	int *board = game->board;
	int tail = 1;

	tail = search_for_tail(game);
	for (int i = 0; i < Nb_CELL_X; i++)
	{
		for (int j = 0; j < Nb_CELL_X; j++)
		{
			if (board[i * Nb_CELL_X + j] >= 1)
			{
				if (board[i * Nb_CELL_X + j] == tail)
					board[i * Nb_CELL_X + j] = 0;
				else
					board[i * Nb_CELL_X + j]++;
			}
		}
	}

}

/**
* modify_snake_length - update the core value by adding 1 to each dot
* @game: p to struct
*
* Return: void
*/
void modify_snake_length(snake_t *game)
{
	int *board = game->board;

	for (int i = 0; i < Nb_CELL_X; i++)
	{
		for (int j = 0; j < Nb_CELL_X; j++)
		{
			if (board[i * Nb_CELL_X + j] >= 1)
			{
				board[i * Nb_CELL_X + j]++;
			}
		}
	}
}


/**
* move_snake - add one dot to the front of the front of the snake if it eat
* food or just move the snake ( adding one dot to the  front and extracting the
* last dot (which is the greatest nb in the board ) )
* @game: p struct
* @row: row of the head
* @col: col of the head
* @direction: to move
*
* Return: void
*/
void move_snake(snake_t *game, int row, int col, int direction)
{
	int *board = game->board;

	switch (direction)
	{
		case Right:

			if (check_wall(row, col + 1))
			{
				if (board[row * Nb_CELL_X + col + 1] == -1)
				{
					modify_snake_length(game);
					board[row * Nb_CELL_X + col + 1] = 1;
					generate_dots(game);
				}
				else
				{
					modify_board(game);
					board[row * Nb_CELL_X + col + 1] = 1;
				}
			}
			else
			{
				printf("we hit a wall\n");
			}
			break;

		case Left:
			if (check_wall(row, col - 1))
			{
				if (board[row * Nb_CELL_X + col - 1] == -1)
				{
					modify_snake_length(game);
					board[row * Nb_CELL_X + col - 1] = 1;
					generate_dots(game);
				}
				else
				{
					modify_board(game);
					board[row * Nb_CELL_X + col - 1] = 1;
				}
			}
			else
			{
				printf("we hit a wall\n");
			}
			break;

		case Up:
			if (check_wall(row - 1, col))
			{
				if (board[(row - 1) * Nb_CELL_X + col] == -1)
				{
					modify_snake_length(game);
					board[(row - 1) * Nb_CELL_X + col] = 1;
					generate_dots(game);
				}
				else
				{
					modify_board(game);
					board[(row - 1) * Nb_CELL_X + col] = 1;
				}
			}
			else
			{
				printf("we hit a wall\n");
			}
			break;

		case Down:
			if (check_wall(row + 1, col))
			{
				if (board[(row + 1) * Nb_CELL_X + col] == -1)
				{
					modify_snake_length(game);
					board[(row + 1) * Nb_CELL_X + col] = 1;
					generate_dots(game);
				}
				else
				{
					modify_board(game);
					board[(row + 1) * Nb_CELL_X + col] = 1;
				}
			}
			else
			{
				printf("we hit a wall\n");
			}
			break;
	}
}

/**
* handle_logic - search for the coordinate of the head ( given manualy when
* initize the struct)
* @game:  to struct
* @direction: to move the snake
* Return: void
*/
void handle_logic(snake_t *game, int direction)
{
	int head_snake_row = 0, head_snake_col = 0;

	get_coodinate(game, &head_snake_row, &head_snake_col, 1); /* head snake */
	move_snake(game, head_snake_row, head_snake_col, direction);

}


/**
* logic_game -  handle_logic of the game
* @keyPressed: key the player press on
* @game: p to struct
* Return: void
*/
void logic_game(int keyPressed, snake_t *game)
{

	switch (keyPressed)
	{
		case SDLK_UP:
			if (1)
			{
				handle_logic(game, Up);
			}
			break;
		case SDLK_DOWN:
			if (1)
			{
				handle_logic(game, Down);
			}
			break;
		case SDLK_LEFT:
			if (1)
			{
				handle_logic(game, Left);
			}
			break;
		case SDLK_RIGHT:
			if (1)
			{
				handle_logic(game, Right);
			}
	}
}
