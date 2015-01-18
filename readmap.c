/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 16:49:45 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 18:05:06 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

char **read_map_dir(int c)
{
	DIR *dir;
	struct dirent *dp;
	char *path;
	int i;

	i = 0;
	dir = opendir("map");
	while (i < c)
	{
		dp = readdir(dir);
		i++;
	}
	path = ft_strjoin("map/", dp->d_name);
	return (readmap(path));
}
/*
int main()
{
	t_env e;

	e.map = read_map_dir(3);
	ft_puttab(e.map);
}
*/
