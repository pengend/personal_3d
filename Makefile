#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/31 06:21:31 by pxia              #+#    #+#              #
#    Updated: 2015/01/18 18:41:15 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d
GC = gcc
LIB = -L /usr/X11/lib -lmlx -lXext -lX11 
INC = -I /usr/X11/include/
FLAGS = -Werror -Wall -Wextra
SRC = main.c mlx_hook.c draw_wall.c pixel_to_wall.c keyboard_control.c \
	readmap.c convert_file_to_char.c tools.c

OBJ = $(SRC:.c=.o)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(GC) $(FLAGS) -g -o $@ $^ $(LIB) $(INC) -O3 libft/libft.a

%.o: %.c
	$(GC) -o $@ -c $< $(LIB) $(INC)

clean:
	rm -rf *.o
	rm -rf libft/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a

re: fclean all
