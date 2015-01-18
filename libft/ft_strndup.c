/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 17:09:58 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 14:59:42 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strndup(char *str, size_t n)
{
	char*tmp;

	if ((tmp = (char*)malloc(sizeof(char) * n + 1)) == 0)
		return (tmp);
	ft_strncpy(tmp, str, n);
	return (tmp);
}
