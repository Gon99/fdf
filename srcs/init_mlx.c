/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 11:42:51 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/24 16:36:28 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

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
