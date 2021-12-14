/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:20:52 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/14 14:14:10 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_map_width(const char *str, char c)
{
	int	width;
	int	i;

	i = 0;
	width = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			width++;
		while (str[i] != c && str[i])
			i++;
	}
	return (width);
}

int	check_line_width(const char *str)
{
	int		i;
	int		width;
	char	**sp;

	i = 0;
	width = 0;
	sp = ft_split(str, ' ');
	while (sp[i])
	{
		if (ft_atoi(sp[i]) != 0 || sp[i][0] == '0')
			width++;
		free(sp[i]);
		i++;
	}
	free(sp);
	return (width);
}
