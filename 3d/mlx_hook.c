/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 22:47:36 by pxia              #+#    #+#             */
/*   Updated: 2015/01/17 22:55:57 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

int expose_hook(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->i->img, 0, 0);
	return (0);
}

int key_hook(int keycode, t_env *e)
{
	if (keycode == 65307)
		exit(0);
	e = e;
	return (0);
}
