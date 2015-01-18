/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ras.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 22:46:21 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 00:16:22 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAS_H
# define RAS_H
# define ABS(x) ((x) < 0 ? - (x) : (x))
# define W	2000
# define H	1000

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct		s_img
{
	void			*mlx;
	void			*img;
	char			*data;
	int				bpp;
	int				size_line;
	int				endian;
	unsigned int	color;
}					t_img;

typedef struct		s_cor
{
	int				x;
	int				y;
	int				z;
	struct s_cor	*t_cor;
}					t_cor;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			*i;
}					t_env;

void				ppixel1(t_cor *p1, int i, int j, t_img *im);
void				ppixel2(t_cor *p1, int i, int j, t_img *im);
int					expose_hook(t_env *e);
int					key_hook(int keycode, t_env *e);
void				ft_trace_line(t_cor *p1, t_cor *p2, t_img *im);

#endif
