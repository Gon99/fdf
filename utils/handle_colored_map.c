/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_comma.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:03:46 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/15 12:32:05 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	has_comma(char *str)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (str[i] && r == 0)
	{
		if (str[i] == ',')
			r = 1;
		i++;
	}
	return (r);
}

void	handle_colored_map(t_fstack *f_stack, char **nsp, int j, int i)
{
	f_stack->matrix[j][i].z = ft_atoi(nsp[0]);
	f_stack->matrix[j][i].color = hex_to_dec(nsp[1]);
	free(nsp[0]);
	free(nsp[1]);
	free(nsp);
}
