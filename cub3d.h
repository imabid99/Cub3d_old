/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:12:28 by imabid            #+#    #+#             */
/*   Updated: 2022/07/26 15:39:51 by imabid           ###   ########.fr       */
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
# define AQUA 0x00bda5
# define AQUA1 0x007667
# define GRAY 0x808080
# define GRAY1 0x302D2C
# define GRAY2 0xa4a4a5
# define TEX_WIDTH 64
# define TEX_HEIGHT 64


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
#define WIDTH 1800
#define HEIGHT 1000
#define rotspeeed DR  * 3
#define PI 3.1415926535
#define two_PI 6.28318530 
#define minimap 0.1
#define FOV (60 * (M_PI / 180)) 
#define movesped 8



typedef struct	s_player {
	int		dxx;
	int 	dyy;
	double	px;
	double ag;
	double py;
	double rotangle;
	double turnspeed;
	int movespeed;
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
	int		to_space;
	double fov;
	int width;
	int height;
}				t_player;
typedef struct ray
{
	double fov;
	double *rayangle;
	double num_rays;
	double horwallhitx;
	double horwallhity;
	double verwallhitx;
	double verwallhity;
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
	double nextverx;
	double nextvery;
	double xhortocheck;
	double yhortocheck;
	double xvertocheck;
	double yvertocheck;
	double foundhorwallhit;
	double foundverwallhit;
	double verdist;
	double hordist;
	double wallhitX;
	double wallhitY;
	int  verwallcontent;
	int  horwallcontent;
	int wallcon;
	double washitvert;
} t_ray;
typedef struct s_wall
{
	double wallstripheight;
	double distancepro;
	double playerWallDist;
	int drawStartx;
	int drawStarty;
	double *line_distance;
	double corrwall;
	int topwall;
	int bottomwall;
	int *hitver;
	double *wX;
	double *wY;
	double *faceup;
	double *facedown;
	double *faceright;
	double *faceleft;
	int *con;
	int a;

} t_wall;
typedef struct s_img
{
	void *img;
	int	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;
typedef struct s_texture
{
	void	*img;   
	int		*addr;
	int 	bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	float		x;
	float		y;
}	t_texture;

typedef struct s_elements
{
	char		*identifier;
	char		*path;
	t_texture	texture;
}	t_elements;
typedef struct s_conf {
	void	*mlx;
	void	*mlx_win; 
	char	**map;
	int		count;
		int txtnbr;
	// void	*img1;
	// int		*addr;
	t_player	player;
	t_elements	*elem;
	t_img	img;
	t_ray	ray;
	t_wall wall;
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
void print_rectangl1(t_conf *conf, int y, int x, int color, int line);
void    init_all2(t_conf *conf);
t_texture	load_img(char *path, void *mlx);
#endif