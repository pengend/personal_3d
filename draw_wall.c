/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:16:02 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 18:42:37 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void init_step_side(t_calq *clq, t_list ray_direction, t_list ray_position)
{
	if (ray_direction.x < 0)
	{
		clq->step.x = -1;
		clq->side_dist.x = (ray_position.x - clq->map.x) * clq->delta_dist.x;
	}
	else
	{
		clq->step.x = 1;
		clq->side_dist.x = (clq->map.x + 1.0 - ray_position.x) * clq->delta_dist.x;
	}
	if (ray_direction.y < 0)
	{
		clq->step.y = -1;
		clq->side_dist.y = (ray_position.y - clq->map.y) * clq->delta_dist.y;
	}
	else
	{
		clq->step.y = 1;
		clq->side_dist.y = (clq->map.y + 1.0 - ray_position.y) * clq->delta_dist.y;
	}
}

void init_calq(t_calq *clq, t_list ray_direction, t_list ray_position)
{
	clq->map.x = ray_position.x;
	clq->map.y = ray_position.y;
	clq->delta_dist.x = sqrt(1 + (ray_direction.y * ray_direction.y) / (ray_direction.x * ray_direction.x));
	clq->delta_dist.y = sqrt(1 + (ray_direction.x * ray_direction.x) / (ray_direction.y * ray_direction.y));
	clq->indice.hit = 0;
}

int get_wall_color(t_calq clq)
{
	if (clq.indice.side == 1)
	{
		if (clq.step.y == 1)
			return (11);
		else
			return (12);
	}
	else
	{
		if (clq.step.x == 1)
			return (13);
		else
			return (14);
	}
}

void calq_distance_to_wall(t_calq clq, t_env *e, t_list ray_position, t_list ray_direction)
{
	double perpdist;
	int lineheight;

	if (clq.indice.side == 0)
		perpdist = fabs((clq.map.x - ray_position.x + (1 - clq.step.x) / 2.0) / ray_direction.x);
	else
		perpdist = fabs((clq.map.y - ray_position.y + (1 - clq.step.y) / 2.0) / ray_direction.y);
	lineheight = abs(HEIGHT / perpdist);
	e->color = switch_color(e->map[clq.map.x][clq.map.y]);
	e->color *= get_wall_color(clq);
	get_draw_start_end(lineheight, e);
//	ft_putnbr(lineheight);
//	ft_putchar('\n');
}

void ray_cast(t_list ray_position, t_list ray_direction, t_env *e)
{
	t_calq clq;

	init_calq(&(clq), ray_direction, ray_position);
	init_step_side(&(clq), ray_direction, ray_position);
	while (clq.indice.hit == 0)
	{
		if (clq.side_dist.x < clq.side_dist.y)
		{
			clq.side_dist.x += clq.delta_dist.x;
			clq.map.x += clq.step.x;
			clq.indice.side = 0;
		}
		else
		{
			clq.side_dist.y += clq.delta_dist.y;
			clq.map.y += clq.step.y;
			clq.indice.side = 1;
		}
		if (e->map[clq.map.x][clq.map.y] != '.')
			clq.indice.hit = 1;
	}
	calq_distance_to_wall(clq, e, ray_position, ray_direction);
}

void draw_wall(t_env *e)
{
	t_list ray_position;
	t_list ray_direction;
	double cam_x;
	clock_t test;

	test =  clock();
	e->x = 0;
	while (e->x < WIDTH)
	{
		cam_x = 2.0 * e->x / WIDTH - 1;
		ray_position.x = e->pos.x;
		ray_position.y = e->pos.y;
		ray_direction.x = e->dir.x + e->plane.x * cam_x;
		ray_direction.y = e->dir.y + e->plane.y * cam_x;
		ray_cast(ray_position, ray_direction, e);
		(e->x)++;
	}
	e->fps = (clock() - test) / 1.0 / CLOCKS_PER_SEC;
	printf("%.5f\n", 1.0 / e->fps);
	e->rotspeed = e->fps * 15.0;
	e->movement = e->fps * 25.0;
}
