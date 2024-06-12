/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:35 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/12 14:31:33 by niabraha         ###   ########.fr       */
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

double	scale(double unscaled_num, double old_min, double old_max)
{
	double	gap;
	double	div;
	double	new_min;
	double	new_max;

	new_min = -2;
	new_max = 2;
	gap = new_max - new_min;
	div = gap / old_max - old_min;
	return (new_min + unscaled_num * div);
}

static int ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int ft_isspace(int c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

double	atod(char *s)
{
	double	res;
	double	dec;
	int		i;
	int		sign;

	res = 0;
	dec = 0.1;
	i = 0;
	sign = 1;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '.')
	{
		res = res * 10 + s[i] - '0';
		i++;
		if (s[i] = '.')
			break ;
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

/* # include <stdio.h>

int main ()
{
	char *str = "76:23.456";
	printf("%f\n", atod(str));
} */