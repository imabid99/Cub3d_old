/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_init1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:50:51 by imabid            #+#    #+#             */
/*   Updated: 2022/06/15 14:55:33 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_all2(t_conf *conf)
{
    conf->ray.wallhitx = 0;
	conf->ray.wallhity = 0;
	conf->ray.distance = 0;
	conf->ray.xstep = 0;
	conf->ray.ystep = 0;
	conf->ray.xintercept = 0;
	conf->ray.yintercept = 0;
	conf->ray.facingdown = 0;
	conf->ray.facingup = 0;
	conf->ray.facingright = 0;
	conf->ray.facingleft = 0;
	conf->ray.nexthox = 0;
	conf->ray.nexthoy = 0;
	conf->ray.foundhorwallhit = 0;

}