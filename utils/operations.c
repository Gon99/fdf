/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:31:34 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/09 17:46:41 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	get_mod(float i)
{
	float	r;

	r = i;
	if (i < 0)
		r = -i;
	return (r);
}

float	get_max(float a, float b)
{
	float	r;

	r = a;
	if (b > a)
		r = b;
	return (r);
}

void	isometric(float *x, float *y, float z)
{
	//0.523599
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}
