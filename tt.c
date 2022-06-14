/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 08:58:22 by imabid            #+#    #+#             */
/*   Updated: 2022/06/07 10:43:00 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <graphics.h>
// #include <stdio.h>
// #include <math.h>
// #include <dos.h>
 
// void main( )
// {
// float x,y,x1,y1,x2,y2,dx,dy,step;
// int i,gd=DETECT,gm;
 
// initgraph(&gd,&gm,"c:\\turboc3\\bgi");
 
// printf("Enter the value of x1 and y1 : ");
// scanf("%f%f",&x1,&y1);
// printf("Enter the value of x2 and y2: ");
// scanf("%f%f",&x2,&y2);
 
// dx=abs(x2-x1);
// dy=abs(y2-y1);
 
// if(dx>=dy)
// step=dx;
// else
// step=dy;
 
// dx=dx/step;
// dy=dy/step;
 
// x=x1;
// y=y1;
 
// i=1;
// while(i<=step)
// {
// putpixel(x,y,5);
// x=x+dx;
// y=y+dy;
// i=i+1;
// delay(100);
// }
 
// closegraph();
// }

// typedef struct s_img {
// 	// t_data	img;
// 	// t_data	coin;
// 	// t_data	player;
// 	// t_data	player1;
// 	// t_data	exit;
// 	// t_data	exit1;
// 	// t_data	background;
// 	// t_data	enemy[3];
//     char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
//     void    *img;
// 	void	*mlx;
// 	void	*mlx_win;
// 	char	**map;
// 	int		count;
// }		t_img;
// int		create_trgb(int t, int r, int g, int b)
// {
// 	return(t << 24 | r << 16 | g << 8 | b);
// }
// int main()
// {
//     void *mlx_ptr;
//     // void *ptr;
    
//     t_img pink_cube;
//     pink_cube.ptr = mlx_new_image(mlx_ptr, 3, 3);

//     pink_cube.addr = mlx_get_data_addr(pink_cub.ptr, &img.bitsinpixel, &line_bytes, &img.endian);
//     int color = create_trgb(0, 255, 218, 233) = 0x00ffdae9;
//     int width;
//     int height = 0;
    
//     while (height < 3)
//     {
//     	width = 0;
//     	while (width < 3)
//     	{
//     		pink_cube.addr(height * 3 + width) = color;
//     		width++;
//     	}
//     	height++;
//     }
//     mlx_put_image_to_window(mlx_ptr, win_ptr, pink_cube.ptr, 0, 0); \\ These zeroes are the coordinates of the window in which you want to place the first pixel of our cute pink cube. Try changing its values to check different coordinates.
//     		mlx_loop(mlx);
// }

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "../mlx/mlx.h"

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_EXIT		17 //Exit program key code

#define KEY_ESC			53

# define TILE_SIZE 32
# define ROWS 11
# define COLS 15
# define WIDTH COLS * TILE_SIZE
# define HEIGHT ROWS * TILE_SIZE

# define TO_COORD(X, Y) ((int)floor(Y) * WIDTH + (int)floor(X))

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
}				t_img;

typedef struct	s_game
{
	void	*mlx;
	void	*win;
	t_img	img;

	int		map[ROWS][COLS];
}				t_game;

//Draw the line by DDA algorithm
void	draw_line(t_game *game, double x1, double y1, double x2, double y2)
{
	double	deltaX;
	double	deltaY;
	double	step;

	deltaX = x2 - x1;
	deltaY = y2 - y1;
	step = (fabs(deltaX) > fabs(deltaY)) ? fabs(deltaX) : fabs(deltaY);
	deltaX /= step;
	deltaY /= step;
	while (fabs(x2 - x1) > 0.01 || fabs(y2 - y1) > 0.01)
	{
		game->img.data[TO_COORD(x1, y1)] = 0xb3b3b3;
		x1 += deltaX;
		y1 += deltaY;
	}
}

void 	draw_lines(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < COLS)
	{
		draw_line(game, i * TILE_SIZE, 0, i * TILE_SIZE, HEIGHT);
		i++;
	}
	draw_line(game, COLS * TILE_SIZE - 1, 0, COLS * TILE_SIZE - 1, HEIGHT);
	j = 0;
	while (j < ROWS)
	{
		draw_line(game, 0, j * TILE_SIZE, WIDTH, j * TILE_SIZE);
		j++;
	}
	draw_line(game, 0, ROWS * TILE_SIZE - 1, WIDTH, ROWS * TILE_SIZE - 1);
}

void	draw_rectangle(t_game *game, int x, int y)
{
	int i;
	int j;

	x *= TILE_SIZE;
	y *= TILE_SIZE;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			game->img.data[(y  + i) * WIDTH + x + j] = 0xFFFFFF;
			j++;
		}
		i++;
	}
}

void	draw_rectangles(t_game *game)
{
	int		i;
	int		j;

	i = 0;
	while (i < ROWS)
	{
		j = 0;
		while (j < COLS)
		{
			if (game->map[i][j] == 1)
				draw_rectangle(game, j, i);
			j++;
		}
		i++;
	}
}

int		deal_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		exit(0);
	return (0);
}

int 	close(t_game *game)
{
		exit(0);
}

void	game_init(t_game *game)
{	
	int map[ROWS][COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};
	memcpy(game->map, map, sizeof(int) * ROWS * COLS);
}

void	window_init(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "mlx 42");
}

void	img_init(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp, &game->img.size_l, &game->img.endian);
}

int		main_loop(t_game *game)
{

	draw_rectangles(game);
	draw_lines(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}

int		main(void)
{
	t_game game;

	game_init(&game);
	window_init(&game);
	img_init(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &close, &game);

	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
}