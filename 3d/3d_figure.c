/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_figure.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 23:32:37 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 20:03:01 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ras.h"

t_list *get_values(int const fd)
{
	char *line;

	line = 
}

void *get_figure_list(int const fd, t_cor *figure)
{
	t_cor *figure;
	t_cor *tmp;

	tmp = figure;
	figure = (t_cor*)malloc(sizeof(t_cor));
	figure->start = get_values(fd);
	figure->p1 = get_values(fd);
	figure->p2 = get_values(fd);
	figure->p3 = get_values(fd);
}

t_cor *get_asked_figure(char *figure_name)
{
	int fd;
	int i;
	char *line;
	t_cor *figure;

	fd = open("doc.txt", O_RDONLY);
	i = get_next_line(fd, &line);
	while (i != 0 && ft_strcmp(line, figure_name))
	{
		i = get_next_line(fd, &line);
		free(line);
	}
	
	return (figure);
}

int main()
{
	get_asked_figure("square:");
}
