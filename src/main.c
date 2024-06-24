/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:10:08 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/24 18:36:36 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int argc, char **argv)
{
	t_complex	fractal;

	welcome_instructions();
	check_errors(&fractal, argc, argv);
	run_mlx(&fractal);
	render_fractal(&fractal);
	mlx_loop(fractal.mlx_ptr);
}
