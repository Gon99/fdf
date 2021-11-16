/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:56:40 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/15 18:19:02 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	get_height(int fd)
{
	int	h;
	char	*line;

	h = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		h++;
	}
	free(line);
	close(fd);
	return (h);
}

static void	init_map_data(char *file, int height, t_fstack *f_stack)
{
	int	c;
	char	*line;
	int	fd;
	//char	**sp;

	c = -1;
	w = 0;
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
	/*printf("L: %s\n", line);
	sp = ft_split(line, ' ');
	int x = 0;
	while (sp[x])
	{
		printf("SP: %s\n", sp[x]);
		x++;
	}
	f_stack->width = w;
	f_stack->height = h;
	//free(line);*/
}

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

/*void	leaks()
{
	system("leaks -q fdf");
}*/

int main(int argc, char **argv)
{
	int		fd;
	int		height;
	t_fstack	f_stack;

	//atexit(leaks);
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("zsh");
		return (0);
	}
	height = get_height(fd);
	init_map_data(argv[1], height, &f_stack);
	return (1);
}
