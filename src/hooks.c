/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:24:42 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/10 17:14:45 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void zoom_hook(int key, int x, int y, t_complex *fractal)
{
	if (key == 4)
	{
		fractal->zoom *= 1.1;
		fractal->shift_x += (scale(x, 0, WIDTH) * fractal->zoom) - (scale(x, 0, WIDTH) * fractal->zoom * 1.1);
		fractal->shift_y += (scale(y, 0, HEIGHT) * fractal->zoom) - (scale(y, 0, HEIGHT) * fractal->zoom * 1.1);
	}
	else if (key == 5)
	{
		fractal->zoom /= 1.1;
		fractal->shift_x += (scale(x, 0, WIDTH) * fractal->zoom) - (scale(x, 0, WIDTH) * fractal->zoom / 1.1);
		fractal->shift_y += (scale(y, 0, HEIGHT) * fractal->zoom) - (scale(y, 0, HEIGHT) * fractal->zoom / 1.1);
	}
	render_fractal(fractal);
}