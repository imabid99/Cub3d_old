/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:40:26 by imabid            #+#    #+#             */
/*   Updated: 2022/06/23 14:45:29 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    win_init(t_conf *conf)
{
    conf->mlx = mlx_init();
    conf->mlx_win = mlx_new_window(conf->mlx,conf->player.width, conf->player.height, "Cub3d");
}

void    img_init(t_conf *conf)
{
    conf->img.img = mlx_new_image(conf->mlx,conf->player.width, conf->player.height);
    conf->img.addr = (int *)mlx_get_data_addr(conf->img.img, &conf->img.bits_per_pixel, &conf->img.line_length,&conf->img.endian);
}

void    init_all(t_conf *conf)
{
    conf->player.dxx = 0;
    conf->player.dyy = 0;
    ft_get_playerPosition(&conf->player);
    conf->player.py = conf->player.dyy * 64 + 64 / 2;
    conf->player.px = conf->player.dxx * 64 + 64 / 2 ;
    conf->player.rotangle = PI / 2; 
    conf->player.movespeed = 3;
    conf->player.rotspeed = 1 * (PI / 180);
    conf->player.tdirection = 0;
    conf->player.walkdirection = 0;
    conf->player.to_a = 0;
    conf->player.to_w = 0;
    conf->player.to_s = 0;
    conf->player.to_d = 0;
    conf->player.to_back = 0;
    conf->player.to_forward = 0;
    conf->ray.num_rays = WIDTH; 
    conf->player.width = WIDTH;
    conf->player.height = HEIGHT;
    
    
}