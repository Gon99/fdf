/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:22:31 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/02 13:33:07 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	my_mlx_pixel_put(t_fstack *f_stack, int x, int y, int color)
{
	char	*dst;

	dst = f_stack->addr + (y * f_stack->line_length + x * (f_stack->bpp / 8));
	*(unsigned int*)dst = color;
}

void	bresenham(float x, float y, float x1, float y1, t_fstack *f_stack)
{
	float	dx;
	float	dy;
	int		z;
	int		z1;
	int		max;
	float	ax = x;
	float ay = y;

	z = f_stack->matrix[(int)y][(int)x].z * f_stack->zoom;
	z1 = f_stack->matrix[(int)y1][(int)x1].z * f_stack->zoom;
	
	x *= f_stack->zoom;
	y *= f_stack->zoom;
	x1 *= f_stack->zoom;
	y1 *= f_stack->zoom;
	
	//printf("z: %d\n", z);
	//printf("co: %d\n", f_stack->matrix[(int)y][(int)x].color);
	//printf("co2: %d\n", f_stack->color);
	//return ;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	
	x += 450;
	y += 450;
	x1 += 450;
	y1 += 450;
	
	dx = x1 - x;
	dy = y1 - y;

	max = get_max(get_mod(dx), get_mod(dy));

	dx /= max;
	dy /= max;
	//mlx_pixel_put(f_stack->mlx, f_stack->mlx_win, x, y, 0xffffff);
	while ((int)(x - x1) || (int)(y - y1))
	{
		//mlx_pixel_put(f_stack->mlx, f_stack->mlx_win, x, y, f_stack->matrix[(int)ay][(int)ax].color);
		my_mlx_pixel_put(f_stack, x, y, f_stack->matrix[(int)ay][(int)ax].color);
		x += dx;
		y += dy;
	}
}

void	draw_matrix(t_fstack *f_stack)
{
	int	x;
	int	y;
	
	y = 0;
	while (y < f_stack->height)
	{
		x = 0;
		while (x < f_stack->width)
		{
			if (x < f_stack->width - 1)
				bresenham(x, y, x + 1, y, f_stack);
			if (y < f_stack->height - 1)
				bresenham(x, y, x, y + 1, f_stack);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f_stack->mlx, f_stack->mlx_win, f_stack->img, 0, 0);
	mlx_loop(f_stack->mlx);
}
