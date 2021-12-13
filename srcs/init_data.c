/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:13:06 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/13 16:40:13 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	init_height_width(int fd, t_fstack *f_stack)
{
	char	*line;
	int		r;

	r = 0;
	line = get_next_line(fd);
	f_stack->width = get_map_width(line, ' ');
	while (line && r >= 0)
	{
		free(line);
		if (line[0])
		{
			printf("LINE: %s\n", line);
			printf("W: %d\n", get_map_width(line, ' '));
		
		}
		line = get_next_line(fd);
		if (line[0] && line && f_stack->width != get_map_width(line, ' '))
			r = -1;
		f_stack->height++;
	}
	free(line);
	printf("W: %d\n", f_stack->width);
	printf("h: %d\n", f_stack->height);
	f_stack->height++;
	close(fd);
	return (r);
}

static void	init_color_z(t_fstack *f_stack, int j, char **sp)
{
	char		**nsp;
	int	i;
	
	i = 0;
	while (sp[i])
	{
		if (sp[i][0] == '\n')
			break ;
		if (has_comma(sp[i]))
		{
			nsp = ft_split(sp[i], ',');
			f_stack->matrix[j][i].z = ft_atoi(nsp[0]);
			f_stack->matrix[j][i].color = hex_to_dec(nsp[1]);
			//free(nsp[0]);
			//free(nsp[1]);
			free(nsp);
		}
		else
		{
			f_stack->matrix[j][i].z = ft_atoi(sp[i]);
			f_stack->matrix[j][i].color = 0xffffff;
		}
		f_stack->matrix[j][i].x = i;
		f_stack->matrix[j][i].y = j;
		f_stack->matrix[j][i].is_last = 0;
		free(sp[i++]);
	}
	f_stack->matrix[j][--i].is_last = 1;
	free(sp);
}

static void	fill_matrix(t_fstack *f_stack, int fd)
{
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
		f_stack->matrix[j] = malloc(sizeof(t_cmatrix) * f_stack->width + 1);
		if (!f_stack->matrix[j])
			return ;
		init_color_z(f_stack, j, sp);
		free(line);
		line = get_next_line(fd);
		j++;
	}
	f_stack->matrix[j] = NULL;
}

static void	init_mlx(t_fstack *f_stack)
{
	f_stack->mlx = mlx_init();
	f_stack->win_w = 1080;
	f_stack->win_h = 1080;
	f_stack->img = mlx_new_image(f_stack->mlx, f_stack->win_w, f_stack->win_h);
	f_stack->addr = mlx_get_data_addr(f_stack->img, &f_stack->bpp, &f_stack->line_length, &f_stack->endian);
	f_stack->zoom = 15;
	if (f_stack->width > 50)
		f_stack->zoom = 4;
	if (f_stack->width > 200)
		f_stack->zoom = 2;
	f_stack->mlx_win =  mlx_new_window(f_stack->mlx, f_stack->win_w, f_stack->win_h, "fdf");
}

int	init_matrix(int fd, char *file, t_fstack *f_stack)
{
	int		fd2;
	int		r;

	f_stack->width = 0;
	f_stack->height = 0;
	r = init_height_width(fd, f_stack);
	if (r < 0)
		return (r);
	fd2 = open(file, O_RDONLY);
	if (fd2 < 0)
		return (-1);
	f_stack->matrix = malloc(sizeof(t_cmatrix *) * f_stack->height + 1);
	if (!f_stack->matrix)
		return (-1);
	fill_matrix(f_stack, fd2);
	init_mlx(f_stack);
	return (r);
}
