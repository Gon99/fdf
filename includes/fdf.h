/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:57:50 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/17 16:27:41 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

typedef struct f_stack
{
	int	height;
	int	width;
	int	**matrix;
}	t_fstack;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);
char	**ft_split(char const *s, char c);
int		ft_atoi(char const *s);
void	draw_matrix(t_fstack *f_stack);

#endif
