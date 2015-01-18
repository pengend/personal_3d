/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 21:18:42 by pxia              #+#    #+#             */
/*   Updated: 2015/01/12 20:21:22 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_countbloc(const char *s, char c)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		nb++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (nb);
}

char		**get_null_tab(void)
{
	char **tab;

	tab = (char**)malloc(sizeof(char*));
	*tab = ft_strnew(1);
	return (tab);
}

char		**get_tab(const char *s, char c)
{
	char	**tab;
	int		nb;
	int		i;
	int		o;

	nb = ft_countbloc(s, c);
	i = 0;
	tab = (char**)malloc(sizeof(char*) * (nb + 1));
	nb = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		o = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		tab[nb] = ft_strnew(i - o + 1);
		ft_strncpy(tab[nb], s + o, i - o);
		nb++;
	}
	tab[nb] = NULL;
	return (tab);
}

char		**ft_strsplit(const char *s, char c)
{
	if (!s)
		return (get_null_tab());
	else
		return (get_tab(s, c));
}
