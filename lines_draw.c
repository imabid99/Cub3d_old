/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imabid <imabid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 15:12:08 by imabid            #+#    #+#             */
/*   Updated: 2022/07/28 13:24:58 by imabid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// int x, y, dx, dy, dx1, dy1, px, py, xe, ye, i;

// void line_1(t_conf *conf, float x1, float y1, float x2, float y2, int color)
// {
//     if (dx >= 0)
//     {
//         x = x1;
//         y = y1;
//         xe = x2;
//     }
//     else
//     {
//         x = x2;
//         y = y2;
//         xe = x1;
//     }
//     conf->img.addr[(int)(x * conf->player.width + y)] = color;
//     while (x < xe)
//     {
//         x = x + 1;
//         if (px < 0)
//         {
//             px = px + 2 * dy1;
//         }
//         else
//         {
//             if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
//             {
//                 y = y + 1;
//             }
//             else
//             {
//                 y = y - 1;
//             }
//             px = px + 2 * (dy1 - dx1);
//         }
//         conf->img.addr[(int)(x * conf->player.width + y)] = color;
//     }
// }

// void line_2(t_conf *conf, float x1, float y1, float x2, float y2, int color)
// {

//     if (dy >= 0)
//     {
//         x = x1;
//         y = y1;
//         ye = y2;
//     }
//     else
//     {
//         x = x2;
//         y = y2;
//         ye = y1;
//     }
//     conf->img.addr[(int)(x * conf->player.width + y)] = color;
//     while (y < ye)
//     {
//         y = y + 1;
//         if (py <= 0)
//         {
//             py = py + 2 * dx1;
//         }
//         else
//         {
//             if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
//             {
//                 x = x + 1;
//             }
//             else
//             {
//                 x = x - 1;
//             }
//             py = py + 2 * (dx1 - dy1);
//         }
//         conf->img.addr[(int)(x * conf->player.width + y)] = color;
//     }
// }

// void line(t_conf *conf, float x1, float y1, float x2, float y2, int color)
// {

//     dx = x2 - x1;
//     dy = y2 - y1;

//     i = 0;
//     dx1 = abs(dx);
//     dy1 = abs(dy);

//     px = 2 * dy1 - dx1;
//     py = 2 * dx1 - dy1;

//     if (dy1 <= dx1)
//         line_1(conf, x1, y1, x2, y2, color);
//     else
//         line_2(conf, x1, y1, x2, y2, color);
// } 