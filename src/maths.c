/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:35 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/30 17:28:57 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

t_z	complex_add(t_z z1, t_z z2)
{
	t_z	res;

	res.re_z = z1.re_z + z2.re_z;
	res.im_z = z1.im_z + z2.im_z;
	return (res);
}

t_z	complex_square(t_z z)
{
	t_z	res;

	res.re_z = (z.re_z * z.re_z) - (z.im_z * z.im_z);
	res.im_z = 2 * z.re_z * z.im_z;
	return (res);
}

double	scale(double i, double new_min, double new_max, double old_min, double old_max)
{
/* 	double	gap;
	double	div;
	double	new_min;
	double	new_max;

	new_min = -2;
	new_max = 2; 
	gap = new_max - new_min;
	div = gap / old_max - old_min;
	return (new_min + i * div); */
	return (new_max - new_min) * (i - old_min) / (old_max - old_min) + new_min;
}
