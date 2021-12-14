/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:56:40 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/14 16:20:24 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	leaks()
{
	system("leaks -q fdf");
}

static void	free_matrix(t_fstack *f_stack)
{
	int	i;

	i = 0;
	while (i < f_stack->height)
		free(f_stack->matrix[i++]);
	free(f_stack->matrix);
}

static int	close_win(int keycode, t_fstack *f_stack)
{
	if (keycode == 53)
	{
		free_matrix(f_stack);
		mlx_destroy_window(f_stack->mlx, f_stack->mlx_win);
		exit(1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			fd;
	t_fstack	f_stack;

	atexit(leaks);
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("zsh");
		return (0);
	}
	if (init_matrix(fd, argv[1], &f_stack) < 0)
	{
		printf("error matrix");
		return (-1);
	}
	draw_matrix(&f_stack);
	mlx_hook(f_stack.mlx_win, 2, 1L << 0, close_win, &f_stack);
	mlx_loop(f_stack.mlx);
	/*free(f_stack.mlx);
	free(f_stack.mlx_win);
	free(f_stack.img);
	free(f_stack.addr);*/
	free_matrix(&f_stack);
	return (1);
}
