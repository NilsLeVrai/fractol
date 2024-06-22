/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:10:08 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/22 15:08:18 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	mandelbrot_or_julia(t_z *z, t_z *c, t_complex *fractal)
{
	if (fractal->type == 1)
	{
		c->re_z = z->re_z;
		c->im_z = z->im_z;
	}
	else if (fractal->type == 2)
	{
		c->re_z = fractal->julia_re_z;
		c->im_z = fractal->julia_re_z;
	}
}

static void	render_pixel(t_complex *fractal, int x, int y)
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
			mlx_pixel_put(fractal->mlx_ptr, fractal->win_ptr, x, y, color);
			return ;
		}
		i++;
	}
	mlx_pixel_put(fractal->mlx_ptr, fractal->win_ptr, x, y, color);
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
	mlx_loop(fractal->mlx_ptr);
}

void	check_errors(t_complex *fractal, int argc, char **argv)
{
	if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		fractal->type = 1;
	else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
	{
		if (check_atod(argv[2]) && check_atod(argv[3]))
		{
			fractal->julia_re_z = atod(argv[2]);
			fractal->julia_im_z = atod(argv[3]);
			fractal->type = 2;
		}
		else
			//ft_printf("Invalid float number.\n");
			printf("Example: ./fractol julia -0.7 0.27015\n");
	}
	else
	{
		printf("Invalid fractal type. Write either mandelbrot or julia ");
		printf("followed by two numbers.\n");
		printf("Example: ./fractol mandelbrot\n");
		printf("Example: ./fractol julia -0.7 0.27015\n");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	t_complex	fractal;

	check_errors(&fractal, argc, argv);
	run_mlx(&fractal);
	render_fractal(&fractal);
}

/*
TODO:
check les arguments pour julia
free leaks
*/