/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 15:32:47 by pxia              #+#    #+#             */
/*   Updated: 2015/01/17 23:13:12 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

void rotationx(t_cor *p, double rad)
{
	double tmp1;
	double tmp2;
	double tmp3;

	tmp1 = c->x;
	tmp2 = c->y;
	tmp3 = c->z;
	c->x = tmp1;
	c->y = tmp2 * cos(rad) - tmp3 * sin(rad);
	c->z = tmp2 * sin(rad) + tmp3 * cos(rad);
}

void rotationy(t_cor *p, double rad)
{
	double tmp1;
	double tmp2;
	double tmp3;

	tmp1 = c->x;
	tmp2 = c->y;
	tmp3 = c->z;
	c->x = tmp1 * cos(rad) + tmp3 * sin(rad);
	c->y = tmp2;
	c->z = tmp1 * sin(rad) * (-1) + tmp3 * cos(rad);
}

void rotationz(t_cor *p, double rad)
{
	double tmp1;
	double tmp2;
	double tmp3;

	tmp1 = c->x;
	tmp2 = c->y;
	tmp3 = c->z;
	c->x = tmp1 * cos(rad) - tmp2 * sin(rad);
	c->y = tmp1 * sin(rad) + tmp2 * cos(rad);
	c->z = tmp3;
}
