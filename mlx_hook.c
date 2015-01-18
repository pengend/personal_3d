/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:41:59 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 18:49:51 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void wolf_image_to_window(t_env *e)
{
	ft_bzero(e->i->data, HEIGHT * e->i->size_line + e->i->bpp / 8 * WIDTH);
	draw_wall(e);
	mlx_put_image_to_window(e->mlx, e->win, e->i->img, 0, 0);	
}

int loop_hook(t_env *e)
{
	if (e->turn[TURN_LEFT])
		key_control(LEFT, e);
	if (e->turn[TURN_RIGHT])
		key_control(RIGHT, e);
	if (e->forbak[FORWARD])
		key_control(UP, e);
	if (e->forbak[BACK])
		key_control(DOWN, e);
	return (0);
}

int expose_hook(t_env *e)
{
	wolf_image_to_window(e);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int keypress_hook(int keycode, t_env *e)
{
	if (keycode == LEFT)
		e->turn[TURN_LEFT] = 1;
	if (keycode == RIGHT)
		e->turn[TURN_RIGHT] = 1;
	if (keycode == UP)
		e->forbak[FORWARD] = 1;
	if (keycode == DOWN)
		e->forbak[BACK] = 1;
	return (0);
}

int keyrelease_hook(int keycode, t_env *e)
{
	if (keycode == LEFT)
		e->turn[TURN_LEFT] = 0;
	if (keycode == RIGHT)
		e->turn[TURN_RIGHT] = 0;
	if (keycode == UP)
		e->forbak[FORWARD] = 0;
	if (keycode == DOWN)
		e->forbak[BACK] = 0;
	return (0);
}
