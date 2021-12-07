/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:13:06 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/07 15:18:01 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_height_width(int fd, t_fstack *f_stack)
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
		
		/**else (ft_atoi(sp[i]) != 0 || sp[i][0] == '0')
		{
			f_stack->matrix[j][i] = ft_atoi(sp[i]);
		
		}*/
		i++;
		//free(sp[i]);
	}
	f_stack->matrix[j][--i].is_last = 1;
	//free(sp);
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
}

static void	init_mlx(t_fstack *f_stack)
{
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	f_stack->win_w = 1080;
	f_stack->win_h = 720;
	f_stack->img = mlx_new_image(mlx, f_stack->win_w, f_stack->win_h);
	f_stack->addr = mlx_get_data_addr(f_stack->img, &f_stack->bpp, &f_stack->line_length, &f_stack->endian);
	f_stack->mlx = mlx;
	f_stack->zoom = 20;
	mlx_win = mlx_new_window(mlx, f_stack->win_w, f_stack->win_h, "fdf");
	f_stack->mlx_win = mlx_win;
}

void	init_matrix(int fd, char *file, t_fstack *f_stack)
{
	int		fd2;
	/*char	*line;
	char	**sp;
	int		i;
	int		j;*/

	f_stack->width = 0;
	f_stack->height = 0;
	init_height_width(fd, f_stack);
	fd2 = open(file, O_RDONLY);
	if (fd2 < 0)
		return ;
	f_stack->matrix = malloc(sizeof(t_cmatrix *) * f_stack->height + 1);
	if (!f_stack->matrix)
		return ;
	fill_matrix(f_stack, fd2);
	init_mlx(f_stack);
}
