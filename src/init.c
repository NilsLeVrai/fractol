/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:18:43 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/29 16:45:36 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	run_mlx(t_complex fractal, mlx_t **mlx, mlx_image_t **img)
{
	*mlx = mlx_init(fractal.width, fractal.height, "fractol", true);
	if (!(*mlx))
	{
		printf("Error: mlx_init failed\n");
		free(*mlx);
		exit(EXIT_FAILURE);
	}
	*img = mlx_new_image(*mlx, fractal.width, fractal.height);
	if (!(*img))
	{
		mlx_close_window(*mlx);
		printf("Error: mlx_new_image failed\n");
		free(*img);
		exit(EXIT_FAILURE);
	}
}

void	init_structure(t_complex *fractal)
{
	fractal->julia_re_z = 0;
	fractal->julia_im_z = 0;
	fractal->type = 0;
	fractal->zoom = 1;
	fractal->modulus = 4;
	fractal->shift_x = 0;
	fractal->shift_y = 0;
	fractal->height = HEIGHT;
	fractal->width = WIDTH;
	fractal->max_iter = 100;
}
