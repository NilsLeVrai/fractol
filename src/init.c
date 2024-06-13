/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/13 18:20:03 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_event_struct(t_complex *fractal)
{
	mlx_hook(fractal->win_ptr,
			KeyPress,
			KeyPressMask,
			key_capture,
			fractal);
	mlx_hook(fractal->win_ptr,
			ButtonPress,
			ButtonPressMask,
			mouse_capture,
			fractal);
}

static void	init_data_struct(t_complex *fractal)
{
	fractal->modulus = 4.0;
	fractal->zoom = 1.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->max_iter = 100;
}

void	run_mlx(t_complex *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		return ;
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, HEIGHT, WIDTH, "fractol");
	if (!fractal->win_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, HEIGHT, WIDTH);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
	}
	fractal->img.img_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.size_line, &fractal->img.endian);
	init_event_struct(fractal);
	init_data_struct(fractal);
}
