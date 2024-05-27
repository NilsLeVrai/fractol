/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:55 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/27 22:51:26 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int deal_key(int keycode, t_complex *fractal)
{
    printf("keycode = %d\n", keycode);
    return (0);
}
/*
keyup = 126
keydown = 125
keyright = 124
keyleft = 123

*/

static int zoom(int keycode, t_complex *fractal)
{
    if (keycode == 126)
    {
        fractal->zoom *= 1.1;
    }
    else if (keycode == 125)
    {
        fractal->zoom /= 1.1;
    }
    render_fractal(fractal);
    return (0);
}

static int close_window(int keycode, t_complex *fractal)
{
    if (keycode == 53)
    {
        mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
        free(fractal->mlx_ptr);
        exit(EXIT_SUCCESS);
    }
    return (0);
}

static void init_event_struct(t_complex *fractal)
{
    //mlx_key_hook(fractal->win_ptr, deal_key, fractal); //tester les keycodes
    mlx_key_hook(fractal->win_ptr, close_window, fractal);
    mlx_key_hook(fractal->win_ptr, zoom, fractal);
}
static void init_data_struct(t_complex *fractal)
{
    fractal->modulus = 4.0;
    fractal->zoom = 1.0;
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->max_iter = 100;
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
    init_event_struct(fractal);
}