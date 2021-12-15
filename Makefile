# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: goliano- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 12:07:52 by goliano-          #+#    #+#              #
#    Updated: 2021/12/15 12:32:29 by goliano-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fdf

LIB_MLX		= libmlx.dylib

SRCS =	./srcs/main.c ./utils/get_next_line.c ./utils/get_next_line_utils.c \
		./libft/ft_split.c ./libft/ft_atoi.c ./srcs/draw_matrix.c \
		./utils/operations.c ./srcs/init_data.c ./utils/handle_colored_map.c \
		./utils/hex_to_dec.c ./utils/get_map_width.c

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Werror -Wextra

RM			= rm -rf

INC			= -I includes/ -Imlx

%.o: %.c
	cc $(FLAGS) $(INC) -o $@ -c $?

all:	$(NAME)

mlx:	$(LIB_MLX)

$(LIB_MLX):		$(MLX_OBJS)
			ar -r $(LIB_MLX) $(MLX_OBJS)
			ranlib $(LIB_MLX)

libft/libft.a:
		make -C libft

mlx_t:
		make -C mlx

$(NAME):		libft/libft.a $(OBJS)
				$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(CFLAGS)	-o $(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C libft
		make clean -C mlx

fclean:		clean
			$(RM) $(NAME)
			make fclean -C libft

re:			fclean all

.PHONY:		all clean fclean re
