/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:09:12 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/03 21:14:08 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_size) + (x * img->bpp / 8);
	*(unsigned int *)(img->pixel_ptr + offset) = color;
}

void	process_burning_ship(double *zx, double *zy)
{
	*zx = fabs(*zx);
	*zy = fabs(*zy);
}

void	get_initial_values(int x, int y, t_fractal *fractal, t_complex *z)
{
	t_map_args	args_x;
	t_map_args	args_y;

	args_x.index = x;
	args_x.new_min = -2.0 * fractal->zoom + fractal->shift_x;
	args_x.new_max = +2.0 * fractal->zoom + fractal->shift_x;
	args_x.old_min = 0.0;
	args_x.old_max = WIDTH;
	args_y.index = y;
	args_y.new_min = -2.0 * fractal->zoom + fractal->shift_y;
	args_y.new_max = +2.0 * fractal->zoom + fractal->shift_y;
	args_y.old_min = 0.0;
	args_y.old_max = HEIGHT;
	z->x = map(args_x);
	z->y = map(args_y);
}

int	calculate_color(int iteration, double zx, double zy, t_fractal *fractal)
{
	double	log_zn;
	double	nu;
	double	smooth_index;

	if (iteration < fractal->iteration_definition)
	{
		log_zn = log(zx * zx + zy * zy) / 2.0;
		nu = log(log_zn / log(2.0)) / log(2.0);
		smooth_index = iteration + 1 - nu;
		return (get_color(smooth_index, fractal->iteration_definition,
				fractal->color_mode));
	}
	return (BLACK);
}
