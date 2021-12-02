# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/15 11:51:57 by goliano-          #+#    #+#              #
#    Updated: 2021/12/02 12:24:54 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

LIB_MLX		= libmlx.dylib

SRCS =	./srcs/main.c ./utils/get_next_line.c ./utils/get_next_line_utils.c \
		./libft/ft_split.c ./libft/ft_atoi.c ./srcs/draw_matrix.c \
		./utils/operations.c ./srcs/init_data.c ./utils/check_comma.c \
		./utils/hex_to_dec.c

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Werror -Wextra -fsanitize=address -g3

RM			= rm -rf

INC			= -I includes/ -Imlx

%.o: %.c
	cc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

$(LIB_MLX):		$(MLX_OBJS)
			ar -r $(LIB_MLX) $(MLX_OBJS)
			ranlib $(LIB_MLX)

lib:
		make -C libft

mlx_t:
		make -C mlx

$(NAME):		lib mlx_t $(OBJS)
				$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -fsanitize=address $(CFLAGS)	-o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C libft
		make clean -C mlx

fclean:		clean
			$(RM) $(NAME)
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
