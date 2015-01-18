/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:31:58 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 18:58:35 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void img_init(t_img *i)
{
	i->img = mlx_new_image(i->mlx, WIDTH, HEIGHT);
	i->data = mlx_get_data_addr(i->img, &(i->bpp), &(i->size_line), &(i->endian));
}

void init_start(t_env *e)
{
	e->pos.x = 1;
	e->pos.y = 1;
	e->dir.x = -1;
	e->dir.y = 0;
	e->plane.x = 0;
	e->plane.y = 0.66;
	if ((e->mlx = mlx_init()) == NULL)
		exit(0);
	e->win = mlx_new_window(e->mlx, WIDTH, HEIGHT, "wolf3d");
	e->i = (t_img*)malloc(sizeof(t_img));
	e->i->mlx = e->mlx;
	img_init(e->i);
	e->turn[0] = 0;
	e->turn[1] = 0;
	e->forbak[0] = 0;
	e->forbak[1] = 0;
}

int main()
{
	t_env e;

	init_start(&e);
	e.map = read_map_dir(3);
	protect_from_walls(&(e.pos), e.map);
	draw_wall(&e);
	mlx_put_image_to_window(e.mlx, e.win, e.i->img, 0, 0);	
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_hook(e.win, KeyPress, KeyPressMask, keypress_hook, &e);
	mlx_hook(e.win, KeyRelease, KeyReleaseMask, keyrelease_hook, &e);
	mlx_loop_hook(e.mlx, loop_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
