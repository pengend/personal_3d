/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 13:08:07 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 18:47:38 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void key_rotate(int command, t_env *e)
{
	double tmp_dx;
	double tmp_px;

	tmp_dx = e->dir.x;
	tmp_px = e->plane.x;
	if (command == RIGHT)
	{
		e->dir.x = e->dir.x * cos(-e->rotspeed) - e->dir.y * sin(-e->rotspeed);
		e->dir.y = tmp_dx * sin(-e->rotspeed) + e->dir.y * cos(-e->rotspeed);
		e->plane.x = e->plane.x * cos(-e->rotspeed) - e->plane.y * sin(-e->rotspeed);
		e->plane.y = tmp_px * sin(-e->rotspeed) + e->plane.y * cos(-e->rotspeed);
	}
	else if (command == LEFT)
	{
		e->dir.x = e->dir.x * cos(e->rotspeed) - e->dir.y * sin(e->rotspeed);
		e->dir.y = tmp_dx * sin(e->rotspeed) + e->dir.y * cos(e->rotspeed);
		e->plane.x = e->plane.x * cos(e->rotspeed) - e->plane.y * sin(e->rotspeed);
		e->plane.y = tmp_px * sin(e->rotspeed) + e->plane.y * cos(e->rotspeed);		
	}
}

void key_movement(int command, t_env *e)
{
	if (command == UP)
	{
		if ((e->map[gf(e->pos.x + e->dir.x * e->movement * 2)][gf(e->pos.y)]) == '.')
			e->pos.x += e->dir.x * e->movement;
		if ((e->map[gf(e->pos.x)][gf(e->pos.y + e->dir.y * e->movement * 2)]) == '.')
			e->pos.y += e->dir.y * e->movement;
	}
	else if (command == DOWN)
	{
		if ((e->map[gf(e->pos.x - e->dir.x * e->movement * 2)][gf(e->pos.y)]) == '.')
			e->pos.x -= e->dir.x * e->movement;
		if ((e->map[gf(e->pos.x)][gf(e->pos.y - e->dir.y * e->movement * 2)]) == '.')
			e->pos.y -= e->dir.y * e->movement;
	}
}

void key_control(int command, t_env *e)
{
	if (command == LEFT || command == RIGHT)
		key_rotate(command, e);
	else if (command == UP || command == DOWN)
		key_movement(command, e);
	wolf_image_to_window(e);
}
