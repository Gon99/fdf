/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: goliano- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 11:57:50 by goliano-          #+#    #+#             */
/*   Updated: 2021/12/14 16:17:14 by goliano-         ###   ########.fr       */
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
#  define BUFFER_SIZE 100
# endif

typedef struct c_matrix
{
	float	x;
	float	y;
	float	z;
	int		color;
	int		is_last;
}t_cmatrix;

typedef struct f_stack
{
	int			height;
	int			width;
	t_cmatrix	**matrix;
	int			zoom;
	void		*mlx;
	void		*mlx_win;
	int			win_w;
	int			win_h;
	void		*img;
	char		*addr;
	int			bpp;
	float		z_scale;
	int			line_length;
	int			endian;
	int			color;
}	t_fstack;

char		*get_next_line(int fd);
size_t		ft_strlen(char const *str);
char		**ft_split(char const *s, char c);
int			ft_atoi(char const *s);
void		draw_matrix(t_fstack *f_stack);
float		get_mod(float i);
float		get_max(float a, float b);
void		isometric(float *x, float *y, float z);
int			init_matrix(int fd, char *file, t_fstack *f_stack);
int			has_comma(char *str);
int			hex_to_dec(char *str);
int			get_map_width(const char *str, char c);
int			check_line_width(const char *str);

#endif
