/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/31 19:47:17 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	zoom(int keycode, t_complex *fractal)
{
	if (keycode == 126)
	{
		fractal->zoom *= 1.1;
	}
	else if (keycode == 125)
	{
		fractal->zoom /= 1.1;
	}
	render_fractal(fractal);
	return (0);
}

static int	close_window(int keycode, t_complex *fractal)
{
	if (keycode == 53)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		free(fractal->mlx_ptr);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static void	init_event_struct(t_complex *fractal)
{
	mlx_key_hook(fractal->win_ptr, close_window, fractal);
	mlx_key_hook(fractal->win_ptr, zoom, fractal);
}

static void	init_data_struct(t_complex *fractal)
{
	fractal->modulus = 4.0;
	fractal->zoom = 1.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->max_iter = 200;
}

void	run_mlx(t_complex *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		return ;
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, HEIGHT, WIDTH, "fractol");
	if (!fractal->win_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		free(fractal->mlx_ptr);
	}
	init_data_struct(fractal);
	init_event_struct(fractal);
}
