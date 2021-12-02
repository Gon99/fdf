/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:31:34 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/02 12:51:05 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
