/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:09:46 by niabraha          #+#    #+#             */
/*   Updated: 2024/05/29 16:32:59 by niabraha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

double	atod(char *s)
{
	double	res;
	double	dec;
	int		i;
	int		sign;

	res = 0;
	dec = 0;
	i = 0;
	sign = 1;
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*char1;
	unsigned char	*char2;

	char1 = (unsigned char *) s1;
	char2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (n - 1 > i && char1[i] == char2[i])
	{
		if (char1[i] != char2[i])
			return (char1[i] - char2[i]);
		else if (char1[i] == '\0' || char2[i] == '\0')
			return (char1[i] - char2[i]);
		i++;
	}
	return (char1[i] - char2[i]);
}
