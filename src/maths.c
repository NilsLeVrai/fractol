/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:35 by niabraha          #+#    #+#             */
/*   Updated: 2024/06/24 18:05:07 by niabraha         ###   ########.fr       */
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

void	init_atod(t_atod *atod_s)
{
	atod_s->dec = 0.1;
	atod_s->sign = 1;
	atod_s->i = 0;
	atod_s->res = 0;
}

double	atod(char *s)
{
	t_atod	atod_s;

	init_atod(&atod_s);
	while (s[atod_s.i] == 32 || (s[atod_s.i] >= 9 && s[atod_s.i] <= 13))
		atod_s.i++;
	if (s[atod_s.i++] == '-')
		atod_s.sign = -1;
	while (s[atod_s.i] >= '0' && s[atod_s.i] <= '9' && s[atod_s.i] != '.')
	{
		atod_s.res = atod_s.res * 10 + s[atod_s.i++] - '0';
		if (s[atod_s.i] == '.')
			break ;
	}
	if (s[atod_s.i] == '.')
	{
		atod_s.i++;
		while (s[atod_s.i] >= '0' && s[atod_s.i] <= '9')
		{
			atod_s.res += atod_s.dec * (s[atod_s.i++] - '0');
			atod_s.dec /= 10;
		}
	}
	return (atod_s.res * atod_s.sign);
}

int	check_atod(char *s)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9' && s[i] != '.')
		i++;
	if (s[i] == '.')
	{
		dot++;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
		i++;
	if ((s[i] == 0 && dot == 1) || (s[i] == 0 && dot == 0))
		return (1);
	return (0);
}
