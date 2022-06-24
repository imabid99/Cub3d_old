/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:11:34 by imabid            #+#    #+#             */
/*   Updated: 2022/06/24 12:05:27 by imabid           ###   ########.fr       */
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
// void print_rectangl(t_conf *conf, int y, int x, int color, int line)
// {
//     int i;
//     int j;

//     x *= (TILE_SIZE);
//     y *= (TILE_SIZE);
//     i = 0;
//     while (i < (TILE_SIZE - line))
//     {
//         j = 0;
//         while (j < (TILE_SIZE - line))
//         {
//             conf->img.addr[(int)((y + j) ) * conf->player.width + (int)((x + i) )] = color;
//             // conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
//             j++;
//         }
//         i++;
//     }
// }
void print_rectangl1(t_conf *conf, int y, int x, int color, int line)
{
    // int i;
    // int j;

    // x *= 1;
    // y *= conf->wall.wallstripconf->player.height;
    // i = 0;
    // while (i < TILE_SIZE - line)
    // {
    //     j = 0;
    //     while (j < TILE_SIZE - line)
    //     {
            conf->img.addr[(int)((y)) * conf->player.width + (int)((x))] = color;
            // conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
    //         j++;
    //     }
    //     i++;
    // }
}

// float playerX = 100;
// float playerY = 100;
// int mapX = 16, mapY = 16, mapS = 64;

char map[16][16] =
    {
        // {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        // {'0', '0', '0', '0', '0', '0', '0', '1', '1'},
        // {'0', '0', '0', 'S', '0', '0', '0', '1', '1'},
        // {'1', '0', '0', '1', '1', '1', '1', '1', '1'},
        // {'1', '0', '0', '0', '0', '0', '0', '1', '1'},
        // {'1', '0', '0', '0', '0', '0', '0', '1', '1'},
        // {'1', '0', '0', '0', '0', '0', '0', '1', '1'},
        // {'1', '1', '1', '1', '1', '1', '1', '1', '1'},
        // {1,1,1,1,1,1,1,1,1},
        // {1,0,0,0,0,0,0,1,1},
        // {0,0,0,2,0,0,0,1,1},
        // {1,0,0,1,1,1,1,1,1},
        // {1,0,0,0,0,0,0,1,1},
        // {1,0,0,0,0,0,0,1,1},
        // {1,0,0,0,0,0,0,1,1},
        // {1,1,1,1,1,1,1,1,1},
        {'1','1','1','1','1','1','1','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','1','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','1','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','1','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','1','1','1','1','1','1','1','1','1'},
        {'1','0','0','0','0','0','0','0','S','1','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','1','1','1','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'}
};

