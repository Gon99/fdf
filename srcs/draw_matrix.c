/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:22:31 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/07 16:00:11 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	my_mlx_pixel_put(t_fstack *f_stack, int x, int y, int color)
{
	char	*dst;

	dst = f_stack->addr + (y * f_stack->line_length + x * (f_stack->bpp / 8));
	printf("D: %s\n", dst);
	printf("C: %d\n", color);
	*(unsigned int *)dst = 0;
}

void	scale_coords(t_cmatrix *a, t_cmatrix *b, t_fstack *f_stack)
{
	a->x = a->x * f_stack->zoom;
	a->y = a->y * f_stack->zoom;
	a->z = a->z * f_stack->zoom;
	b->x = b->x * f_stack->zoom;
	b->y = b->y * f_stack->zoom;
	b->z = b->z * f_stack->zoom;
	isometric(&(a->x), &(a->y), a->z);
	isometric(&(b->x), &(b->y), b->z);
	a->x += f_stack->win_w / 2;
	a->y += f_stack->win_h / 1.5;
	b->x += f_stack->win_w / 2;
	b->y += f_stack->win_h / 1.5;
}

void	bresenham(t_cmatrix a, t_cmatrix b, t_fstack *f_stack)
{
	float	dx;
	float	dy;
	float	max;
	int	color;
	//float	ax = a.x;
	//float ay = a.y;

	color = f_stack->matrix[(int)a.y][(int)a.x].color;
	//printf("z: %d\n", z);
	//printf("co: %d\n", f_stack->matrix[(int)y][(int)x].color);
	//printf("co2: %d\n", f_stack->color);
	//return ;
	//printf("X1: %f\n", a.x);
	scale_coords(&a, &b, f_stack);
	//printf("X2: %f\n", a.x);
	/*
	x += 450;
	y += 450;
	x1 += 450;
	y1 += 450;
	*/

	dx = b.x - a.x;
	dy = b.y - a.y;

	max = get_max(get_mod(dx), get_mod(dy));

	dx /= max;
	dy /= max;
	//color = (b.z || a.z) ? 0xfc0345 : 0xBBFAFF;
	//color = (b.z != a.z) ? 0xfc031c : color;
	/*printf("DX: %f\n", dx);
	printf("DY: %f\n", dy);
	return ;*/
	//mlx_pixel_put(f_stack->mlx, f_stack->mlx_win, a.x, a.y, 0xffffff);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(f_stack->mlx, f_stack->mlx_win, a.x, a.y, color);
		//my_mlx_pixel_put(f_stack, a.x, a.y, color);
		a.x += dx;
		a.y += dy;
		if (a.x > f_stack->win_w || a.y > f_stack->win_h || a.y < 0 || a.x < 0)
			break ;
	}
}

/*int	key_hook(int keycode, t_fstack *f_stack)
{
	printf("HELLO HOOKS");
	printf("CODE: %d\n", keycode);
	printf("H: %d\n", f_stack->height);
	return (1);
}*/

void	draw_matrix(t_fstack *f_stack)
{
	int	x;
	int	y;
	
	y = 0;
	while (f_stack->matrix[y])
	{
		x = 0;
		while (1)
		{
			if (f_stack->matrix[y + 1])
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y + 1][x], f_stack);
			if (!f_stack->matrix[y][x].is_last)
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y][x + 1], f_stack);
			if (f_stack->matrix[y][x].is_last)
				break ;
			/*if (y < f_stack->height - 1)
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y + 1][x], f_stack);
			if (x < f_stack->width - 1)
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y][x + 1], f_stack);
			if (!f_stack->matrix[y][x].is_last)
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y][x + 1], f_stack);
			if (f_stack->matrix[y][x].is_last)
				break ;*/
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f_stack->mlx, f_stack->mlx_win, f_stack->img, 0, 0);
	mlx_loop(f_stack->mlx);
	/*
	mlx_key_hook(f_stack->mlx_win, key_hook, f_stack);
	*/
}
