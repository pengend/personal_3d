#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 18:22:48 by pxia              #+#    #+#              #
#    Updated: 2015/01/17 23:30:13 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf
GC = gcc -Wall -Wextra -Werror -g
SRC = main.c trace.c pixelput.c mlx_hook.c get_next_line.c

XLIB = -L /usr/X11/lib -lmlx -lXext -lX11 -I /usr/X11/include/

OBJ = $(SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(GC) -o $@ $^ $(XLIB) libft/libft.a

%.o: %.c
	$(GC) -o $@ -c $< $(XLIB)

clean:
	rm -rf *.o
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)
	rm -f libft/libft.a

re: fclean all
