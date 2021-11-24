/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:22:31 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/24 16:51:51 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	my_mlx_pixel_put(t_fstack *f_stack, int x, int y, int color)
{
	char	*dst;

	dst = f_stack->addr + (y * f_stack->line_length + x * (f_stack->bpp / 8));
	*(unsigned int*)dst = color;
}

int	get_mod(float i)
{
	int	r;

	r = i;
	if (i < 0)
		r = -i;
	return (r);
}

int	get_max(int a, int b)
{
	int	r;

	r = a;
	if (b > a)
		r = b;
	return (r);
}

void	bresenham(int x, int y, int x1, int y1, t_fstack *f_stack)
{
	int	dx;
	int	dy;
	int	z;
	int	z1;

	z = f_stack->matrix[(int)y][(int)x];
	printf("p: %d\n", f_stack->matrix[3][3]);
	printf("Z: %d\n", z);
	z1 = f_stack->matrix[(int)y1][(int)x1];
	x *= f_stack->zoom;
	x1 *= f_stack->zoom;
	y *= f_stack->zoom;
	y1 *= f_stack->zoom;
	dx = x1 - x;
	dy = y1 - y;
	dx /= get_max(get_mod(dx), get_mod(dy));
	dy /= get_max(get_mod(dx), get_mod(dy));
	f_stack->color = 0xffffff;
	if (z > 0)
		f_stack->color = 0xe80c0c;
	//mlx_pixel_put(f_stack->mlx, f_stack->mlx_win, x, y, 0xffffff);
	while ((int)(x - x1) || (int)(y - y1))
	{
		my_mlx_pixel_put(f_stack, x, y, f_stack->color);
		x += dx;
		y += dy;
	}
}

void	draw_matrix(t_fstack *f_stack)
{
	int	x;
	int	y;
	//t_data img;

	/*void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 1080, "fdf");
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	*/
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
			//my_mlx_pixel_put(data, y + 200, x + 300, 0xffffff);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f_stack->mlx, f_stack->mlx_win, f_stack->img, 0, 0);
	mlx_loop(f_stack->mlx);
}
