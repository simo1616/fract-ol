/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:39:33 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/03 20:42:07 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	get_color(int iteration, int max_iteration, int color_mode)
{
	double	t;
	t_color	color;

	t = (double)iteration / (double)max_iteration;
	ft_get_color_scheme(t, color_mode, &color);
	return ((color.r << 16) | (color.g << 8) | color.b);
}

void	ft_get_color_scheme(double t, int color_mode, t_color *color)
{
	if (color_mode == 0)
	{
		color->r = (int)(9 * (1 - t) * t * t * t * 255);
		color->g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		color->b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (color_mode == 1)
	{
		color->r = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		color->g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
		color->b = (int)(9 * (1 - t) * t * t * t * 255);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char const *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
		ft_putchar_fd(s[i++], fd);
}
