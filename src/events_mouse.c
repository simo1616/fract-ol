/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_mouse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:53:42 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/04 16:35:57 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	double		mouse_re;
	double		mouse_im;
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
	mouse_re = map(args_x);
	mouse_im = map(args_y);
	zoom_in_out(button, mouse_re, mouse_im, fractal);
	fractal_render(fractal);
	return (0);
}

int	julia_track(int x, int y, t_fractal *fractal)
{
	t_map_args	args_x;
	t_map_args	args_y;

	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		args_x.index = x;
		args_x.new_min = -2.0;
		args_x.new_max = +2.0;
		args_x.old_min = 0.0;
		args_x.old_max = WIDTH;
		args_y.index = y;
		args_y.new_min = 2.0;
		args_y.new_max = -2.0;
		args_y.old_min = 0.0;
		args_y.old_max = HEIGHT;
		fractal->julia_x = map(args_x) * fractal->zoom + fractal->shift_x;
		fractal->julia_y = map(args_y) * fractal->zoom + fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}

void	zoom_in_out(int button, double mouse_re, double mouse_im,
	t_fractal *fractal)
{
	double	zoom_factor;

	if (button == Button4)
	{
		zoom_factor = 0.9;
		fractal->zoom *= zoom_factor;
		fractal->shift_x = mouse_re - (mouse_re - fractal->shift_x)
			* zoom_factor;
		fractal->shift_y = mouse_im - (mouse_im - fractal->shift_y)
			* zoom_factor;
	}
	else if (button == Button5)
	{
		zoom_factor = 1.0 / 0.9;
		fractal->zoom *= zoom_factor;
		fractal->shift_x = mouse_re - (mouse_re - fractal->shift_x)
			* zoom_factor;
		fractal->shift_y = mouse_im - (mouse_im - fractal->shift_y)
			* zoom_factor;
	}
}
