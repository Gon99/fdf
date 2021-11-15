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

static void	init_map_data(char *line, t_fstack *f_stack)
{
	int	c;
	int	w;
	int	h;

	c = -1;
	w = 0;
	h = 0;
	while (line[++c])
	{
		if (line[c] == '\n')
			h++;
		if (line[c] != ' ' && line[c] != '\n')
			w++;
	}
	f_stack->width = w;
	f_stack->height = h;
	free(line);
}

static int	error_map(char *line, t_fstack *f_stack)
{
	int		i;
	char	**sp;
	int		r;

	i = 0;
	r = 0;
	sp = ft_split(line, ' ');
	if (!sp)
		return (1);
	while (sp[i])
	{
		free(sp[i]);
		i++;
	}
	free(sp);
	if (f_stack->width != i)
		r = 1;
	return (r);
}

/*void	leaks()
{
	system("leaks -q fdf");
}*/

int main(int argc, char **argv)
{
	int			fd;
	char		*line;
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
	line = get_next_line(fd);
	init_map_data(line, &f_stack);
	while (line)
	{
		if (error_map(line, &f_stack))
		{
			printf("Error\n");
			return (0);
		}
		line = get_next_line(fd);
		free(line);
	}
	printf("H: %d\n", f_stack.height);
	return (1);
}
