/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:35 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/27 22:50:56 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_z complex_add(t_z z1, t_z z2)
{
    t_z res;

    res.re_z = z1.re_z + z2.re_z;
    res.im_z = z1.im_z + z2.im_z;
    return (res);
}

t_z complex_square(t_z z)
{
    t_z res;

    res.re_z = (z.re_z * z.re_z) - (z.im_z * z.im_z); //a^2 - b^2
    res.im_z = 2 * z.re_z * z.im_z; //2abi
    return (res);
}

double scale(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    double gap;
    double div;

    gap = new_max - new_min;
    div = gap / old_max - old_min;
    return (new_min + unscaled_num * div);
}

double atod(char *s)
{
    double res = 0;
    double dec = 0.1;
    int i = 0;
    int sign = 1;

    while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
        i++;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (s[i] >= '0' && s[i] <= '9')
    {
        res = res * 10 + s[i] - '0';
        i++;
    }
    if (s[i] == '.')
    {
        i++;
        while (s[i] >= '0' && s[i] <= '9')
        {
            res += dec * (s[i] - '0');
            dec /= 10;
            i++;
        }
    }
    return (res * sign);
}
