/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:43:09 by imabid            #+#    #+#             */
/*   Updated: 2022/06/08 14:44:07 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_clear(t_conf *conf)
{
    int i =0, j = 0;
    while(i < mapXX )
    {
        j = 0;
        while(j < mapYY)
        {
            print_rectangl(conf,i,j,BLACK,0);  
            j++;
        }
        i++;
    }
}

void    player_print(t_conf *conf)
{
    int r = 5; 
    int i = 0;
    int j = 0;
    double x = conf->player.px;
    double y = conf->player.py;
    i = -r;
    line(conf,conf->player.py,
	conf->player.px,
	(conf->player.py + (60 * cos(conf->player.rotangle))) ,
	(conf->player.px + (60 * sin(conf->player.rotangle))), C2);
    while (i < r)
    {
        j = -r;
        while (j < r)
        {
            if ((i * i) + (j * j) <= (r * r))
            {
                conf->img.addr[(int)((i + y)) *
                (WIDTH) + (int)((j + x))] = C1;
            }
            j++;
        }
        i++;
    }
}