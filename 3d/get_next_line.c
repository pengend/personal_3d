/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:18:43 by pxia              #+#    #+#             */
/*   Updated: 2014/11/30 02:17:13 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_readall(int const fd, char **file)
{
	int		ret;
	char	*buff;
	char	*ptr;

	ret = 0;
	if ((buff = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1))) == 0)
		return (0);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		ptr = *file;
		if (ret == -1)
			return (0);
		*file = ft_strnjoin(*file, buff, ret);
		if (*file == 0)
			return (0);
		free(ptr);
		ptr = NULL;
	}
	free(buff);
	buff = NULL;
	return (1);
}

int ft_check(char **file, int *start)
{
	if ((*file)[*start - 1] == '\0')
	{
		free(*file);
		*file = NULL;
		*start = 0;
		return (0);
	}
	return (1);
}

int ft_changefd(char **file, int *tmp, const int fd)
{
	if (*file == NULL)
		return (0);
	if (*tmp != fd)
	{
		free(*file);
		file = NULL;
		return (1);
	}
	else
		return (0);
}

int ft_init(char **file, int *tmp, int *start, int const fd)
{
	if (*file == NULL || ft_changefd(file, tmp, fd))
	{
		*tmp = fd;
		*start = 0;
		*file = ft_strnew(1);
		if (!ft_readall(fd, file))
			return (-1);
	}
	return (0);
}

int get_next_line(int const fd, char **line)
{
	static	char	*file;
	static	int		start;
	static	int		tmp;
	int				i;

	if ((ft_init(&file, &tmp, &start, fd)) == -1)
		return (-1);
	*line = NULL;
	i = 0;
	while (file[start + i] != '\n')
	{
		if (file[start + i] == '\0')
			break ;
		i++;
	}
	*line = (char*)malloc(sizeof(char) * (i + 1));
	ft_strncpy(*line, file + start, i);
	(*line)[i] = '\0';
	start = start + i + 1;
	return (ft_check(&file, &start));
}
