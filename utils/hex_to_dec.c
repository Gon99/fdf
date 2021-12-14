/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_to_dec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 11:46:21 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/14 16:07:44 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	hex_to_dec(char *str)
{
	int	l;
	int	dec;
	int	base;

	l = ft_strlen(str);
	base = 1;
	dec = 0;
	while (l-- > 0)
	{
		if (str[l] >= '0' && str[l] <= '9')
			dec += (str[l] - 48) * base;
		else if (str[l] >= 'A' && str[l] <= 'F')
			dec += (str[l] - 55) * base;
		else if (str[l] >= 'a' && str[l] <= 'f')
			dec += (str[l] - 87) * base;
		base *= 16;
	}
	return (dec);
}
