/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:10:01 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/12 14:42:53 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define HEIGHT 800
# define WIDTH 800

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "mlx.h"

typedef struct s_complex
{
	t_img		img;
	double		julia_re_z;
	double		julia_im_z;
	void		*mlx_ptr;
	void		*win_ptr;
	int			type;
	double		zoom;
	double		modulus;
	double		shift_x;
	double		shift_y;
	int			max_iter;
}				t_complex;

typedef struct s_z
{
	double	re_z;
	double	im_z;
}			t_z;

typedef struct s_img_data_address
{
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
	void	*img_ptr;
}			t_img;

double	atod(char *s);
t_z		complex_add(t_z z1, t_z z2);
t_z		complex_square(t_z z);

char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	check_errors(t_complex *fractal, int argc, char **argv);

double	scale(double unscaled_num, double old_min, double old_max);
void	run_mlx(t_complex *fractal);
void	render_fractal(t_complex *fractal);
#endif
