/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:43:09 by imabid            #+#    #+#             */
/*   Updated: 2022/08/08 17:46:10 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_clear(t_conf *conf)
{
    int i =0, j = 0;
    while(i < conf->player.height)
    {
        j = 0;
        while(j < conf->player.width)
        {
            print_rectangl1(conf,i,j,BLACK,0);  
            j++;
        }
        i++;
    }
}

void    player_print(t_conf *conf)
{
    int r = 15; 
    int i = 0;
    int j = 0;
    double x = conf->player.px;
    double y = conf->player.py;
    i = -r;
    int f = 0;
    // line(conf,conf->player.py * minimap,
	// conf->player.px * minimap,
	// ((conf->player.py  + ( 10 * sin(conf->player.rotangle)) * minimap)) ,
	// ((conf->player.px  + ( 10 * cos(conf->player.rotangle)) * minimap)), C2);
    i = -r;
    while (i < r)
    {
        j = -r;
        while (j < r)
        {
            if ((i * i) + (j * j) <= (r * r))
            {
                conf->img.addr[(int)(((i + y)) * minimap) *
                conf->player.width + (int)(((j + x) * minimap))] = C2;
                // conf->img.addr[(int)(((i + y))) *
                // (WIDTH) + (int)(((j + x)))] = C2;
            }
            j++;
        }
        i++;
    }
}