/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:59:31 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/04 16:37:16 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_ptr, fractal->win_ptr,
		fractal->img.img_ptr, 0, 0);
}

void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_pixel		pixel;
	t_complex	c;
	int			index;

	pixel.x = x;
	pixel.y = y;
	get_initial_values(pixel.x, pixel.y, fractal, &pixel.z);
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c.x = fractal->julia_x;
		c.y = fractal->julia_y;
	}
	else
	{
		c.x = pixel.z.x;
		c.y = pixel.z.y;
		pixel.z.x = 0;
		pixel.z.y = 0;
	}
	index = 0;
	calculate_fractal(&pixel.z, &c, &index, fractal);
	process_pixel_color(&pixel, index, fractal);
}

void	calculate_fractal(t_complex *z, t_complex *c,
	int *index, t_fractal *fractal)
{
	double	xtemp;

	while (*index < fractal->iteration_definition)
	{
		if (!ft_strncmp(fractal->name, "burning_ship", 12))
			process_burning_ship(&z->x, &z->y);
		xtemp = z->x * z->x - z->y * z->y + c->x;
		z->y = 2 * z->x * z->y + c->y;
		z->x = xtemp;
		if ((z->x * z->x + z->y * z->y) > fractal->escape_value)
			break ;
		(*index)++;
	}
}

void	process_pixel_color(t_pixel *pixel, int index, t_fractal *fractal)
{
	int	color;

	color = calculate_color(index, pixel->z.x, pixel->z.y, fractal);
	my_pixel_put(pixel->x, pixel->y, &fractal->img, color);
}
