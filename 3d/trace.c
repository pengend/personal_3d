/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 22:26:29 by pxia              #+#    #+#             */
/*   Updated: 2015/01/17 23:04:57 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void ft_trace_d(t_cor *p1, t_cor *p2, t_img *im, int c)
{
	int i;

	i = 0;
	if (c == 1)
		while (i <= ABS(p2->y - p1->y))
		{
			(p2->y > p1->y) ? ppixel1(p1, 0, i, im) : ppixel2(p1, 0, i, im);
			i++;
		}
	else
	{
		while (i <= ABS(p2->x - p1->x))
		{
			(p2->x > p1->x) ? ppixel1(p1, i, 0, im) : ppixel2(p1, i, 0, im);
			i++;
		}
	}
}

void ft_trace1(double a, t_cor *p1, t_cor *p2, t_img *im)
{
	double tmp;
	double b;
	int ent;
	int i;
	int j;

	i = 1;
	j = 0;
	tmp = 0;
	while (i <= ABS(p2->x - p1->x))
	{
		b = i * ABS(a) - tmp;
		ent = (b - floor(b) >= floor(b) + 1 - b) ?
			floor(b) + 1 : floor(b);
		tmp += ent;
		while (ent--)
		{
			(p2->x > p1->x) ? ppixel1(p1, i, j, im) : ppixel2(p1, i, j, im);
			j += (a < 0) ? -1 : 1;
		}
		i++;
	}
}

void ft_trace0(double a, t_cor *p1, t_cor *p2, t_img *im)
{
	int i;
	int j;
	int max;
	double tmp;

	i = 1;
	j = 0;
	max = ABS(p1->x - p2->x);
	tmp = 0;
	while (i <= max)
	{
		while (i * ABS(a) - tmp < 1 && i <= max)
		{
			(p2->x > p1->x) ? ppixel1(p1, i, j, im) : ppixel2(p1, i, j, im);
			i++;
		}
		tmp = floor(i * ABS(a));
		j += (a < 0) ? -1 : 1;
	}
}

void ft_trace_line(t_cor *p1, t_cor *p2, t_img *im)
{
	double a;

	a = (p2->y - p1->y) / 1.0 / (p2->x - p1->x);
	if (ABS(p2->x - p1->x) == 0)
		ft_trace_d(p1, p2, im, 1);
	else if (ABS(p2->y - p1->y) == 0)
		ft_trace_d(p1, p2, im, 0);
	else
	{
		if (ABS(a) > 1)
			ft_trace1(a, p1, p2, im);
		else
			ft_trace0(a, p1, p2, im);
	}
}
