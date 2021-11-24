# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 11:51:57 by goliano-          #+#    #+#              #
#    Updated: 2021/11/24 11:54:08 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	./srcs/main.c ./utils/get_next_line.c ./utils/get_next_line_utils.c \
		./utils/ft_split.c ./utils/ft_atoi.c ./srcs/draw_matrix.c \
		./srcs/init_mlx.c
CC = gcc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

RM	= rm -f

NAME = fdf

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS)	-o $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
