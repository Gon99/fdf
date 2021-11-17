/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:22:31 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/17 17:18:09 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

void	draw_matrix(t_fstack *f_stack)
{
	void	*mlx;
	void	*mlx_win;

	printf("W: %d\n", f_stack->width);
	printf("H: %d\n", f_stack->height);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080);
	mlx_loop(mlx);
}
