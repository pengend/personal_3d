/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_to_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 12:00:38 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 19:16:16 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void put_pixel_to_img(t_img *im, int x, int y, int color)
{
	unsigned int c;

	c = mlx_get_color_value(im->mlx, color);
	im->data[y * im->size_line + im->bpp / 8 * x] = (c & 0xFF);
	im->data[y * im->size_line + im->bpp / 8 * x + 1] = (c & 0xFF00) >> 8;
	im->data[y * im->size_line + im->bpp / 8 * x + 2] = (c & 0xFF0000) >> 16;
}


int switch_color(char case_on_map)
{
	if (case_on_map == 'W')
		return (YELLOW);
	else if (case_on_map == '1')
		return (GREEN);
	else if (case_on_map == '2')
		return (BLUE);
	else if (case_on_map == '3')
		return (RED);
	else if (case_on_map == '4')
		return (WHITE);
}

void get_draw_start_end(int lineheight, t_env *e)
{
	int draw_start;
	int draw_end;
	int i;

	draw_start = -lineheight / 2.0 + HEIGHT / 2.0;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = lineheight / 2.0 + HEIGHT / 2.0;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	i = 0;
	while (i < draw_start)
	{
		put_pixel_to_img(e->i, e->x, i, 0x00CCFF);
		i++;
	}
	while (draw_start < draw_end)
	{
		put_pixel_to_img(e->i, e->x, draw_start, e->color);
		draw_start++;
	}
	while (draw_end < HEIGHT)
	{
		put_pixel_to_img(e->i, e->x, draw_end, 0x000099);
		draw_end++;
	}
}
