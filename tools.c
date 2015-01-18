/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 18:34:04 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 18:41:57 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

void ft_puterror(char *error)
{
	ft_putendl(error);
	exit(0);
}

int gf(double i)
{
	return (floor(i));
}

void protect_from_walls(t_list *pos, char **map)
{
	int tmpx;
	int tmpy;

	tmpx = floor(pos->x);
	tmpy = floor(pos->y);
	if (map[tmpx][tmpy] != '.')
		ft_puterror("Wolf3d : Bad Position set. (in wall)");
	if (tmpx = pos->x)
		pos->x += 0.5;
	if (tmpy = pos->y)
		pos->y += 0.5;
}