double	normalize_ang(double angle)
{
    angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle = (2 * PI) + angle;
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
        if(map[(int)((conf->player.py - (cos(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (sin(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
            conf->player.px += sin(conf->player.rotangle) * conf->player.movespeed;
            conf->player.py -= cos(conf->player.rotangle) * conf->player.movespeed;   
        }
    }
    if (conf->player.to_d == 1)
    {
        if(map[(int)((conf->player.py + (cos(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - (sin(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
        conf->player.px -= sin(conf->player.rotangle) * conf->player.movespeed;
        conf->player.py += cos(conf->player.rotangle) * conf->player.movespeed;  
        }
    }
    if (conf->player.to_w == 1)
    {
        if (map[(int)((conf->player.py + (pdy * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (pdx * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
            conf->player.px += pdx * conf->player.movespeed;
            conf->player.py += pdy * conf->player.movespeed;
        }
        // else
        // {
        //     conf->player.px -= sin(conf->player.rotangle) * conf->player.movespeed;
        //     conf->player.py += cos(conf->player.rotangle) * conf->player.movespeed;
        // }
    }
    if (conf->player.to_s == 1)
    {
        if(map[(int)((conf->player.py - (cos(conf->player.rotangle - PI / 2) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (sin(conf->player.rotangle - PI / 2) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
        conf->player.px += sin(conf->player.rotangle - PI / 2) * conf->player.movespeed;
        conf->player.py -= cos(conf->player.rotangle - PI / 2) * conf->player.movespeed;
            
        } 
    }
}
void    rayfacing(t_conf *conf, double _ang)
{
    conf->ray.facingdown = _ang > 0 && _ang < PI;
    conf->ray.facingup = !conf->ray.facingdown;
    conf->ray.facingright = _ang < 0.5 * PI || _ang > 1.5 * PI;
    conf->ray.facingleft = !conf->ray.facingright;
    // printf("%d\n",conf->ray.facingright);  
}
double    hoz_intersection(t_conf *conf, double _ang)
{
    // init_all2(conf);
    //   bach nl9aw y_coordinate dyal closest horix grid intersection
    conf->ray.yintercept = floor(conf->player.py / TILE_SIZE) * TILE_SIZE;
    conf->ray.yintercept += conf->ray.facingdown ? TILE_SIZE : 0; 
    // bach nl9aw x_coordinate dyal closest horix grid intersection
    conf->ray.xintercept = conf->player.px + (conf->ray.yintercept - conf->player.py) / tan(_ang);
    // printf("--%f---%f--\n",floor(conf->player.py/TILE_SIZE),conf->player.py / TILE_SIZE);

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
            // puts("hahaha");
            // printf("----%c----\n",has_wall(conf->ray.nexthox ,conf->ray.nexthoy - conf->ray.facingup ? 1 : 0));
            // printf("---- %d ----\n",conf->ray.nexthoy - conf->ray.facingup) ? 1 : 0);
        if(has_wall(conf,conf->ray.nexthox ,conf->ray.nexthoy - (conf->ray.facingup ? 1 : 0)) == '1') 
        {
            // printf("%c\n",has_wall(conf->ray.nexthox ,conf->ray.nexthoy - conf->ray.facingup ? 1 : 0));
            conf->ray.foundhorwallhit = 1;
            conf->ray.horwallhitx = conf->ray.nexthox;
            conf->ray.horwallhity = conf->ray.nexthoy;
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
        // printf("%d\n",conf->player.width);
        if(has_wall(conf,conf->ray.nextverx - (conf->ray.facingleft ? 1 : 0),conf->ray.nextvery) == '1') 
        {
            conf->ray.foundverwallhit = 1;
            conf->ray.verwallhitx = conf->ray.nextverx;
            conf->ray.verwallhity = conf->ray.nextvery;
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
void    check_intersection(t_conf *conf, double _ang)
{
    init_all2(conf);
    _ang = normalize_ang(_ang);
    rayfacing(conf, _ang);
    conf->ray.hordist = hoz_intersection(conf, _ang);
    // hoz_intersection(conf);
    conf->ray.verdist = ver_intersection(conf, _ang);
    // printf("hordist = %f ==== verdist = %f ",floor(conf->ray.hordist),floor(conf->ray.verdist));
    // printf("angle = %f\n",conf->ray.rayangle);
    // exit(0);
    // ver_intersection(conf);
    // hna kanstori smallest of the distancce
    // conf->ray.wallhitX = (conf->ray.hordist < conf->ray.verdist) ? conf->ray.horwallhitx : conf->ray.verwallhitx;
    // conf->ray.wallhitY = (conf->ray.hordist < conf->ray.verdist) ? conf->ray.horwallhity : conf->ray.verwallhity;
    // conf->ray.distance = (conf->ray.hordist < conf->ray.verdist) ? conf->ray.hordist : conf->ray.verdist;
    // conf->ray.washitvert = conf->ray.verdist < conf->ray.hordist;
    // n7asbo both horz and ver onchofo chkon li 9rab
    if (conf->ray.verdist > conf->ray.hordist)
	{
		conf->ray.wallhitX = conf->ray.horwallhitx;
		conf->ray.wallhitY = conf->ray.horwallhity;
        conf->ray.distance = conf->ray.hordist;
        conf->ray.washitvert = 0;
	}
	else
	{
		conf->ray.wallhitX  = conf->ray.verwallhitx;
		conf->ray.wallhitY  = conf->ray.verwallhity;
        conf->ray.distance = conf->ray.verdist;
		conf->ray.washitvert = 1;

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
        conf->player.rotangle -= conf->player.rotspeed;
    if (conf->player.to_back == 1)
        conf->player.rotangle += conf->player.rotspeed;
}

void cast_rays(t_conf *conf)
{
    // int columnbr = 0;
    double _ang = 0;
    _ang = conf->player.rotangle - (FOV / 2);
    int i = 0;
    conf->wall.line_distance = malloc(sizeof(double) * conf->ray.num_rays);
    conf->ray.rayangle = malloc(sizeof(double) * conf->ray.num_rays);
    while(i < conf->ray.num_rays)
    // while(i < 1)
    {
        // puts("here");
        _ang = normalize_ang(_ang);
        check_intersection(conf, _ang);
        // line(conf,conf->player.py * minimap,
	    // conf->player.px * minimap,
	    // conf->ray.wallhitY * minimap,
	    // conf->ray.wallhitX * minimap, C1);
        // line(conf,conf->player.py ,
	    // conf->player.px ,
	    // conf->ray.wallhitY ,
	    // conf->ray.wallhitX , C1);
        _ang += FOV /conf->ray.num_rays;
        conf->ray.rayangle[i] = _ang;
        conf->wall.line_distance[i] = conf->ray.distance;
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
            j++;
        }
        // printf("\n");
        i++;
    }
    // i = 0;
    // while(i < mapX )
    // {
    //     j = 0;
    //     while(j < mapY)
    //     {
    //         if(map[i][j] == '0' || map[i][j] == 'S')
    //             print_rectangl(conf,i,j,WHITE,1);
    //         j++;
    //     }
    //     i++;
    // }
}
void    ft_draw_line(t_conf *conf)
{
    int x;
    int i = 0;
    int j ;
    // printf("x = %d, y = %d, conf->wall.drawStarty = %f, ")
    //  printf("startx = %d, starty = %d\n",conf->wall.drawStartx, conf->wall.drawStarty);
    while (i < 1)
    {
        j = conf->wall.drawStarty < 0 ? -conf->wall.drawStarty : 0;
        while (j < conf->wall.wallstripheight)
        {
            // printf("kahria1 = %d\n",j);
            // if(conf->ray.washitvert)
                conf->img.addr[((conf->wall.drawStarty + j) * conf->player.width + (conf->wall.drawStartx + i))] = AQUA;
            // else
            //     conf->img.addr[((conf->wall.drawStarty + j) * conf->player.width + (conf->wall.drawStartx + i))] = GRAY;
            j++;
        }
        i++;
    }
}
void    render3d(t_conf *conf)
{
    // double _ang;

    // _ang = conf->player.rotangle + (FOV/ 2);
    conf->wall.playerWallDist = (conf->player.width / 2) / tan(FOV / 2);
        // printf("wallDist = %f\n",conf->wall.playerWallDist);
    conf->wall.wallstripheight = 0.1;
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
        conf->wall.wallstripheight = conf->wall.wallstripheight >= conf->player.height ? conf->player.height : conf->wall.wallstripheight;
        // printf("kahria1 = %f, kharia2 = %f\n",conf->wall.wallstripheight,conf->wall.playerWallDist);
        conf->wall.drawStarty = (conf->player.height / 2) - (conf->wall.wallstripheight / 2);
        
        ft_draw_line(conf);
        // _ang -= FOV/ conf->ray.num_rays;
        conf->wall.drawStartx++;
    }
}
int main_loop(t_conf *conf)
{
    // printf("widht = %d , height = %d \n",conf->player.width,conf->player.height);
    ft_clear(conf);
    cast_rays(conf);
    render3d(conf);
    mapp_print(conf);
    player_print(conf);
    move_to(conf);
    rotate(conf);
    mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->img.img, 0, 0);
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
    init_all(&conf);
    win_init(&conf);
    img_init(&conf);
    cub3d_hook(&conf);
    // mlx_loop(conf.mlx);
    return 0;
}
