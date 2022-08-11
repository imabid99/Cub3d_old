/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:11:34 by imabid            #+#    #+#             */
/*   Updated: 2022/08/11 19:48:38 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>

void print_rectangl(t_conf *conf, int y, int x, int color, int line)
{
    int i;
    int j;

    x *= (TILE_SIZE * minimap);
    y *= (TILE_SIZE * minimap);
    i = 0;
    while (i < (TILE_SIZE - line) * minimap)
    {
        j = 0;
        while (j < (TILE_SIZE - line) * minimap)
        {
            conf->img.addr[(int)((y + j) ) * conf->player.width + (int)((x + i) )] = color;
            // conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
            j++;
        }
        i++;
    }
}
void print_rectangl1(t_conf *conf, int y, int x, int color, int line)
{
            conf->img.addr[(int)((y)) * conf->player.width + (int)((x))] = color;
}

char map[16][16] =
    {
        {'1','1','1','1','1','1','1','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','2','1','0','0','0','0','1'},
        {'1','0','2','0','0','0','0','1'},
        {'1','0','1','0','S','0','0','1'},
        {'1','0','2','0','0','0','0','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','2','0','0','0','0','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','1','0','0','0','0','1','1','1','1','1','1','1','1','1'},
        {'1','0','1','0','0','0','0','1','0','1','0','0','0','0','0','1'},
        {'1','0','2','0','0','0','0','1','0','1','1','1','1','1','0','1'},
        {'1','0','1','0','0','0','0','2','0','2','0','0','0','0','0','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
};
char old_map[16][16] =
    {
        {'1','1','1','1','1','1','1','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','2','1','0','0','0','0','1'},
        {'1','0','2','0','0','0','0','1'},
        {'1','0','1','0','S','0','0','1'},
        {'1','0','2','0','0','0','0','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','2','0','0','0','0','1'},
        {'1','0','1','0','0','0','0','1'},
        {'1','0','1','0','0','0','0','1','1','1','1','1','1','1','1','1'},
        {'1','0','1','0','0','0','0','1','0','1','0','0','0','0','0','1'},
        {'1','0','2','0','0','0','0','1','0','1','1','1','1','1','0','1'},
        {'1','0','1','0','0','0','0','2','0','2','0','0','0','0','0','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
};

double	normalize_ang(double angle)
{
    angle = remainder(angle, (2 * M_PI));
    // printf("remainder = %f\n",angle);
	if (angle < 0)
		angle = (2 * PI) + angle;
    // printf("right angle = %f\n",angle);
	return (angle);
}

double disbtp(double x1, double y1, double x2, double y2)
{
    return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
char    has_wall(t_conf *conf,double x,double y)
{
        if (x < 0 || x > (16 * 64)|| y < 0 || y > (16 * 64)) {
            return '1';
        }
        // printf("%f\n",floor(80.0));
        int mapindexX = floor(x / TILE_SIZE);
        int mapindexY = floor(y / TILE_SIZE);
        return map[mapindexY][mapindexX];
}
void move_to(t_conf *conf)
{   
    float pdx = -sin(conf->player.rotangle - PI / 2);
    float pdy = cos(conf->player.rotangle - PI / 2);
    if (conf->player.to_a == 1)
    {
        if(map[(int)((conf->player.py - (cos(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (sin(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)] != '1'
            && map[(int)((conf->player.py - (cos(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (sin(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)] != '2')
        {
            conf->player.px += sin(conf->player.rotangle) * conf->player.movespeed;
            conf->player.py -= cos(conf->player.rotangle) * conf->player.movespeed;   
        }
    }
    if (conf->player.to_d == 1)
    {
        if(map[(int)((conf->player.py + (cos(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - (sin(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)] != '1'
        && map[(int)((conf->player.py + (cos(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - (sin(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)] != '2')
        {
        conf->player.px -= sin(conf->player.rotangle) * conf->player.movespeed;
        conf->player.py += cos(conf->player.rotangle) * conf->player.movespeed;  
        }
    }
    // badal hadi llah ihafdk 
    if (conf->player.to_w == 1)
    {
        if (map[(int)((conf->player.py) / TILE_SIZE)][(int)((conf->player.px + (cos(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)] != '1' 
        && map[(int)((conf->player.py) / TILE_SIZE)][(int)((conf->player.px + (cos(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)] != '2' )
        {
            conf->player.px += cos(conf->player.rotangle) * conf->player.movespeed;
            // conf->player.py += pdy * conf->player.movespeed;
        }
        if(map[(int)((conf->player.py + (sin(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px) / TILE_SIZE)] != '1' 
        && map[(int)((conf->player.py + (sin(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px) / TILE_SIZE)] != '2')
        {
            conf->player.py += sin(conf->player.rotangle ) * conf->player.movespeed;
        }
    }
    // hadi l9dima
    // if (conf->player.to_w == 1)
    // {
    //     if (map[(int)((conf->player.py) / TILE_SIZE)][(int)((conf->player.px - (sin(conf->player.rotangle - PI / 2) * conf->player.movespeed)) / TILE_SIZE)] != '1' 
    //     && map[(int)((conf->player.py) / TILE_SIZE)][(int)((conf->player.px - (sin(conf->player.rotangle - PI / 2) * conf->player.movespeed)) / TILE_SIZE)] != '2' )
    //     {
            
    //         conf->player.px += pdx * conf->player.movespeed;
    //         puts("here");
    //         // conf->player.py += pdy * conf->player.movespeed;
    //     }
    //     if(map[(int)((conf->player.py + (cos(conf->player.rotangle - PI / 2) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px) / TILE_SIZE)] != '1' 
    //     && map[(int)((conf->player.py + (cos(conf->player.rotangle - PI / 2) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px) / TILE_SIZE)] != '2')
    //     {
    //         conf->player.py += pdy * conf->player.movespeed;
    //         puts("here1");
            
    //     }
    // }
    if (conf->player.to_s == 1)
    {
        if(map[(int)((conf->player.py - (sin(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - (cos(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)] != '1'
        && map[(int)((conf->player.py - (sin(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - (cos(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)] != '2')
        {
        conf->player.px -= cos(conf->player.rotangle) * conf->player.movespeed;
        conf->player.py -= sin(conf->player.rotangle) * conf->player.movespeed;
            
        } 
    }
    // zadt hna
    if (conf->player.to_space == 1)
    {
        if(conf->ray.facingdown)
        {
            if (map[(int)((conf->player.py + 20 + (pdy * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + 20 + (pdx * conf->player.movespeed)) / TILE_SIZE)] == '2')
                map[(int)((conf->player.py + 20 + (pdy * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + 20 + (pdx * conf->player.movespeed)) / TILE_SIZE)] = '0';
        }
        else if(conf->ray.facingup)
        {
            if (map[(int)((conf->player.py - 20 + (pdy * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - 20 + (pdx * conf->player.movespeed)) / TILE_SIZE)] == '2')
                map[(int)((conf->player.py - 20 + (pdy * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - 20 + (pdx * conf->player.movespeed)) / TILE_SIZE)] = '0';
        }
    }
}
void    rayfacing(t_conf *conf, double _ang)
{
    conf->ray.facingdown = _ang > 0 && _ang < PI;
    conf->ray.facingup = !conf->ray.facingdown;
    
    conf->ray.facingright = _ang < 0.5 * PI || _ang > 1.5 * PI;
    conf->ray.facingleft = !conf->ray.facingright;
}
double    hoz_intersection(t_conf *conf, double _ang)
{
    //   bach nl9aw y_coordinate dyal closest horix grid intersection
    conf->ray.yintercept = floor(conf->player.py / TILE_SIZE) * TILE_SIZE;
    conf->ray.yintercept += conf->ray.facingdown ? TILE_SIZE : 0; 
    // bach nl9aw x_coordinate dyal closest horix grid intersection
    conf->ray.xintercept = conf->player.px + (conf->ray.yintercept - conf->player.py) / tan(_ang);
    // printf("--%f---%f--\n",floor(conf->player.py/TILE_SIZE),conf->player.py / TILE_SIZE) ;

    // n7sbo increment dyal xstep o ystep
    conf->ray.ystep = TILE_SIZE;
    conf->ray.ystep *= conf->ray.facingup ? -1 : 1;
    
    conf->ray.xstep = TILE_SIZE / tan(_ang); 
    conf->ray.xstep *= (conf->ray.facingleft && conf->ray.xstep > 0) ? -1 : 1;
    conf->ray.xstep *= (conf->ray.facingright && conf->ray.xstep < 0) ? -1 : 1;

    conf->ray.nexthox = conf->ray.xintercept;
    conf->ray.nexthoy = conf->ray.yintercept;
    // if(conf->ray.facingup)
    //     conf->ray.nexthoy--; 
        // incrementiw xstep o ystep tanl9aw wallƒ
    // while(1)
    // nextVertTouchX >= 0 && nextVertTouchX <= WINDOW_WIDTH && nextVertTouchY >= 0 && nextVertTouchY <= WINDOW_HEIGHT
    while(conf->ray.nexthox >= 0 && conf->ray.nexthox <= (16 * 64) && conf->ray.nexthoy >= 0
        && conf->ray.nexthoy <= (16 * 64))
    // while(conf->ray.nexthox >= 0 && conf->ray.nexthox <= conf->player.width && conf->ray.nexthoy >= 0
    //     && conf->ray.nexthoy <= conf->player.height)
    {
        conf->ray.xhortocheck = conf->ray.nexthox;
        conf->ray.yhortocheck = conf->ray.nexthoy - (conf->ray.facingup ? 1 : 0);
            // puts("hahaha");
            // printf("----%c----\n",has_wall(conf->ray.nexthox ,conf->ray.nexthoy - conf->ray.facingup ? 1 : 0));
            // printf("---- %d ----\n",conf->ray.nexthoy - conf->ray.facingup) ? 1 : 0);
        if(has_wall(conf,conf->ray.xhortocheck ,conf->ray.yhortocheck) == '1' || has_wall(conf,conf->ray.xhortocheck ,conf->ray.yhortocheck) == '2') 
        {
            // printf("%c\n",has_wall(conf->ray.nexthox ,conf->ray.nexthoy - conf->ray.facingup ? 1 : 0));
            conf->ray.foundhorwallhit = 1;
            conf->ray.horwallhitx = conf->ray.nexthox;
            conf->ray.horwallhity = conf->ray.nexthoy;
            // zadt hna
            conf->ray.horwallcontent = map[(int)floor(conf->ray.yhortocheck / TILE_SIZE)][(int)floor(conf->ray.xhortocheck / TILE_SIZE)];
            //  printf("%d\n",conf->ray.horwallcontent);
            break;
        }
        else{
            conf->ray.nexthox += conf->ray.xstep;
            conf->ray.nexthoy += conf->ray.ystep;
        }
    }
    if(conf->ray.foundhorwallhit)
    {
    //we return distance between two poins
        // printf(" disbtp = %f\n",disbtp(conf->player.px,conf->player.py,conf->ray.verwallhitx,conf->ray.verwallhity));
        return(disbtp(conf->player.px,conf->player.py,conf->ray.horwallhitx,conf->ray.horwallhity));
        
    }
    // puts("here");
    return (DBL_MAX);
}
double   ver_intersection(t_conf *conf, double _ang)
{
     //   bach nl9aw x_coordinate dyal closest ver grid intersection
    conf->ray.xintercept = floor(conf->player.px / TILE_SIZE) * TILE_SIZE;
    conf->ray.xintercept += conf->ray.facingright ? TILE_SIZE : 0; 
    // bach nl9aw y_coordinate dyal closest ver grid intersection
    conf->ray.yintercept = conf->player.py + (conf->ray.xintercept - conf->player.px) * tan(_ang);
    // printf("--%f---%f--\n",floor(conf->player.py/TILE_SIZE),conf->player.py / TILE_SIZE);

    // n7sbo increment dyal xstep o ystep
    conf->ray.xstep = TILE_SIZE;
    conf->ray.xstep *= conf->ray.facingleft ? -1 : 1;
    
    conf->ray.ystep = TILE_SIZE * tan(_ang); 
    conf->ray.ystep *= (conf->ray.facingup && conf->ray.ystep > 0) ? -1 : 1;
    conf->ray.ystep *= (conf->ray.facingdown && conf->ray.ystep < 0) ? -1 : 1;

    conf->ray.nextverx = conf->ray.xintercept;
    conf->ray.nextvery = conf->ray.yintercept;
        // incrementiw xstep o ystep tanl9aw wall
    // while(1)
    while(conf->ray.nextverx >= 0 && conf->ray.nextverx <= (16 * 64) && conf->ray.nextvery >= 0
        && conf->ray.nextvery <= (16 * 64))
    // while(conf->ray.nextverx >= 0 && conf->ray.nextverx <= conf->player.width && conf->ray.nextvery >= 0
    //     && conf->ray.nextvery <= conf->player.height)
    {
        conf->ray.xvertocheck = conf->ray.nextverx - (conf->ray.facingleft ? 1 : 0);
        conf->ray.yvertocheck = conf->ray.nextvery;
        
        // printf("%d\n",conf->player.width);
        if(has_wall(conf,conf->ray.xvertocheck,conf->ray.yvertocheck) == '1' || has_wall(conf,conf->ray.xvertocheck,conf->ray.yvertocheck) == '2') 
        {
            conf->ray.verwallhitx = conf->ray.nextverx;
            conf->ray.verwallhity = conf->ray.nextvery;
            //zid hadi
            // zadt hna
            conf->ray.verwallcontent = map[(int)floor(conf->ray.yvertocheck / TILE_SIZE)][(int)floor(conf->ray.xvertocheck / TILE_SIZE)];
            // printf("tt = %d\n", map[(int)floor(conf->ray.xvertocheck / TILE_SIZE)][(int)floor(conf->ray.yvertocheck / TILE_SIZE)]);
            conf->ray.foundverwallhit = 1;
            break;
        }
        else{
            conf->ray.nextverx += conf->ray.xstep;
            conf->ray.nextvery += conf->ray.ystep;
        }
    }
    if(conf->ray.foundverwallhit)
    {
    //we return distance between two poins
    // printf(" disbtp = %f\n",disbtp(conf->player.px,conf->player.py,conf->ray.verwallhitx,conf->ray.verwallhity));
        return(disbtp(conf->player.px,conf->player.py,conf->ray.verwallhitx,conf->ray.verwallhity));
    }
    // puts("here");
    return (DBL_MAX);
}
void    check_intersection(t_conf *conf, double _ang,int i)
{
    init_all2(conf);
    _ang = normalize_ang(_ang);
    rayfacing(conf, _ang);
    conf->wall.faceleft[i] = conf->ray.facingleft;
    conf->wall.faceright[i] = conf->ray.facingright;
    conf->wall.faceup[i] = conf->ray.facingup;
    conf->wall.facedown[i] = conf->ray.facingdown;
    conf->ray.hordist = hoz_intersection(conf, _ang);
    // hoz_intersection(conf);
    conf->ray.verdist = ver_intersection(conf, _ang);
    if (conf->ray.verdist > conf->ray.hordist)
	{
		conf->ray.wallhitX = conf->ray.horwallhitx;
		conf->ray.wallhitY = conf->ray.horwallhity;
        conf->ray.distance = conf->ray.hordist;
        conf->ray.washitvert = 0;
        // zadt hna
        conf->ray.wallcon = conf->ray.horwallcontent;
        // printf("adf = %d\n",conf->ray.horwallcontent);
	}
	else
	{
		conf->ray.wallhitX  = conf->ray.verwallhitx;
		conf->ray.wallhitY  = conf->ray.verwallhity;
        conf->ray.distance = conf->ray.verdist;
		conf->ray.washitvert = 1;
        // zadt hna
        conf->ray.wallcon = conf->ray.verwallcontent;
        // printf("adf = %d\n",conf->ray.verwallcontent);
	}
     
    // double foundhorwallhit = 0; 
    // bach nl9aw y_coordinate dyal closest horix grid intersection
    // conf->ray.yintercept = floor(conf->player.py / TILE_SIZE) * TILE_SIZE;
    // conf->ray.yintercept += conf->ray.facingdown ? TILE_SIZE : 0; 
    // // bach nl9aw x_coordinate dyal closest horix grid intersection
    // conf->ray.xintercept = conf->player.px + (conf->ray.yintercept - conf->player.py) / tan(conf->ray.rayangle);
    // // printf("--%f---%f--\n",floor(conf->player.py/TILE_SIZE),conf->player.py / TILE_SIZE);

    // // n7sbo increment dyal xstep o ystep
    // conf->ray.ystep = TILE_SIZE;
    // conf->ray.ystep *= conf->ray.facingup ? -1 : 1;
    
    // conf->ray.xstep = TILE_SIZE / tan(conf->ray.rayangle); 
    // conf->ray.xstep *= (conf->ray.facingleft && conf->ray.xstep > 0) ? -1 : 1;
    // conf->ray.xstep *= (conf->ray.facingright && conf->ray.xstep < 0) ? -1 : 1;

    // conf->ray.nexthox = conf->ray.xintercept;
    // conf->ray.nexthoy = conf->ray.yintercept;
    // if(conf->ray.facingup)
    //     conf->ray.nexthoy--; 
    //     // incrementiw xstep o ystep tanl9aw wall
    // while(conf->ray.nexthox >= 0 && conf->ray.nexthox <= conf->player.width && conf->ray.nexthoy >= 0
    //     && conf->ray.nexthoy <= conf->player.height)
    // {
    //         // puts("hahaha");
    //     if(has_wall(conf->ray.nexthox,conf->ray.nexthoy) == '1') 
    //     {
             
    //         conf->ray.foundhorwallhit = 1;
    //         conf->ray.horwallhitx = conf->ray.nexthox;
    //         conf->ray.horwallhity = conf->ray.nexthoy;
    //         line(conf,conf->player.py,
	//     conf->player.px,
	//     (conf->ray.horwallhity) ,
	//     (conf->ray.horwallhitx), BLACK);
    //         break;
    //     }
    //     else{
    //         conf->ray.nexthox += conf->ray.xstep;
    //         conf->ray.nexthoy += conf->ray.ystep;
    //     }
    // }

    // printf("|%f|---|%f|\n",conf->ray.xstep,conf->ray.ystep);
}
void    rotate(t_conf *conf)
{
    conf->player.rotangle = normalize_ang(conf->player.rotangle);
    if (conf->player.to_forward == 1)
        conf->player.rotangle -= conf->player.turnspeed;
    if (conf->player.to_back == 1)
        conf->player.rotangle += conf->player.turnspeed;
}

void cast_rays(t_conf *conf)
{
    // int columnbr = 0;
    double _ang = 0;
    _ang = conf->player.rotangle - (FOV / 2);
    int i = 0;
    conf->wall.line_distance = malloc(sizeof(double) * conf->ray.num_rays);
    conf->wall.wX = malloc(sizeof(double) * conf->ray.num_rays);
    conf->wall.wY = malloc(sizeof(double) * conf->ray.num_rays);
    conf->ray.rayangle = malloc(sizeof(double) * conf->ray.num_rays);
    conf->wall.hitver = malloc(sizeof(double) * conf->ray.num_rays);
    conf->wall.faceup = malloc(sizeof(double) * conf->ray.num_rays);
    conf->wall.facedown = malloc(sizeof(double) * conf->ray.num_rays);
    conf->wall.faceright = malloc(sizeof(double) * conf->ray.num_rays);
    conf->wall.faceleft = malloc(sizeof(double) * conf->ray.num_rays);
    // zadt hna
    conf->wall.con = malloc(sizeof(double) * conf->ray.num_rays);
    // conf->wall.conhor = malloc(sizeof(double) * conf->ray.num_rays);
    while(i < conf->ray.num_rays)
    // while(i < 1)
    {
        // puts("here");
        _ang = normalize_ang(_ang);
        // conf->wall.faceleft[i] = conf->ray.facingleft;
        // conf->wall.faceright[i] = conf->ray.facingright;
        // conf->wall.faceup[i] = conf->ray.facingup;
        // conf->wall.facedown[i] = conf->ray.facingdown;
        check_intersection(conf, _ang,i);
        line(conf,conf->player.py * minimap,
	    conf->player.px * minimap,
	    conf->ray.wallhitY * minimap,
	    conf->ray.wallhitX * minimap, C1);
        // line(conf,conf->player.py ,
	    // conf->player.px ,
	    // conf->ray.wallhitY ,
	    // conf->ray.wallhitX , C1);
        _ang += FOV /conf->ray.num_rays;
        conf->ray.rayangle[i] = _ang;
        conf->wall.line_distance[i] = conf->ray.distance;
        conf->wall.wX[i] = conf->ray.wallhitX;
        conf->wall.wY[i] = conf->ray.wallhitY;
        conf->wall.hitver[i] = conf->ray.washitvert; 
        // zadt hna
        conf->wall.con[i] = conf->ray.wallcon;
        // conf->wall.conhor[i] = 
        // conf->wall.faceleft[i] = conf->ray.facingleft;
        // conf->wall.faceright[i] = conf->ray.facingright;
        // conf->wall.faceup[i] = conf->ray.facingup;
        // conf->wall.facedown[i] = conf->ray.facingdown;
        // conf->wall.face[i] = conf->ray.washitvert; 
        // if(conf->ray.facingup)
        //     conf->wall.a = 0;
        // if(conf->ray.facingdown)
        //     conf->wall.a = 1;
        // if(conf->ray.facingleft)
        //     conf->wall.a = 2;
        // if(conf->ray.facing)
        //     conf->wall.a = 0;
        // if(conf->ray.facingup)
        //     conf->wall.a = 0;
        
        i++;
    }
    // line(conf,conf->player.py ,
	// conf->player.px ,
	// (conf->player.py + (100 * cos(conf->player.rotangle))),
	// (conf->player.px + (100 * -sin(conf->player.rotangle))), BLACK);
    // line(conf,conf->player.py,
	// conf->player.px,
	// (conf->player.py + ( 80 * sin(conf->player.rotangle))) ,
	// (conf->player.px + ( 80 * cos(conf->player.rotangle))), BLACK);
    
}
void ft_get_playerPosition(t_player *player)
{
    int i = 0;
    int j;
    while (i < 16)
    {
        j = 0;
        while (j < 16)
        {
            if (map[i][j] == 'S')
            {
                player->dxx = j;
                player->dyy = i;
                // printf("%d,%d \n", map[player->dxx][player->dyy]);
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

    //         conf->img.addr[(i) * conf->player.width + (j)] = GRAY;
    //         j++;
    //     }
    //     i++;
    // }

    while(i < 16)
    {
        j = 0;
        while(j < 16)
        {
            // printf("%c",map[i][j]);
            if(map[i][j] == '1')
                print_rectangl(conf,i, j,GRAY,0);
            else if(map[i][j] == '0' || map[i][j] == 'S')
                print_rectangl(conf,i, j,WHITE,0);
            else if(map[i][j] == '2')
                print_rectangl(conf,i, j,C2,0);
            j++;
        }
        // printf("\n");
        i++;
    }
}
// void    ft_draw_line(t_conf *conf)
// {
//     int x;
//     int i = 0;
//     int j ;
//     // printf("x = %d, y = %d, conf->wall.drawStarty = %f, ")
//     //  printf("startx = %d, starty = %d\n",conf->wall.drawStartx, conf->wall.drawStarty);
//     while (i < 1)
//     {
//         j = conf->wall.drawStarty < 0 ? -conf->wall.drawStarty : 0;
//         while (j < conf->wall.wallstripheight)
//         {
//             // printf("kahria1 = %d\n",j);
//             // if(conf->ray.washitvert)
//                 conf->img.addr[((conf->wall.drawStarty + j) * conf->player.width + (conf->wall.drawStartx + i))] = AQUA;
//             // else
//             //     conf->img.addr[((conf->wall.drawStarty + j) * conf->player.width + (conf->wall.drawStartx + i))] = GRAY;
//             j++;
//         }
//         i++;
//     }
// }

void    texture_facing(t_conf *conf)
{
    if(!conf->wall.hitver[conf->wall.drawStartx] && conf->wall.faceup[conf->wall.drawStartx])
        conf->txtnbr = 0;
    if(!conf->wall.hitver[conf->wall.drawStartx] && conf->wall.facedown[conf->wall.drawStartx] )
        conf->txtnbr = 1;
    if(conf->wall.hitver[conf->wall.drawStartx] && conf->wall.faceleft[conf->wall.drawStartx])
        conf->txtnbr = 2;
    if(conf->wall.hitver[conf->wall.drawStartx] && conf->wall.faceright[conf->wall.drawStartx])
        conf->txtnbr = 3;
}
void    draw_wall(t_conf *conf)
{
    int x = 0;
    
     while( x < conf->wall.topwall)
    {
        conf->img.addr[(x * conf->player.width + conf->wall.drawStartx)] = AQUA;
        x++;
    }
    	int y;
	// static float x;
	int texoffsetY;
	int disfromtop;
	int texoffsetX;
		// printf("x = %f y =%f\n", conf->wall.wY[conf->wall.drawStartx], conf->wall.wX[conf->wall.drawStartx]);
	// puts("here");
	if(conf->wall.hitver[conf->wall.drawStartx])
		texoffsetX = (int)conf->wall.wY[conf->wall.drawStartx] % TILE_SIZE;
	else
		texoffsetX = (int)conf->wall.wX[conf->wall.drawStartx] % TILE_SIZE;
	// exit(0);
		// printf("x = %d y =%d\n", texoffsetX, texoffsetY);
    // printf("%d\n",conf->wall.hitver[conf->wall.drawStartx] % 64);
	int color;
    // zadt hna
    int texnm = conf->wall.con[conf->wall.drawStartx];
    // printf("%d   \n",texnm);
    // y = conf->wall.topwall  ;
	y = conf->wall.topwall < 0 ? -conf->wall.topwall : 0;
    texture_facing(conf);
    while (y < conf->wall.bottomwall)
    {
		// if (x > 64)
		// 	x = 0;
		// disfromtop = y + (conf->wall.wallstripheight / 2) - (conf->player.width / 2);
		// texoffsetY = disfromtop * (TEX_HEIGHT / conf->wall.wallstripheight);
        // puts("here");
        // printf("00conf->wall.top=%d, 00conf->wall.bottomwall= %d\n",conf->wall.topwall,conf->wall.bottomwall);
		texoffsetY = (y) * (TEX_HEIGHT / conf->wall.wallstripheight);
		// printf("x = %d y =%d\n", texoffsetX, texoffsetY);
		color = conf->elem[conf->txtnbr].texture.addr[(texoffsetY * TEX_HEIGHT) + texoffsetX];
        // zadt hna
        if(texnm == '2')
        {
            // puts("here");
            color = conf->elem[4].texture.addr[(texoffsetY * TEX_HEIGHT) + texoffsetX];
        }
		// color = C1;
        conf->img.addr[((y + conf->wall.topwall) * conf->player.width  + (conf->wall.drawStartx + 1))] = color;
        y++;
    }
    int j = conf->wall.bottomwall;
     while( j < conf->player.height)
    {
        conf->img.addr[(j * conf->player.width + conf->wall.drawStartx)] = GRAY;
        j++;
    }
}
void    render3d(t_conf *conf)
{
    // double _ang;

    // _ang = conf->player.rotangle + (FOV/ 2);
    conf->wall.playerWallDist = (conf->player.width / 2) / tan(FOV / 2);
        // printf("wallDist = %f\n",conf->wall.playerWallDist);
    conf->wall.wallstripheight = 0;
    conf->wall.drawStartx = 0;
    
    while (conf->wall.drawStartx < conf->ray.num_rays)
    {
        // _ang = normalize_ang(_ang);

        // printf("ray = %f\n",conf->ray.distance);
        // printf("rayangle = %f rootangle %f\n",conf->ray.rayangle,conf->player.rotangle);
        // printf("line distane = %f\n",conf->wall.line_distance[conf->wall.drawStartx]);
        conf->wall.corrwall = conf->wall.line_distance[conf->wall.drawStartx] * cos(conf->ray.rayangle[conf->wall.drawStartx] - conf->player.rotangle);
        // printf("%f\n",conf->wall.corrwall);
        conf->wall.wallstripheight = (TILE_SIZE / conf->wall.corrwall) * conf->wall.playerWallDist;
        // conf->wall.wallstripheight = conf->wall.wallstripheight >= conf->player.height ? conf->player.height : conf->wall.wallstripheight;
        // printf("kahria1 = %f, kharia2 = %f\n",conf->wall.wallstripheight,conf->wall.playerWallDist);
        // conf->wall.wallstripheight = conf->wall.wallstripheight >= HEIGHT ? HEIGHT : conf->wall.wallstripheight;
        // printf("%f\n", conf->wall.wallstripheight);
        // conf->wall.drawStarty = (conf->player.height / 2) - (conf->wall.wallstripheight / 2);
        // conf->wall.drawStarty = conf->wall.drawStarty < 0 ? 0 : conf->wall.drawStarty;
        conf->wall.topwall = (conf->player.height / 2) - (conf->wall.wallstripheight / 2);
        // conf->wall.topwall = conf->wall.topwall < 0 ? 0 : conf->wall.topwall;
        conf->wall.bottomwall = (conf->player.height / 2) + (conf->wall.wallstripheight / 2);
        // conf->wall.bottomwall = conf->wall.bottomwall > conf->player.height ? 0 : conf->wall.bottomwall;
        
        // ft_draw_line(conf);
        draw_wall(conf);
        conf->wall.drawStartx++;
    }
}

void    try_to_close_door(t_conf *conf)
{
    int    i;
    int    j;
    int    x;
    int    y;

    i = 0;
    y = (int)(conf->player.py / TILE_SIZE);
    x = (int)(conf->player.px / TILE_SIZE);
    while (i < 16)
    {
        j = 0;
        while (j < 16)
        {
            if (old_map[i][j] && old_map[i][j] == '2')
            {
                if (((j != x) && (j + 1 != x && j - 1 != x)))
                    map[i][j] = old_map[i][j];
                if (((i != y) && (i + 1 != y && i - 1 != y)))
                    map[i][j] = old_map[i][j];
            }
            j++;
        }
        i++;
    }
}

int main_loop(t_conf *conf)
{
    int ammo;

    ammo = conf->ammo;
    void    *img;
    ft_clear(conf);
    cast_rays(conf);
    render3d(conf);
    mapp_print(conf);
    player_print(conf);
    // cast_rays(conf);
    conf->mygun.img = mlx_xpm_file_to_image(conf->mlx,"asset/gun111.xpm",&conf->mygun.img_width,&conf->mygun.img_height);
    img = mlx_xpm_file_to_image(conf->mlx,"asset/ammo.xpm",&conf->mygun.img_width,&conf->mygun.img_height);
    conf->mygun.img2 = mlx_xpm_file_to_image(conf->mlx,"asset/kkl.xpm",&conf->mygun.img_width,&conf->mygun.img_height);
    move_to(conf);
    rotate(conf);
    mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->img.img, 0, 0);
    if (conf->r == 0 && conf->ammo > 0)
        mlx_put_image_to_window(conf->mlx,conf->mlx_win,conf->mygun.img,(WIDTH / 2) - 300 , HEIGHT - 360);
    if(conf->ammo <= 0)
    {
        conf->mygun.img3 = mlx_xpm_file_to_image(conf->mlx,"asset/knife6.xpm",&conf->mygun.img_width,&conf->mygun.img_height);
        mlx_put_image_to_window(conf->mlx,conf->mlx_win,conf->mygun.img3,(WIDTH / 2) - 250, HEIGHT - 280);
    }
    while (conf->r == 0 && ammo-- > 0)
        mlx_put_image_to_window(conf->mlx,conf->mlx_win,img,(ammo * 32), HEIGHT - 70);
    try_to_close_door(conf);
    return 0;
}
void cub3d_hook(t_conf *conf)
{
    mlx_clear_window(conf->mlx, conf->mlx_win);
    ft_clear(conf);
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
    init_all(&conf);
    cub3d_hook(&conf);
    return 0;
}
