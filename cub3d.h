/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:12:28 by imabid            #+#    #+#             */
/*   Updated: 2022/06/15 14:57:07 by imabid           ###   ########.fr       */
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
#define FOV 
#define TILE_SIZE 64
#define mapXX 16
#define mapYY 16
#define WIDTH 16 * 64
#define HEIGHT 16 * 64
#define rotspeeed DR  * 3
#define PI 3.1415926535
#define PI1 



typedef struct	s_player {
	int		dxx;
	int 	dyy;
	double	px;
	double ag;
	double py;
	double rotangle;
	double rotspeed;
	int movespeed;
	double width;
	double height;
	double tdirection;
	double rspeed;
	double movestep;
	double walkdirection;
	int 	to_a;
	int 	to_s;
	int		to_d;
	int 	to_w;
	int 	to_forward;
	int 	to_back;
	double fov;
	// double num_rays;
}				t_player;
typedef struct ray
{
	double fov;
	double rayangle;
	double num_rays;
	double wallhitx;
	double wallhity;
	double distance;
	double xstep;
	double ystep;
	double xintercept;
	double yintercept;
	int facingdown;
	int facingup;
	int facingright;
	int facingleft;
	double nexthox;
	double nexthoy;
	double foundhorwallhit;

} t_ray;
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
	t_ray	ray;
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
void    move_to(t_conf *conf);
int player_move(int key,void *param);
int keyrealeased(int key,t_conf *conf);
int    iam_wall(t_conf *conf);
void    rotate(t_conf *conf);
void    init_all2(t_conf *conf);
#endif