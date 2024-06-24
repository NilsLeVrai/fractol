/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:39:45 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/24 18:33:57 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	julia_click_event(int x, int y, t_complex *fractal)
{
	if (fractal->type == 2)
	{
		fractal->julia_re_z = (scale(x, 0, WIDTH) * fractal->zoom) + \
		fractal->shift_x;
		fractal->julia_im_z = (scale(y, 0, HEIGHT) * fractal->zoom) + \
		fractal->shift_y;
	}
	return (0);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *) dst = color;
}

void	mandelbrot_or_julia(t_z *z, t_z *c, t_complex *fractal)
{
	if (fractal->type == 1)
	{
		c->re_z = z->re_z;
		c->im_z = z->im_z;
	}
	else if (fractal->type == 2)
	{
		c->re_z = fractal->julia_re_z;
		c->im_z = fractal->julia_im_z;
	}
}

void	render_pixel(t_complex *fractal, int x, int y)
{
	t_z	z;
	t_z	c;
	int	i;
	int	color;

	i = 0;
	color = 0xFFFFFF;
	z.re_z = (scale(x, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.im_z = (scale(y, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	mandelbrot_or_julia(&z, &c, fractal);
	while (i < fractal->max_iter)
	{
		z = complex_add(complex_square(z), c);
		if ((z.re_z * z.re_z) + (z.im_z * z.im_z) > fractal->modulus)
		{
			color = scale(i, 0x12e3ab, fractal->max_iter);
			my_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(&fractal->img, x, y, color);
}

void	render_fractal(t_complex *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			render_pixel(fractal, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr, \
	fractal->img.img_ptr, 0, 0);
}
