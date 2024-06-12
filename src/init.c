/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/12 14:46:28 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
static int deal_key(int keycode) // enlever static
{
    printf("keycode = %d\n", keycode);
    return (0);
}
static int	zoom(int keycode, t_complex *fractal)
{
	if (keycode == 97)
	{
		fractal->zoom *= 1.1;
	}
	else if (keycode == 122)
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
	mlx_hook(fractal->win_ptr, key_event, key_mask, key_handler, fractal);
	mlx_hook(fractal->win_ptr, button_event, button_mask, mouse_handler, fractal);
	mlx_hook(fractal->win_ptr, destroy_notify, no_event_mask, close_handler, fractal);
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
	fractal->img.img.ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bpp, &fractal->img.size_line, &fractal->img.endian);
	init_data_struct(fractal);
	init_event_struct(fractal);
}
