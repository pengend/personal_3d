/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file_to_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 17:18:26 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 17:58:00 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "w3d.h"

int ft_nb_line(char *filename)
{
	int fd;
	char *line;
	int i;

	i = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		free(line);
		i++;
	}
	close(fd);
	return (i);
}

char **readmap(char *pathname)
{
	int fd;
	int len;
	int i;
	char **map;
	char *line;

	len = ft_nb_line(pathname);
	map = (char**)malloc(sizeof(char*) * len + 1);
	fd = open(pathname, O_RDONLY);
	i = 0;
	while (i < len)
	{
		get_next_line(fd, &line);
		map[i] = ft_strdup(line);
		free(line);
		line = NULL;
		i++;
	}
	map[i] = NULL;
	return (map);
}
