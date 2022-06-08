/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:12:28 by imabid            #+#    #+#             */
/*   Updated: 2022/06/08 15:16:23 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_3D
#define CUB_3D

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
#include <math.h>
# define C2 0xC34A6A
# define C1 0x7AE2B3
# define WHITE 0xffffff
# define BLACK 0x000000
# define GRAY 0x808080
# define ESC 53
# define W 13
# define VITESS 8
# define A 0
# define S 1
# define D 2
#define ang 3.14
#define rotationAngle = ang / 2;
#define DR (1 * (M_PI / 180))
#define TILE_SIZE 64
#define mapXX 16
#define mapYY 16
#define WIDTH 16 * 64
#define HEIGHT mapYY * TILE_SIZE
#define rotspeeed DR  * 3
#define PI 3.1415926535



typedef struct	s_player {
	int		dx;
	int 	dy;
	double	px;
	double ag;
	double py;
	double rotangle;
	double rotspeed;
	double movespeed;
	double width;
	double height;
}				t_player;
typedef struct	s_line {
	int		dx;
	int 	dy;
	double	px;
	double ag;
	double py;
	double rotangle;
	double rotspeed;
	double movespeed;
	
}				t_line;
typedef struct s_img
{
	void *img;
	int	*addr;

	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_conf {
	void	*mlx;
	void	*mlx_win; 
	char	**map;
	int		count;
	t_player	player;
	t_img	img;
}		t_conf;


void    ft_clear(t_conf *conf);
void    player_print(t_conf *conf);
void    win_init(t_conf *conf);
void    init_all(t_conf *conf);
void    img_init(t_conf *conf);
void    print_rectangl(t_conf *conf,int x,int y,int color,int line);
void line(t_conf *recup, float x1, float y1, float x2, float y2, int color);
void    ft_get_playerPosition(t_player *player);
void line_1(t_conf *conf, float x1, float y1, float x2, float y2, int color);
void line_2(t_conf *conf, float x1, float y1, float x2, float y2, int color);
#endif