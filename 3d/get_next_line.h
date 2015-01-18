/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 15:31:50 by pxia              #+#    #+#             */
/*   Updated: 2015/01/17 23:31:41 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 100000

# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include "libft/libft.h"

int					get_next_line(int const fd, char **line);

#endif
