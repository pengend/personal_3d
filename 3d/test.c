/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 23:03:32 by pxia              #+#    #+#             */
/*   Updated: 2015/01/17 23:04:44 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int main()
{
	double a;
	int b = 3;
	int c = 4;

	a = b / 1.0 / c;
	printf("%.4f", a);
}
