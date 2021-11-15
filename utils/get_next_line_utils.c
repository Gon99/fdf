/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:23:36 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/15 12:37:08 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

size_t	ft_strlen(char const *str)
{
	size_t	l;

	l = 0;
	if (!str)
		return (l);
	while (str[l] != '\0')
		l++;
	return (l);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	r;
	size_t	tl;

	tl = ft_strlen(s1) + ft_strlen(s2);
	if (tl < 1)
		return (0);
	join = (char *)malloc((tl + 1) * sizeof(char));
	if (!join)
		return (0);
	i = 0;
	r = 0;
	if (s1)
	{
		while ((i < tl) && s1[i])
			join[i++] = s1[r++];
	}
	r = 0;
	while ((i < tl) && s2[r])
		join[i++] = s2[r++];
	join[i] = '\0';
	free((char *)s1);
	return (join);
}
