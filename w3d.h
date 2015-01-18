/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/16 15:34:08 by pxia              #+#    #+#             */
/*   Updated: 2015/01/18 18:40:45 by pxia             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W3D_H

# define W3D_H
# define WIDTH	800
# define HEIGHT	500
# define YELLOW	0xFFFF00
# define GREEN	0x33FF00
# define BLUE	0x3399FF
# define RED	0xCC0000
# define WHITE	0xFFFFFF
# define ROT	M_PI / 180
# define MVT	0.1
# define LEFT	65361
# define RIGHT	65363
# define UP		65362
# define DOWN	65364
# define TURN_LEFT	0
# define TURN_RIGHT	1
# define FORWARD	1
# define BACK		0

# include "libft/libft.h"
# include <math.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <dirent.h>
# include <mlx.h>
# include <math.h>
# include <X11/Xlib.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct timeval timeval;

typedef struct	s_integ
{
	int			x;
	int			y;
}				t_integ;

typedef struct	s_indice
{
	int			hit;
	int			side;
}				t_indice;

typedef struct	s_list
{
	double		x;
	double		y;
}				t_list;

typedef struct	s_img
{
	void		*mlx;
	void		*img;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_calq
{
	t_integ		map;
	t_integ		step;
	t_list		side_dist;
	t_list		delta_dist;
	t_indice	indice;
}				t_calq;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	t_list		pos;
	t_list		dir;
	t_list		plane;
	t_img		*i;
	int			color;
	int			x;
	timeval		ct;
	timeval		ot;
	double		fps;
	double		rotspeed;
	double		movement;
	int			turn[2];
	int			forbak[2];
	char		**map;
}				t_env;

int expose_hook(t_env *e);
int key_hook(int keycode, t_env *e);
int loop_hook(t_env *e);
int keypress_hook(int keycode, t_env *e);
int keyrelease_hook(int keycode, t_env *e);
void draw_wall(t_env *e);
void get_draw_start_end(int lineheight, t_env *e);
void wolf_image_to_window(t_env *e);
int switch_color(char case_on_map);
void put_pixel_to_img(t_img *im, int x, int y, int color);
char **readmap(char *pathname);
char **read_map_dir(int c);
void key_rotate(int command, t_env *e);
void key_control(int command, t_env *e);
int keypress_hook(int keycode, t_env *e);
int gf(double i);
void protect_from_walls(t_list *pos, char **map);
void ft_puterror(char *error);

#endif
