/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:57:50 by goliano-          #+#    #+#             */
/*   Updated: 2021/11/29 17:35:07 by goliano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

typedef struct f_stack
{
	int		height;
	int		width;
	int		**matrix;
	int		zoom;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		color;
}	t_fstack;

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(char const *str);
char	**ft_split(char const *s, char c);
int		ft_atoi(char const *s);
void	draw_matrix(t_fstack *f_stack);
void	init_mlx(t_fstack *f_stack);
int		get_mod(float i);
int		get_max(int a, int b);
void	isometric(float *x, float *y, int z);
void	init_height_width(int fd, t_fstack *f_stack);
void	init_matrix(char *file, t_fstack *f_stack);
int		has_comma(char *str);

#endif
