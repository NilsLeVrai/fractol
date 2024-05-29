/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:10:01 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/29 16:34:57 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define HEIGHT 800
#define WIDTH 800

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct mlx_stuff
{
	void *mlx_ptr;
	void *win_ptr;
}               t_mlx;

typedef struct 		s_complex
{
	mlx_t			*mlx;
	mlx_image_t	 	*img;
    double 			julia_re_z;
    double 			julia_im_z;
    int     		type;
    double 			zoom;
    double 			modulus;
    double 			shift_x;
    double 			shift_y;
	unsigned short	height;
	unsigned short	width;
    int 			max_iter;
}               	t_complex;

typedef struct s_z
{
    double re_z;
    double im_z;
}               t_z;

//errors
void    check_errors(t_complex *fractal, int argc, char **argv);
void	introduction_message(void);

double atod(char *s);
t_z	complex_add(t_z z1, t_z z2);
t_z	complex_square(t_z z);
void init_structure(t_complex *fractal);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void check_errors(t_complex *fractal, int argc, char **argv);
char    *ft_strchr(const char *s, int c);

double	scale(double i, double old_min, double old_max);
void run_mlx(t_complex fractal, mlx_t **mlx, mlx_image_t **img);
void render_fractal(t_complex *fractal);
#endif

