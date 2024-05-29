/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:56:52 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/29 14:02:48 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/fractol.h"

void check_errors(t_complex *fractal, int argc, char **argv)
{
    if (argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
        fractal->type = 1; // 1 for mandelbrot
    else if (argc == 4 && !ft_strncmp(argv[1], "julia", 5))
    {
        fractal->julia_re_z = atod(argv[2]); // TODO: verif si entree pas valide.
        fractal->julia_im_z = atod(argv[3]);
        fractal->type = 2; // 2 for julia
    }
    else
    {
        printf("Invalid fractal type. Write either mandelbrot or julia followed by two numbers.\n");
        printf("Example: ./fractol mandelbrot\n");
        printf("Example: ./fractol julia -0.7 0.27015\n");
        exit(EXIT_FAILURE);
    }
}