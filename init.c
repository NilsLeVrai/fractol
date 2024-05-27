/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/27 17:09:57 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void init_data_struct(t_complex *fractal)
{
    fractal->modulus = 4.0;
    fractal->zoom = 1.0;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->max_iter = 20;
}

void run_mlx(t_complex *fractal)
{
    fractal->mlx_ptr = mlx_init();
    if (!fractal->mlx_ptr)
        return ;
    fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, HEIGHT, WEIGHT, "Fractol");
    if (!fractal->win_ptr)
    {
        mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
        free(fractal->mlx_ptr);
    }
    init_data_struct(fractal);
   //init_event_struct(fractal);
}