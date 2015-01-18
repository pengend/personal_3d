/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 22:35:04 by pxia              #+#    #+#             */
/*   Updated: 2015/01/17 23:32:15 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void init_mlx_tools(t_env *e)
{
	e->win = mlx_new_window(e->mlx, W, H, "WOLF RAS");
	e->i = (t_img*)malloc(sizeof(t_img));
	e->i->mlx = e->mlx;
	e->i->img = mlx_new_image(e->mlx, W, H);
	e->i->data = mlx_get_data_addr(e->i->img, &(e->i->bpp),
								&(e->i->size_line), &(e->i->endian));
}

int main()
{
	t_env e;
	int fd;
	char *line;
	t_cor *figure;

	fd = open("doc.txt", O_RDONLY);
	if ((e.mlx = mlx_init()) == NULL)
		return (0);
	get_next_line(fd, &line);
	ft_putendl(line);
	init_mlx_tools(&e);
	mlx_expose_hook(e.win, expose_hook, &e);
	mlx_key_hook(e.win, key_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}
