/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:50:52 by imabid            #+#    #+#             */
/*   Updated: 2022/08/11 19:48:56 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern char map[16][16];

int player_move(int key,void *param)
{
    t_conf *conf;
    conf = (t_conf *)param;
    // zadt hna
    float pdx = -sin(conf->player.rotangle - PI / 2);
    float pdy = cos(conf->player.rotangle - PI / 2);
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
    // zadt hna
    else if(key == 49)
    {
        conf->player.to_space = 1;

    }
    // zadt hna 2
    else if(key == 3)
    {
            conf->ammo--;
        if(conf->ammo >= 0)
        {
            conf->mygun.img = mlx_xpm_file_to_image(conf->mlx,"asset/gun2222.xpm",&conf->mygun.img_width,&conf->mygun.img_height);
            mlx_put_image_to_window(conf->mlx,conf->mlx_win,conf->mygun.img,(WIDTH / 2) - 300 , HEIGHT - 360);
        }
    }
    else if (key == 15 && conf->ammo < 5)
    {
        conf->r = 1;
        conf->ammo = 15;
    }
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
    }
    else if(key == 49)
        conf->player.to_space = 0;
    else if (key == 15)
        conf->r = 0;
    return 1;
}
