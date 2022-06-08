/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:11:34 by imabid            #+#    #+#             */
/*   Updated: 2022/06/08 15:12:51 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void    print_rectangl(t_conf *conf,int x,int y,int color,int line)
{
    int i;
    int j;

    x *= TILE_SIZE;
    y *= TILE_SIZE;
    i = 0;
    while(i < TILE_SIZE - line)
    {
        j = 0;
        while (j < TILE_SIZE - line)
        {
            conf->img.addr[(x + i) * WIDTH + y + j] = color;
            j++;
        }
        i++;
    }
}

// int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;

// void line_1(t_conf *recup, float x1, float y1, float x2, float y2, int color)
// {
//     if (dx >= 0)
//     {
//         x = x1;
//         y = y1;
//         xe = x2;
//     }
//     else
//     {
//         x = x2;
//         y = y2;
//         xe = x1;
//     }
//     recup->img.addr[(int)(x * WIDTH + y)] = color;
//     while (x < xe)
//     {
//         x = x + 1;
//         if (px < 0)
//         {
//             px = px + 2 * dy1;
//         }
//         else
//         {
//             if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
//             {
//                 y = y + 1;
//             }
//             else
//             {
//                 y = y - 1;
//             }
//             px = px + 2 * (dy1 - dx1);
//         }
//         recup->img.addr[(int)(x * WIDTH + y)] = color;
//     }
// }

// void line_2(t_conf *recup, float x1, float y1, float x2, float y2, int color)
// {

//     if (dy >= 0)
//     {
//         x = x1;
//         y = y1;
//         ye = y2;
//     }
//     else
//     {
//         x = x2;
//         y = y2;
//         ye = y1;
//     }
//     recup->img.addr[(int)(x * WIDTH + y)] = color;
//     while (y < ye)
//     {
//         y = y + 1;
//         if (py <= 0)
//         {
//             py = py + 2 * dx1;
//         }
//         else
//         {
//             if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
//             {
//                 x = x + 1;
//             }
//             else
//             {
//                 x = x - 1;
//             }
//             py = py + 2 * (dx1 - dy1);
//         }
//         recup->img.addr[(int)(x * WIDTH + y)] = color;
//     }
// }

// void line(t_conf *recup, float x1, float y1, float x2, float y2, int color)
// {

//     dx = x2 - x1;
//     dy = y2 - y1;

//     i = 0;
//     dx1 = abs(dx);
//     dy1 = abs(dy);

//     px = 2 * dy1 - dx1;
//     py = 2 * dx1 - dy1;

//     if (dy1 <= dx1)
//     {
//         line_1(recup, x1, y1, x2, y2, color);
//     }
//     else
//     {
//         line_2(recup, x1, y1, x2, y2, color);
//     }
// }

float playerX = 100; float playerY = 100;
int mapX= 16,mapY = 16,mapS =64;

char map[16][16]=
{
    // {1,1,1,1,1,1,1,1},
    // {1,0,1,0,0,0,0,1},
    // {1,0,1,0,0,0,0,1},
    // {1,0,1,1,1,1,0,1},
    // {1,0,0,0,0,0,0,1},
    // {1,0,0,1,1,1,0,1},
    // {1,0,0,0,0,0,0,1},
    // {1,1,1,1,1,1,1,1},
    {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','1','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','1','0','1','1','1','1','1','0','0','0','0','1'},
    {'1','0','0','0','1','1','1','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','1','0','0','0','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','1','1','0','1','1','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','1','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','1','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','S','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
    {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
};
// int mapX= 8,mapY = 8,mapS =64;
// int map[8][8]= 
// {
//     {1,1,1,1,1,1,1,1},
//     {1,0,1,0,0,0,0,1},
//     {1,0,1,0,0,0,0,1},
//     {1,0,1,1,1,1,0,1},
//     {1,0,0,0,0,0,0,1},
//     {1,0,0,1,1,1,0,1},
//     {1,0,0,0,0,0,0,1},
//     {1,1,1,1,1,1,1,1},
    
// };

void    ft_get_playerPosition(t_player *player)
{
    int i = 0;
    int j;
    while (i < mapX)
    {
        j = 0;
        while (j < mapY)
        {
            if (map[i][j] == 'S')
            {
                player->dx = i;
                puts("here"); 
                player->dy = j;
                return;
            }
            j++;
        }
        i++;
    }
}
// void    init_all(t_conf *conf)
// {
//     ft_get_playerPosition(&conf->player);
//     conf->player.py = conf->player.dy * 64 + 64 / 2;
//     conf->player.px = conf->player.dx * 64 + 64 / 2 ;
//     conf->player.rotangle = PI / 2;
//     conf->player.movespeed = 5;
//     conf->player.rotspeed = 5 * (PI / 180);
// }
// void    ft_clear(t_conf *conf)
// {
//     int i =0, j = 0;
//     while(i < mapX )
//     {
//         j = 0;
//         while(j < mapY)
//         {
//             print_rectangl(conf,i,j,BLACK,0);  
//             j++;
//         }
//         i++;
//     }
// }
// void    player_print(t_conf *conf)
// {
//     int r = 5; 
//     int i = 0;
//     int j = 0;
//     double x = conf->player.px;
//     double y = conf->player.py;
//     i = -r;
//     line(conf,conf->player.py,
// 	conf->player.px,
// 	(conf->player.py + (60 * cos(conf->player.rotangle))) ,
// 	(conf->player.px + (60 * sin(conf->player.rotangle))), C2);
//     while (i < r)
//     {
//         j = -r;
//         while (j < r)
//         {
//             if ((i * i) + (j * j) <= (r * r))
//             {
//                 conf->img.addr[(int)((i + y)) *
//                 (WIDTH) + (int)((j + x))] = C1;
//             }
//             j++;
//         }
//         i++;
//     }
// }
int	close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
int player_move(int key,void *param)
{
    t_conf *conf;
    conf = (t_conf *)param;
    // puts("here");
    printf("%d\n",key);
    if(key == ESC)
        exit(0);
    else if (key == W)
		conf->player.py -=VITESS;
	else if (key == D)
		conf->player.px+= VITESS;
	else if (key == S)
		conf->player.py += VITESS;
	else if (key == A)
		conf->player.px -= VITESS;
    else if(key == 123)
        conf->player.rotangle += cos(0) * conf->player.rotspeed;
    else if(key == 125)
        conf->player.rotangle += sin(0) * conf->player.rotspeed;
    printf("%d\n",key);
    // else if  
    // printf("PlayerX = %f player Y = %f",conf->player->px,conf->player->py);
	// mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->player.img, conf->player.px, conf->player->py);
    return 0;
}

void    mapp_print(t_conf *conf)
{
    int i;
    int j;

    i = 0;
    
    while(i < mapX )
    {
        j = 0;
        while(j < mapY)
        {
                print_rectangl(conf,i,j,GRAY,1);  
            j++;
        }
        i++;
    }
    i = 0;
    while(i < mapX )
    {
        j = 0;
        while(j < mapY)
        {
            if(map[i][j] == '0'|| map[i][j] == 'S')
                print_rectangl(conf,i,j,WHITE,1);  
            j++;
        }
        i++;
    }
}

int main_loop(t_conf *conf)
{
    ft_clear(conf);
    mapp_print(conf);
    player_print(conf);
    mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->img.img, 0, 0);
    return 0;
}
void    cub3d_hook(t_conf *conf)
{
    mlx_clear_window(conf->mlx, conf->mlx_win);
    ft_clear(conf);
    mlx_hook(conf->mlx_win, 2, 1L << 0, player_move, conf);
    mlx_hook(conf->mlx_win, 17, 0, close_win, conf);
    mlx_loop_hook(conf->mlx,&main_loop, conf);
}
int	main(void)
{
	// t_player	img;
    t_conf conf;
    win_init(&conf);
    img_init(&conf);
    init_all(&conf);
    cub3d_hook(&conf);
	mlx_loop(conf.mlx);
    return 0;
}


