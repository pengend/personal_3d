/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 16:47:44 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 19:51:33 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void img_init(t_img *i)
{
	int w = WIDTH;
	int h = HEIGHT;

	ft_putstr("sada");
    i->img = mlx_xpm_file_to_image(i->mlx, "bluestone.bmp", &w, &h);
	ft_putstr("sada");
}

int main()
{
	t_env e;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 500, 500, "test");
    e.i = (t_img*)malloc(sizeof(t_img));
    e.i->mlx = e.mlx;
	img_init(e.i);
	ft_putstr("sada");
	mlx_put_image_to_window(e.mlx, e.win, e.i->img, 0, 0);
	mlx_loop(e.mlx);
	return (0);
}
