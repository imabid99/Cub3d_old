/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:50:52 by imabid            #+#    #+#             */
/*   Updated: 2022/06/22 19:26:56 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    iam_wall(t_conf *conf)
// {
//     float x;
//     float y;
//     x = conf->player.px / 64;
//     y = conf->player.py / 64;
//     if(map[x][y] == 0)
//         return 1;
//     else 
//         return 0;
//     // return map[x][y] != 0 ;
// }
int player_move(int key,void *param)
{
    t_conf *conf;
    conf = (t_conf *)param;
    // puts("here");
    // printf("%d\n",key);
    if(key == ESC)
        exit(0);
    else if (key == W)
        conf->player.to_w = 1;
	else if (key == D)
        conf->player.to_d = 1;
	else if (key == S)
        conf->player.to_s = 1;
	else if (key == A)
        conf->player.to_a = 1;
    else if(key == 123)
        // conf->player.rotangle +=  conf->player.rotspeed;
        conf->player.to_forward = 1;
    else if(key == 124)
        conf->player.to_back = 1;
    // rotate(conf);
    // move_to(conf);
        // conf->player.rotangle -= conf->player.rotspeed;
    // printf("%d\n",key);
    // else if  
    // printf("PlayerX = %f player Y = %f",conf->player->px,conf->player->py);
	// mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->player.img, conf->player.px, conf->player->py);
    return 0;
}

int keyrealeased(int key,t_conf *conf)
{
    if(key == ESC)
        exit(0);
    else if (key == W)
        conf->player.to_w = 0;
	else if (key == D)
        conf->player.to_d = 0;
	else if (key == S)
        conf->player.to_s = 0;
	else if (key == A)
        conf->player.to_a = 0;
    else if(key == 123)
        conf->player.to_forward = 0;
    else if(key == 124)
    {
        conf->player.to_back = 0;
        // puts("hiahia");
    }
    return 1;
}

// void    move_to(t_conf *conf)
// {
//     // puts("here");
//     float pdx = cos(conf->player.rotangle - PI / 2);
//     float pdy = -sin(conf->player.rotangle - PI / 2);
//     // int xo = 0;
//     // int yo = 0;
//     // if (pdx > 0)
//     //     xo = -20;
//     // else
//     //     xo = 20;
//     // if (pdy > 0)
//     //     yo = -20;
//     // else
//     //     yo = 20;
//     if(conf->player.to_a == 1)
//     {
//         conf->player.px += cos(conf->player.rotangle) * conf->player.movespeed;
//         conf->player.py -= sin(conf->player.rotangle) * conf->player.movespeed;
//     }
//     if(conf->player.to_d == 1)
//     {
//         conf->player.px -= cos(conf->player.rotangle) * conf->player.movespeed;
//         conf->player.py += sin(conf->player.rotangle) * conf->player.movespeed;
//     }
//     if(conf->player.to_w == 1)
//     {
//         if (conf->player.px)
//         conf->player.px += pdx * conf->player.movespeed;
//         conf->player.py += pdy * conf->player.movespeed;
        
//     }
//     if(conf->player.to_s == 1)
//     {
//         conf->player.px += cos(conf->player.rotangle  + PI / 2)*conf->player.movespeed;
//         conf->player.py -= sin(conf->player.rotangle + PI / 2)* conf->player.movespeed;
//     }
//     if(conf->player.to_forward == 1)
//         conf->player.rotangle +=  conf->player.rotspeed;
//     if(conf->player.to_back == 1)
//         conf->player.rotangle -= conf->player.rotspeed;
        
// }
