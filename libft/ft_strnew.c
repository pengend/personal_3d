/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:18:23 by pxia              #+#    #+#             */
/*   Updated: 2014/11/05 18:21:45 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnew(size_t size)
{
	char *s;

	s = (char*)malloc(sizeof(char) * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
