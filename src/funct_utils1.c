/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:22:17 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/03 20:42:05 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	ft_atodbl(char *s)
{
	long	n;
	double	fn;
	double	pow;
	int		sign;
	int		i;

	n = 0;
	i = 0;
	fn = 0.0;
	sign = 1;
	pow = 1;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -sign;
		i++;
	}
	n = ft_atodbl_part1(s, &i);
	fn = ft_atodbl_part2(s, &i);
	return ((n + fn) * sign);
}

long	ft_atodbl_part1(char *s, int *i)
{
	long	n;

	n = 0;
	while (s[*i] != '.' && s[*i])
	{
		n = (n * 10) + (s[*i] - '0');
		(*i)++;
	}
	if (s[*i] == '.')
		(*i)++;
	return (n);
}

double	ft_atodbl_part2(char *s, int *i)
{
	double	fn;
	double	pow;

	fn = 0.0;
	pow = 1;
	while (s[*i])
	{
		pow /= 10;
		fn = fn + (s[*i] - '0') * pow;
		(*i)++;
	}
	return (fn);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i) && i < (int)n - 1)
		i++;
	if (n)
		return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
	return (0);
}
