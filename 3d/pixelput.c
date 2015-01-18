/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixelput.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 22:40:35 by pxia              #+#    #+#             */
/*   Updated: 2015/01/17 23:06:05 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void put_pixel_to_img(t_img *im, int x, int y, unsigned int cl)
{
	unsigned int color;

	color = mlx_get_color_value(im->mlx, cl);
	im->data[y * im->size_line + im->bpp / 8 * x] = (color & 0xFF);
	im->data[y * im->size_line + im->bpp / 8 * x + 1] = (color & 0xFF00) >> 8;
	im->data[y * im->size_line + im->bpp / 8 * x + 2] =
		(color & 0xFF0000) >> 16;
}

void ppixel1(t_cor *p1, int i, int j, t_img *im)
{
	put_pixel_to_img(im, p1->x + i, p1->y + j, 0xFFFFFF);
}

void ppixel2(t_cor *p1, int i, int j, t_img *im)
{
	put_pixel_to_img(im, p1->x - i, p1->y - j, 0xFFFFFF);
}
