/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:11:34 by imabid            #+#    #+#             */
/*   Updated: 2022/06/14 11:57:34 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void print_rectangl(t_conf *conf, int y, int x, int color, int line)
{
    int i;
    int j;

    x *= TILE_SIZE;
    y *= TILE_SIZE;
    i = 0;
    while (i < TILE_SIZE - line)
    {
        j = 0;
        while (j < TILE_SIZE - line)
        {
            conf->img.addr[(y + j) * WIDTH + x + i] = color;
            j++;
        }
        i++;
    }
}

float playerX = 100;
float playerY = 100;
int mapX = 16, mapY = 16, mapS = 64;

char map[16][16] =
    {
        // {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        // {'0', '0', '0', '0', '0', '0', '0', '1', '1'},
        // {'0', '0', '0', 'S', '0', '0', '0', '1', '1'},
        // {'1', '0', '0', '1', '1', '1', '1', '1', '1'},
        // {'1', '0', '0', '0', '0', '0', '0', '1', '1'},
        // {'1', '0', '0', '0', '0', '0', '0', '1', '1'},
        // {'1', '0', '0', '0', '0', '0', '0', '1', '1'},
        // {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        // {1,1,1,1,1,1,1,1,1},
        // {1,0,0,0,0,0,0,1,1},
        // {0,0,0,2,0,0,0,1,1},
        // {1,0,0,1,1,1,1,1,1},
        // {1,0,0,0,0,0,0,1,1},
        // {1,0,0,0,0,0,0,1,1},
        // {1,0,0,0,0,0,0,1,1},
        // {1,1,1,1,1,1,1,1,1},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','S','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','1','1','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','1','1','1','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
};

double	normalize_ang(double angle)
{
	if (angle < 0)
		angle = (2 * PI) + angle;
	return (angle);
}
void move_to(t_conf *conf)
{
    
    float pdx = cos(conf->player.rotangle - PI / 2);
    float pdy = -sin(conf->player.rotangle - PI / 2);
    if (conf->player.to_a == 1)
    {
        if(map[(int)((conf->player.py - (sin(conf->player.rotangle + PI / 2) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (cos(conf->player.rotangle + PI / 2) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
        // conf->player.px += cos(conf->player.rotangle) * conf->player.movespeed;
        // conf->player.py -= sin(conf->player.rotangle) * conf->player.movespeed;   
        conf->player.px += cos(conf->player.rotangle + PI / 2) * conf->player.movespeed;
        conf->player.py -= sin(conf->player.rotangle + PI / 2) * conf->player.movespeed;
        }
    }
    if (conf->player.to_d == 1)
    {
        if(map[(int)((conf->player.py + (pdy * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (pdx * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
        // conf->player.px -= cos(conf->player.rotangle) * conf->player.movespeed;
        // conf->player.py += sin(conf->player.rotangle) * conf->player.movespeed;
        conf->player.px += pdx * conf->player.movespeed;
        conf->player.py += pdy * conf->player.movespeed;
            
        }
    }
    if (conf->player.to_w == 1)
    {
        if (map[(int)((conf->player.py - (sin(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (cos(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
            // conf->player.px += pdx * conf->player.movespeed;
            // conf->player.py += pdy * conf->player.movespeed;
            conf->player.px += cos(conf->player.rotangle) * conf->player.movespeed;
            conf->player.py -= sin(conf->player.rotangle) * conf->player.movespeed; 
            printf("x position: %f, y position: %f,map = %c\n", conf->player.px / 64, conf->player.py / 64,
                   map[(int)((conf->player.py / 64))][(int)((conf->player.px / 64))]);
        }
    }
    if (conf->player.to_s == 1)
    {
        if(map[(int)((conf->player.py + (sin(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - (cos(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
        // conf->player.px += cos(conf->player.rotangle + PI / 2) * conf->player.movespeed;
        // conf->player.py -= sin(conf->player.rotangle + PI / 2) * conf->player.movespeed;
        conf->player.px -= cos(conf->player.rotangle) * conf->player.movespeed;
        conf->player.py += sin(conf->player.rotangle) * conf->player.movespeed;
            
        }
    }
    // conf->player.rotangle = normalize_ang(conf->player.rotangle);
    // if (conf->player.to_forward == 1)
    //     conf->player.rotangle += conf->player.rotspeed;
    // if (conf->player.to_back == 1)
    //     conf->player.rotangle -= conf->player.rotspeed;
}
void    rotate(t_conf *conf)
{
    conf->player.rotangle = normalize_ang(conf->player.rotangle);
    if (conf->player.to_forward == 1)
        conf->player.rotangle += conf->player.rotspeed;
    if (conf->player.to_back == 1)
        conf->player.rotangle -= conf->player.rotspeed;
}

void cast_rays(t_conf *conf)
{
    int columnbr = 0;
    conf->ray.rayangle = conf->player.rotangle - (conf->ray.fov / 2);
    int i = 0;
    while(i < conf->ray.num_rays)
    {
        conf->ray.rayangle = normalize_ang(conf->ray.rayangle);
           line(conf,conf->player.py,
	    conf->player.px,
	    (conf->player.py + (200 * -sin((conf->ray.rayangle)))) ,
	    (conf->player.px + (200 * cos((conf->ray.rayangle)))), C1);
        conf->ray.rayangle += conf->ray.fov /conf->ray.num_rays;
        i++;
    }
}
void ft_get_playerPosition(t_player *player)
{
    int i = 0;
    int j;
    while (i < mapY)
    {
        j = 0;
        while (j < mapX)
        {
            if (map[i][j] == 'S')
            {
                player->dxx = j;
                player->dyy = i;
                printf("%d,%d \n", map[player->dxx][player->dyy]);
                return;
            }
            j++;
        }
        i++;
    }
}
int close_win(void)
{
    exit(EXIT_SUCCESS);
}

void mapp_print(t_conf *conf)
{
    int i;
    int j;

    i = 0;

    // while (i < mapY) // = 0
    // {
    //     j = 0;
    //     while (j < mapX) // = 1
    //     {
    //         puts("hello");

    //         conf->img.addr[(i) * WIDTH + (j)] = GRAY;
    //         j++;
    //     }
    //     i++;
    // }

    while(i < mapY)
    {
        j = 0;
        while(j < mapX)
        {
            // printf("%c",map[i][j]);
            if(map[i][j] == '1')
                print_rectangl(conf,i,j,GRAY,1);
            else if(map[i][j] == '0' || map[i][j] == 'S')
                print_rectangl(conf,i,j,WHITE,1);
            j++;
        }
        // printf("\n");
        i++;
    }
    // i = 0;
    // while(i < mapX )
    // {
    //     j = 0;
    //     while(j < mapY)
    //     {
    //         if(map[i][j] == '0' || map[i][j] == 'S')
    //             print_rectangl(conf,i,j,WHITE,1);
    //         j++;
    //     }
    //     i++;
    // }
}

int main_loop(t_conf *conf)
{
    ft_clear(conf);
    mapp_print(conf);
    cast_rays(conf);
    player_print(conf);
    move_to(conf);
    rotate(conf);
    mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->img.img, 0, 0);
    return 0;
}
void cub3d_hook(t_conf *conf)
{
    mlx_clear_window(conf->mlx, conf->mlx_win);
    // ft_clear(conf);
    mlx_hook(conf->mlx_win, 2, 1L << 0, player_move, conf);
    mlx_hook(conf->mlx_win, 17, 0, close_win, conf);
    mlx_hook(conf->mlx_win, 3, 1L << 1, keyrealeased, conf);
    mlx_loop_hook(conf->mlx, &main_loop, conf);
    mlx_loop(conf->mlx);
}
int main(void)
{
    t_conf conf;
    win_init(&conf);
    img_init(&conf);
    // int i = 0;
    // int j = 0;
    // printf("map[0] %c\n",map[5][3]);
    init_all(&conf);
    cub3d_hook(&conf);
    mlx_loop(conf.mlx);
    return 0;
}
