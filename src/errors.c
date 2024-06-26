/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:36:29 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/24 20:37:44 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_error(void)
{
	ft_printf("Invalid fractal type. Write either mandelbrot or julia ");
	ft_printf("followed by two numbers.\n");
	ft_printf("Example: ./fractol mandelbrot\n");
	ft_printf("Example: ./fractol julia -0.7 0.27015\n");
	exit(EXIT_SUCCESS);
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
			print_error();
	}
	else
		print_error();
}
