/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:06:26 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/31 16:00:43 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_complex	fractal;
	mlx_t		*mlx;
	mlx_image_t	*img;

	introduction_message();
	check_errors(&fractal, argc, argv);
	init_structure(&fractal);
	run_mlx(fractal, &mlx, &img);
	fractal.mlx = mlx;
	fractal.img = img;
	image_to_window(mlx, img, 0, 0);
	render_fractal(&fractal);
	mlx_loop(mlx);
	mlx_terminate(fractal.mlx);
	return (EXIT_SUCCESS);
}
