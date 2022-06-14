/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:40:26 by imabid            #+#    #+#             */
/*   Updated: 2022/06/11 16:50:16 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    win_init(t_conf *conf)
{
    conf->mlx = mlx_init();
    conf->mlx_win = mlx_new_window(conf->mlx,mapXX * 64, mapYY * 64, "Cub3d");
}

void    img_init(t_conf *conf)
{
    conf->img.img = mlx_new_image(conf->mlx,mapXX * 64, mapYY * 64);
    conf->img.addr = (int *)mlx_get_data_addr(conf->img.img, &conf->img.bits_per_pixel, &conf->img.line_length,&conf->img.endian);
}

void    init_all(t_conf *conf)
{
    ft_get_playerPosition(&conf->player);
    conf->player.py = conf->player.dyy * 64 + 64 / 2;
    conf->player.px = conf->player.dxx * 64 + 64 / 2 ;
    conf->player.rotangle = PI / 2; 
    conf->player.movespeed = 3;
    conf->player.rotspeed = 3 * (PI / 180);
    conf->player.width = mapXX * TILE_SIZE;
    conf->player.height = mapYY * TILE_SIZE;
    conf->player.tdirection = 0;
    conf->player.walkdirection = 0;
    conf->player.to_a = 0;
    conf->player.to_w = 0;
    conf->player.to_s = 0;
    conf->player.to_d = 0;
    conf->ray.fov = 60 * (PI / 180); // move degres to radian
    conf->ray.num_rays = WIDTH; 
    
}