/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:15:24 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/04 16:17:27 by mbendidi         ###   ########.fr       */
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

int	calculate_color(int iter, double zx, double zy, t_fractal *fractal)
{
	double	log_zn;
	double	nu;
	double	smooth_index;

	if (iter < fractal->iteration_definition)
	{
		log_zn = log(zx * zx + zy * zy) / 2.0;
		nu = log(log_zn / log(2.0)) / log(2.0);
		smooth_index = iter + 1 - nu;
		return (get_color(smooth_index, fractal->iteration_definition,
				fractal->color_mode));
	}
	return (BLACK);
}
