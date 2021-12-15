/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:22:31 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/15 17:13:11 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_fstack *f_stack, float x, float y, int color)
{
	char	*dst;

	dst = f_stack->addr + ((int)y * f_stack->line_length \
			+ (int)x * (f_stack->bpp / 8));
	*(unsigned int *)dst = color;
}

void	scale_coords(t_cmatrix *a, t_cmatrix *b, t_fstack *f_stack)
{
	isometric(&(a->x), &(a->y), a->z);
	isometric(&(b->x), &(b->y), b->z);
	a->x = a->x * f_stack->zoom;
	a->y = a->y * f_stack->zoom;
	b->x = b->x * f_stack->zoom;
	b->y = b->y * f_stack->zoom;
	a->x += f_stack->win_w / 2;
	a->y += f_stack->win_h / 2;
	b->x += f_stack->win_w / 2;
	b->y += f_stack->win_h / 2;
}

double percent(float start, float end, float current)
{
	double	placement;
	double	distance;
	double	r;

	distance = (int)end - (int)start;
	placement = (int)current - (int)start;
	r = 1.0;
	if (distance != 0)
		r = (int)start / (int)distance;
	return (r);
}

int	get_light(float start, float end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	degradate(t_cmatrix a, t_cmatrix b, t_cmatrix c)
{
	double	percentage;
	int		red;
	int		green;
	int		blue;
	int diff;
	int diffy;

	diff = b.x - a.x;
	diffy = b.y - a.y;
	if (a.color == b.color)
		return (a.color);
	if (a.x > a.y)
		percentage = percent(a.x, b.x, c.x);
	else
		percentage = percent(a.y, b.y, c.y);
	red = get_light((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, percentage);
	green = get_light((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, percentage);
	blue = get_light(a.color & 0xFF, b.color & 0xFF, percentage);
	printf("R: %d\n", red << 16);
	printf("G: %d\n", green << 16);
	printf("B: %d\n", blue << 16);
	return ((red << 16) | (green << 8) | blue);
}

void	bresenham(t_cmatrix a, t_cmatrix b, t_fstack *f_stack)
{
	float	dx;
	float	dy;
	float	max;
	int		color;
	//t_cmatrix cur;

	printf("A1: %d\n", a.color);
	printf("B2: %d\n", b.color);
	color = f_stack->matrix[(int)a.y][(int)a.x].color;
	scale_coords(&a, &b, f_stack);
	dx = b.x - a.x;
	dy = b.y - a.y;
	max = get_max(get_mod(dx), get_mod(dy));
	dx /= max;
	dy /= max;
	//cur = a;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x > f_stack->win_w || a.y > f_stack->win_h || a.y < 0 || a.x < 0)
			break ;
		//color = degradate(a, b, cur);
		my_mlx_pixel_put(f_stack, a.x, a.y, color);
		a.x += dx;
		a.y += dy;
		//cur.x += dx;
		//cur.y += dy;
	}
}

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
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y + 1][x] \
						, f_stack);
			if (!f_stack->matrix[y][x].is_last)
				bresenham(f_stack->matrix[y][x], f_stack->matrix[y][x + 1] \
						, f_stack);
			if (f_stack->matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f_stack->mlx, f_stack->mlx_win, f_stack->img, 0, 0);
}
