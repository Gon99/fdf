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

LIB_MLX		= libmlx.a

SRCS 		= ./srcs/main.c ./utils/get_next_line.c ./utils/get_next_line_utils.c ./Libft/ft_split.c ./Libft/ft_atoi.c ./srcs/draw_matrix.c ./utils/operations.c ./srcs/init_data.c ./utils/check_comma.c ./utils/hex_to_dec.c

MLX_SRC 	= mlx_linux/mlx_init.c mlx_linux/mlx_new_window.c \
		mlx_linux/mlx_loop.c

OBJS		= $(SRCS:.c=.o)

MLX_OBJS	= $(MLX_SRCS:.c=.o)

MLX_OBJS_M	= $(MLX_OBJS:.m=.o)

FLAGS		= -Wall -Werror -Wextra -fsanitize=address -g3

RM			= rm -rf

INC			= -I includes/ -Imlx_linux

%.o: %.c
	cc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

$(LIB_MLX):		$(MLX_OBJS)
			ar -r $(LIB_MLX) $(MLX_OBJS)
			ranlib $(LIB_MLX)

lib:
		make -C Libft

mlx_t:
		make -C mlx_linux

$(NAME): lib mlx_t $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -L/usr/lib -Imlx_linux -fsanitize=address Libft/libft.a mlx_linux/$(LIB_MLX) -o $(NAME) -lXext -lX11 -lm -lz

clean:
		$(RM) $(OBJS)
		make clean -C Libft
		make clean -C mlx_linux

fclean:		clean
			$(RM) $(NAME)
			make fclean -C Libft

re:			fclean all

.PHONY:		all clean fclean re
