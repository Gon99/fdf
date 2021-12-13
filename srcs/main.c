/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:56:40 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/13 10:25:33 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*static void	init_height_width(int fd, t_fstack *f_stack)
{
	int		c;
	char	*line;
	char	**sp;

	line = get_next_line(fd);
	sp = ft_split(line, ' ');
	if (!sp)
		return ;
	c = 0;
	while (sp[c])
	{
		if (sp[c][0] == '0' || ft_atoi(sp[c]) != 0)
			f_stack->width++;
		//free(sp[c]);
		c++;
	}
	//free(sp);
	while (line)
	{
		//free(line);
		line = get_next_line(fd);
		f_stack->height++;
	}
	close(fd);
	//free(line);
}
*/
/*static void	init_map_data(char *file, int height, t_fstack *f_stack)
{
	int	c;
	char	*line;
	int	fd;
	//char	**sp;

	c = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		//handle error
	f_stack->height = height;
	printf("H: %d\n", height);
	line = get_next_line(fd);
	while (line)
	{
		sp = ft_split(line, ' ');
		line = get_next_line(fd);
	}
	printf("L: %s\n", line);
	sp = ft_split(line, ' ');
	int x = 0;
	while (sp[x])
	{
		printf("SP: %s\n", sp[x]);
		x++;
	}
	f_stack->width = w;
	f_stack->height = h;
	//free(line);
}*/

/*static int	error_map(char *line, t_fstack *f_stack)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	printf("L: %s\n", line);
	while (line[i])
	{
		if (line[i] != '\n' && line[i] != ' ')
			r++;
		i++;
	}
	printf("W: %d\n", f_stack->width);
	printf("I: %d\n", r);
	if (f_stack->width != r)
		return (1);
	return (0);
}*/


/*static void init_matrix(char *file, t_fstack *f_stack)
{
	int		fd;
	char	*line;
	char	**sp;
	int		i;
	int		j;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	f_stack->matrix = malloc(sizeof(int **) * f_stack->height + 1);
	if (!f_stack->matrix)
		return ;
	line = get_next_line(fd);
	j = 0;
	while (line)
	{
		sp = ft_split(line, ' ');
		if (!sp)
			return;
		i = 0;
		f_stack->matrix[j] = malloc(sizeof(int*) * f_stack->width + 1);
		if (!f_stack->matrix[i])
			return ;
		while (sp[i])
		{
			if (ft_atoi(sp[i]) != 0 || sp[i][0] == '0')
				f_stack->matrix[j][i] = ft_atoi(sp[i]);
			//free(sp[i]);
			i++;
		}
		//printf("\n");
		//free(sp);
		//free(line);
		line = get_next_line(fd);
		j++;
	}
	//free(line);
}*/

/*void	free_matrix(t_fstack *f_stack)
{
	int	i;

	i = 0;
	while (i < f_stack->height)
	{
		free(f_stack->matrix[i]);
		i++;
	}
	free(f_stack->matrix);
}*/

/*void	leaks()
{
	system("leaks -q fdf");
}*/

int close_win(int keycode, t_fstack *f_stack)
{
	if (keycode == 53)
	{
		mlx_destroy_window(f_stack->mlx, f_stack->mlx_win);
		exit(1);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int			fd;
	t_fstack	f_stack;

//	atexit(leaks);
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("zsh");
		return (0);
	}
	init_matrix(fd, argv[1], &f_stack);
	draw_matrix(&f_stack);
	mlx_hook(f_stack.mlx_win, 2, 1L<<0, close_win, &f_stack);
	mlx_loop(f_stack.mlx);
	//free_matrix(&f_stack);
	return (1);
}
