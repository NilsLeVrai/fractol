/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:24:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/22 14:34:27 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	closing_window(t_complex *fractal)
{
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
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->max_iter += 10;
	else if (keysym == XK_minus)
		fractal->max_iter -= 10;
	render_fractal(fractal);
	return (0);
}

int	mouse_capture(int key, int x, int y, t_complex *fractal)
{
	x++;
	y++;
	if (key == Button5)
		fractal->zoom *= 1.1;
	else if (key == Button4)
		fractal->zoom /= 1.1;
	render_fractal(fractal);
	return (0);
}
