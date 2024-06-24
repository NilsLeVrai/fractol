/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:24:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/24 19:38:13 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	scale(double unscaled_num, double old_min, double old_max)
{
	double	gap;
	double	div;
	double	new_min;
	double	new_max;

	new_min = -2;
	new_max = 2;
	gap = new_max - new_min;
	div = gap / old_max - old_min;
	return (new_min + unscaled_num * div);
}

int	closing_window(t_complex *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(0);
	return (0);
}

int	key_capture(int keysym, t_complex *fractal)
{
	if (keysym == XK_Escape)
		closing_window(fractal);
	else if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_Page_Up && fractal->max_iter < 200)
		fractal->max_iter += 10;
	else if (keysym == XK_Page_Down && fractal->max_iter > 10)
		fractal->max_iter -= 10;
/* 	else if (keysym == XK_space)
		change_color(fractal); */
	render_fractal(fractal);
	return (0);
}

int	mouse_capture(int key, int x, int y, t_complex *fractal)
{
	if (key == Button5)
		fractal->zoom *= 1.1;
	else if (key == Button4)
		fractal->zoom /= 1.1;
	else if (key == Button1)
		julia_click_event(x, y, fractal);
	render_fractal(fractal);
	return (0);
}
