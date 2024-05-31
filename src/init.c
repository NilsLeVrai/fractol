/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 14:18:43 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/31 15:59:03 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void image_to_window(mlx_t *mlx, mlx_image_t *image, int x, int y)
{
	if (mlx_image_to_window(mlx, image, x, y) == -1)
	{
		mlx_close_window(mlx);
		printf("%s", mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void	run_mlx(t_complex fractal, mlx_t **mlx, mlx_image_t **img)
{
	*mlx = mlx_init(fractal.width, fractal.height, "fractol", true);
	if (!(*mlx))
	{
		printf("Error: mlx_init failed\n");
		exit(EXIT_FAILURE);
	}
	*img = mlx_new_image(*mlx, fractal.width, fractal.height);
	if (!(*img))
	{
		mlx_close_window(*mlx);
		printf("Error: mlx_new_image failed\n");
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
	fractal->max_iter = 200;
}
