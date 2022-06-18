/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:11:34 by imabid            #+#    #+#             */
/*   Updated: 2022/06/18 19:01:09 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <float.h>
void print_rectangl(t_conf *conf, int y, int x, int color, int line)
{
    int i;
    int j;

    x *= TILE_SIZE;
    y *= TILE_SIZE;
    i = 0;
    while (i < TILE_SIZE - line)
    {
        j = 0;
        while (j < TILE_SIZE - line)
        {
            conf->img.addr[(y + j) * WIDTH + x + i] = color;
            j++;
        }
        i++;
    }
}

float playerX = 100;
float playerY = 100;
int mapX = 16, mapY = 16, mapS = 64;

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
        {'1','1','1','1','1','1','1','1','1','1','1','1','1','1','1','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','S','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','1','1','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','1','1','1','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','1','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
        {'1','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'},
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

double disbtp(x1,y1,x2,y2)
{
    return (sqrt((x2-x1) * (x2-x1) + (y2-y1)* (y2-y1)));
}
void move_to(t_conf *conf)
{
    
    float pdx = cos(conf->player.rotangle - PI / 2);
    float pdy = -sin(conf->player.rotangle - PI / 2);
    if (conf->player.to_a == 1)
    {
        if(map[(int)((conf->player.py - (sin(conf->player.rotangle + PI / 2) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (cos(conf->player.rotangle + PI / 2) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
        // conf->player.px += cos(conf->player.rotangle) * conf->player.movespeed;
        // conf->player.py -= sin(conf->player.rotangle) * conf->player.movespeed;   
        conf->player.px += cos(conf->player.rotangle + PI / 2) * conf->player.movespeed;
        conf->player.py -= sin(conf->player.rotangle + PI / 2) * conf->player.movespeed;
        }
    }
    if (conf->player.to_d == 1)
    {
        if(map[(int)((conf->player.py + (pdy * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (pdx * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
        // conf->player.px -= cos(conf->player.rotangle) * conf->player.movespeed;
        // conf->player.py += sin(conf->player.rotangle) * conf->player.movespeed;
        conf->player.px += pdx * conf->player.movespeed;
        conf->player.py += pdy * conf->player.movespeed;
            
        }
    }
    if (conf->player.to_w == 1)
    {
        if (map[(int)((conf->player.py - (sin(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px + (cos(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
            // conf->player.px += pdx * conf->player.movespeed;
            // conf->player.py += pdy * conf->player.movespeed;
            conf->player.px += cos(conf->player.rotangle) * conf->player.movespeed;
            conf->player.py -= sin(conf->player.rotangle) * conf->player.movespeed; 
            // printf("x position: %f, y position: %f,map = %c\n", conf->player.px / 64, conf->player.py / 64,
            //        map[(int)((conf->player.py / 64))][(int)((conf->player.px / 64))]);
        }
    }
    if (conf->player.to_s == 1)
    {
        if(map[(int)((conf->player.py + (sin(conf->player.rotangle) * conf->player.movespeed)) / TILE_SIZE)][(int)((conf->player.px - (cos(conf->player.rotangle ) * conf->player.movespeed)) / TILE_SIZE)] != '1')
        {
        // conf->player.px += cos(conf->player.rotangle + PI / 2) * conf->player.movespeed;
        // conf->player.py -= sin(conf->player.rotangle + PI / 2) * conf->player.movespeed;
        conf->player.px -= cos(conf->player.rotangle) * conf->player.movespeed;
        conf->player.py += sin(conf->player.rotangle) * conf->player.movespeed;
            
        }
    }
}
char    has_wall(double x,double y)
{
    if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT) {
            return '1';
        }
        int mapindexX = floor(x / TILE_SIZE);
        int mapindexY = floor(y / TILE_SIZE);
        // printf("%c\n",map[mapindexY][mapindexX]);
        return map[mapindexY][mapindexX];
}
void    rayfacing(t_conf *conf)
{
    conf->ray.facingdown = conf->ray.rayangle > 0 && conf->ray.rayangle < PI;
    conf->ray.facingup = !conf->ray.facingdown;
    conf->ray.facingright = conf->ray.rayangle < 0.5 * PI || conf->ray.rayangle > 1.5 * PI;
    conf->ray.facingleft = !conf->ray.facingright;
    // printf("%d\n",conf->ray.facingright);  
}
double    hoz_intersection(t_conf *conf)
{
    //   bach nl9aw y_coordinate dyal closest horix grid intersection
    conf->ray.yintercept = floor(conf->player.py / TILE_SIZE) * TILE_SIZE;
    conf->ray.yintercept += conf->ray.facingdown ? TILE_SIZE : 0; 
    // bach nl9aw x_coordinate dyal closest horix grid intersection
    conf->ray.xintercept = conf->player.px + (conf->ray.yintercept - conf->player.py) / tan(conf->ray.rayangle);
    // printf("--%f---%f--\n",floor(conf->player.py/TILE_SIZE),conf->player.py / TILE_SIZE);

    // n7sbo increment dyal xstep o ystep
    conf->ray.ystep = TILE_SIZE;
    conf->ray.ystep *= conf->ray.facingup ? -1 : 1;
    
    conf->ray.xstep = TILE_SIZE / tan(conf->ray.rayangle); 
    conf->ray.xstep *= (conf->ray.facingleft && conf->ray.xstep > 0) ? -1 : 1;
    conf->ray.xstep *= (conf->ray.facingright && conf->ray.xstep < 0) ? -1 : 1;

    conf->ray.nexthox = conf->ray.xintercept;
    conf->ray.nexthoy = conf->ray.yintercept;
    if(conf->ray.facingup)
        conf->ray.nexthoy--; 
        // incrementiw xstep o ystep tanl9aw wall
    while(conf->ray.nexthox >= 0 && conf->ray.nexthox <= WIDTH && conf->ray.nexthoy >= 0
        && conf->ray.nexthoy <= HEIGHT)
    {
            // puts("hahaha");
        if(has_wall(conf->ray.nexthox,conf->ray.nexthoy) == '1') 
        {
             
            conf->ray.foundhorwallhit = 1;
            conf->ray.horwallhitx = conf->ray.nexthox;
            conf->ray.horwallhity = conf->ray.nexthoy;
        //     line(conf,conf->player.py,
	    // conf->player.px,
	    // (conf->ray.horwallhity) ,
	    // (conf->ray.horwallhitx), BLACK);
            break;
        }
        else{
            conf->ray.nexthox += conf->ray.xstep;
            conf->ray.nexthoy += conf->ray.ystep;
        }
    }
    if(conf->ray.foundhorwallhit)
    //we return distance between two poins
        return(disbtp(conf->player.px,conf->player.py,conf->ray.horwallhitx,conf->ray.horwallhity));
    return (DBL_MAX);
}
double   ver_intersection(t_conf *conf)
{
    //   // // bach nl9aw x_coordinate dyal closest vert grid intersection
    // conf->ray.xintercept = floor(conf->player.px / TILE_SIZE) * TILE_SIZE;
    // conf->ray.xintercept += conf->ray.facingright ? TILE_SIZE : 0; 
    // // bach nl9aw y_coordinate dyal closest ver grid intersection
    // conf->ray.yintercept = conf->player.py + (conf->ray.xintercept - conf->player.px) * tan(conf->ray.rayangle);
    // // printf("--%f---%f--\n",floor(conf->player.py/TILE_SIZE),conf->player.py / TILE_SIZE);

    // // n7sbo increment dyal xstep o ystep
    // conf->ray.xstep = TILE_SIZE;
    // conf->ray.xstep *= conf->ray.facingleft ? -1 : 1;
    
    // conf->ray.ystep = TILE_SIZE * tan(conf->ray.rayangle); 
    // conf->ray.ystep *= (conf->ray.facingup && conf->ray.ystep > 0) ? -1 : 1;
    // conf->ray.ystep *= (conf->ray.facingdown && conf->ray.ystep < 0) ? -1 : 1;

    // conf->ray.nextverx = conf->ray.xintercept;
    // conf->ray.nextvery = conf->ray.yintercept;
    // if(conf->ray.facingleft)
    //     conf->ray.nextverx--;
    //     // incrementiw xstep o ystep tanl9aw wall
    // while(conf->ray.nextverx >= 0 && conf->ray.nextverx <= WIDTH && conf->ray.nextvery >= 0
    //     && conf->ray.nextvery <= HEIGHT)
    // {
    //         // puts("hahaha");
    //     if(has_wall(conf->ray.nextverx,conf->ray.nextvery) == '1') 
    //     {
             
    //         conf->ray.foundverwallhit = 1;
    //         conf->ray.verwallhitx = conf->ray.nextverx;
    //         conf->ray.verwallhity = conf->ray.nextvery;
    //      line(conf,conf->player.py,
	//     conf->player.px,
	//     conf->ray.verwallhitx ,
	//     conf->ray.verwallhity, BLACK);
    //         break;
    //     }
    //     else{
    //         conf->ray.nextverx += conf->ray.xstep;
    //         conf->ray.nextvery += conf->ray.ystep;
    //     }
    // }
     //   bach nl9aw x_coordinate dyal closest ver grid intersection
    conf->ray.xintercept = floor(conf->player.px / TILE_SIZE) * TILE_SIZE;
    conf->ray.xintercept += conf->ray.facingright ? TILE_SIZE : 0; 
    // bach nl9aw y_coordinate dyal closest ver grid intersection
    conf->ray.yintercept = conf->player.py + (conf->ray.xintercept - conf->player.px) * tan(conf->ray.rayangle);
    // printf("--%f---%f--\n",floor(conf->player.py/TILE_SIZE),conf->player.py / TILE_SIZE);

    // n7sbo increment dyal xstep o ystep
    conf->ray.xstep = TILE_SIZE;
    conf->ray.xstep *= conf->ray.facingleft ? -1 : 1;
    
    conf->ray.ystep = TILE_SIZE * tan(conf->ray.rayangle); 
    conf->ray.ystep *= (conf->ray.facingup && conf->ray.ystep > 0) ? -1 : 1;
    conf->ray.ystep *= (conf->ray.facingdown && conf->ray.ystep < 0) ? -1 : 1;

    conf->ray.nextverx = conf->ray.xintercept;
    conf->ray.nextvery = conf->ray.yintercept;
    if(conf->ray.facingleft)
        conf->ray.nextverx--; 
        // incrementiw xstep o ystep tanl9aw wall
    while(conf->ray.nextverx >= 0 && conf->ray.nextverx <= WIDTH && conf->ray.nextvery >= 0
        && conf->ray.nextverx <= HEIGHT)
    {
            // puts("hahaha");
        if(has_wall(conf->ray.nextverx,conf->ray.nextvery) == '1') 
        {
             
            conf->ray.foundverwallhit = 1;
            conf->ray.verwallhitx = conf->ray.nextverx;
            conf->ray.verwallhity = conf->ray.nextvery;
        //     line(conf,conf->player.py,
	    // conf->player.px,
	    // (conf->ray.verwallhity) ,
	    // (conf->ray.verwallhitx), C1);
            break;
        }
        else{
            conf->ray.nextverx += conf->ray.xstep;
            conf->ray.nextvery += conf->ray.ystep;
        }
    }
    if(conf->ray.foundverwallhit)
    //we return distance between two poins
        return(disbtp(conf->player.px,conf->player.py,conf->ray.verwallhitx,conf->ray.verwallhity));
    return (DBL_MAX);
}
void    check_intersection(t_conf *conf)
{
    init_all2(conf);
    rayfacing(conf);
    conf->ray.hordist = hoz_intersection(conf);
    // hoz_intersection(conf);
    conf->ray.verdist = ver_intersection(conf);
    // ver_intersection(conf);
    // hna kanstori smallest of the distancce
    conf->ray.wallhitX = (conf->ray.hordist < conf->ray.verdist) ? conf->ray.horwallhitx : conf->ray.verwallhitx;
    conf->ray.wallhitY = (conf->ray.hordist < conf->ray.verdist) ? conf->ray.horwallhity : conf->ray.verwallhity;
    conf->ray.distance = (conf->ray.hordist < conf->ray.verdist) ? conf->ray.hordist : conf->ray.verdist;
    conf->ray.washitvert = conf->ray.verdist < conf->ray.hordist;
    // n7asbo both horz and ver onchofo chkon li 9tab
     
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
    // while(conf->ray.nexthox >= 0 && conf->ray.nexthox <= WIDTH && conf->ray.nexthoy >= 0
    //     && conf->ray.nexthoy <= HEIGHT)
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
        conf->player.rotangle += conf->player.rotspeed;
    if (conf->player.to_back == 1)
        conf->player.rotangle -= conf->player.rotspeed;
}

void cast_rays(t_conf *conf)
{
    int columnbr = 0;
    conf->ray.rayangle = conf->player.rotangle - (conf->ray.fov / 2);
    int i = 0;
    // while(i < conf->ray.num_rays)
    while(i < 1)
    {
        conf->ray.rayangle = normalize_ang(conf->ray.rayangle);
        check_intersection(conf);
        line(conf,conf->player.py,
	    conf->player.px,
	    conf->ray.wallhitY ,
	    conf->ray.wallhitX, C1);
        conf->ray.rayangle += conf->ray.fov /conf->ray.num_rays;
        i++;
    }
    
}
void ft_get_playerPosition(t_player *player)
{
    int i = 0;
    int j;
    while (i < mapY)
    {
        j = 0;
        while (j < mapX)
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

    //         conf->img.addr[(i) * WIDTH + (j)] = GRAY;
    //         j++;
    //     }
    //     i++;
    // }

    while(i < mapY)
    {
        j = 0;
        while(j < mapX)
        {
            // printf("%c",map[i][j]);
            if(map[i][j] == '1')
                print_rectangl(conf,i,j,GRAY,1);
            else if(map[i][j] == '0' || map[i][j] == 'S')
                print_rectangl(conf,i,j,WHITE,1);
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

int main_loop(t_conf *conf)
{
    ft_clear(conf);
    mapp_print(conf);
    cast_rays(conf);
    player_print(conf);
    move_to(conf);
    rotate(conf);
    mlx_put_image_to_window(conf->mlx, conf->mlx_win, conf->img.img, 0, 0);
    return 0;
}
void cub3d_hook(t_conf *conf)
{
    mlx_clear_window(conf->mlx, conf->mlx_win);
    // ft_clear(conf);
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
    // int i = 0;
    // int j = 0;
    // printf("map[0] %c\n",map[5][3]);
    init_all(&conf);
    cub3d_hook(&conf);
    mlx_loop(conf.mlx);
    return 0;
}
