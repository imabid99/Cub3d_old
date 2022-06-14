/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 14:43:09 by imabid            #+#    #+#             */
/*   Updated: 2022/06/13 15:51:10 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_clear(t_conf *conf)
{
    int i =0, j = 0;
    while(i < mapXX)
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
    int f = 0;
    printf("%f -- \n",conf->player.rotangle);
    line(conf,conf->player.py,
	conf->player.px,
	(conf->player.py + ( 64 * -sin(conf->player.rotangle))) ,
	(conf->player.px + ( 64 * cos(conf->player.rotangle))), C2);

    i = -r;
    while (i < r)
    {
        j = -r;
        while (j < r)
        {
            if ((i * i) + (j * j) <= (r * r))
            {
                conf->img.addr[(int)((i + y)) *
                (WIDTH) + (int)((j + x))] = C2;
            }
            j++;
        }
        i++;
    }
}