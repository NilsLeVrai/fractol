/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/24 19:41:42 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void	init_event_struct(t_complex *fractal)
{
	mlx_hook(fractal->win_ptr, KeyPress, KeyPressMask, key_capture, fractal);
	mlx_hook(fractal->win_ptr, ButtonPress, ButtonPressMask, mouse_capture, \
	fractal);
	mlx_hook(fractal->win_ptr, DestroyNotify, StructureNotifyMask, \
	closing_window, fractal);
	mlx_hook(fractal->win_ptr, ButtonPress, ButtonPressMask, mouse_capture, \
	fractal);
}

static void	init_data_struct(t_complex *fractal)
{
	fractal->modulus = 4.0;
	fractal->zoom = 1.0;
	fractal->shift_x = 0.0;
	fractal->shift_y = 0.0;
	fractal->max_iter = 100;
	fractal->color = 0x000000;
}

void	run_mlx(t_complex *fractal)
{
	fractal->mlx_ptr = mlx_init();
	if (!fractal->mlx_ptr)
		return ;
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, HEIGHT, WIDTH, \
	"fractol");
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
	fractal->img.data = mlx_get_data_addr(fractal->img.img_ptr, \
	&fractal->img.bpp, &fractal->img.size_line, &fractal->img.endian);
	init_event_struct(fractal);
	init_data_struct(fractal);
}

void	welcome_instructions(void)
{
	ft_printf("Welcome to my fract'ol :)\n");
	ft_printf("This program renders the Mandelbrot and Julia fractals.\n");
	ft_printf("To render the Mandelbrot fractal, run the program with the ");
	ft_printf("following command:\n");
	ft_printf("./fractol mandelbrot\n\n");
	ft_printf("To render the Julia fractal, run the program with the ");
	ft_printf("following command:\n");
	ft_printf("./fractol julia -0.7 0.27015\n\n");
	ft_printf("You can also zoom in and out using the mouse wheel.\n");
	ft_printf("You can change the color scheme by pressing the space bar.\n");
	ft_printf("You can increase or decrease the number of iterations by ");
	ft_printf("pressing the Page Up or Page Down keys.\n");
	ft_printf("You can move the fractal by pressing the arrow keys.\n");
	ft_printf("You can exit the program by pressing the Esc key or by ");
	ft_printf("clicking the x cross.\n");
	ft_printf("Enjoy!\n");
}
