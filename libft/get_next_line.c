/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:18:43 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 17:54:23 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	}
	free(buff);
	buff = NULL;
	return (1);
}

int ft_check(char **file, int start)
{
	if ((*file)[start - 1] == '\0')
	{
		free(*file);
		*file = NULL;
		return (0);
	}
	return (1);
}

int get_next_line(int const fd, char **line)
{
	static	char	*file;
	static	int		start;
	int				i;

	if (file == NULL)
	{
		start = 0;
		file = ft_strnew(1);
		if (!ft_readall(fd, &file))
			return (-1);
	}
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
	return (ft_check(&file, start));
}
