/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:13:06 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/29 17:35:11 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_height_width(int fd, t_fstack *f_stack)
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

static void	handle_color(t_fstack *f_stack, int i, int j, char **sp)
{
	char	**nsp;

	while (sp[i])
	{
		if (has_comma(sp[i]))
		{
			nsp = ft_split(sp[i], ',');
			f_stack->matrix[j][i] = ft_atoi(nsp[0]);
		}
		else
			f_stack->matrix[j][i] = ft_atoi(sp[i]);
		/*else (ft_atoi(sp[i]) != 0 || sp[i][0] == '0')
		{
			f_stack->matrix[j][i] = ft_atoi(sp[i]);
		
		}*/
		i++;
		//free(sp[i]);
	}
	//free(sp);
}

static void	fill_matrix(t_fstack *f_stack, int fd)
{
	int		i;
	int		j;
	char	*line;
	char	**sp;

	line = get_next_line(fd);
	j = 0;
	while (line)
	{
		sp = ft_split(line, ' ');
		if (!sp)
			return ;
		i = 0;
		f_stack->matrix[j] = malloc(sizeof(int*) * f_stack->width + 1);
		if (!f_stack->matrix[j])
			return ;
		handle_color(f_stack, i, j, sp);
		free(line);
		line = get_next_line(fd);
		j++;
	}
}

void	init_matrix(char *file, t_fstack *f_stack)
{
	int		fd;
	/*char	*line;
	char	**sp;
	int		i;
	int		j;*/

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	f_stack->matrix = malloc(sizeof(int **) * f_stack->height + 1);
	if (!f_stack->matrix)
		return ;
	fill_matrix(f_stack, fd);
}

void	init_mlx(t_fstack *f_stack)
{
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
	f_stack->img = mlx_new_image(mlx, 1920, 1080);
	f_stack->addr = mlx_get_data_addr(f_stack->img, &f_stack->bpp, &f_stack->line_length, &f_stack->endian);
	f_stack->mlx = mlx;
	f_stack->mlx_win = mlx_win;
	f_stack->zoom = 20;
}
