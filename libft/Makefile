#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pxia <pxia@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/04 14:01:38 by pxia              #+#    #+#              #
#    Updated: 2015/01/18 17:54:07 by pxia             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a
GC = gcc -Wall -Wextra -Werror
SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memccpy.c ft_memalloc.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_memdel.c ft_nbrlen.c ft_strndup.c ft_reverse_str.c ft_puttab.c \
	ft_intchr.c ft_putnbr.c ft_strnjoin.c get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

%.o: %.c
	$(GC) -o $@ -c $<

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
