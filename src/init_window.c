/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:53:49 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/03 20:42:09 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	window_init(t_fractal *fractal)
{
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->win_ptr)
	{
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
}

void	image_init(t_fractal *fractal)
{
	fractal->img.img_ptr = mlx_new_image(fractal->mlx_ptr, WIDTH, HEIGHT);
	if (!fractal->img.img_ptr)
	{
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
	fractal->img.pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr,
			&fractal->img.bpp, &fractal->img.line_size, &fractal->img.endian);
	if (!fractal->img.pixel_ptr)
	{
		mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		mlx_destroy_display(fractal->mlx_ptr);
		free(fractal->mlx_ptr);
		malloc_error();
	}
}

void	events_init(t_fractal *fractal)
{
	mlx_hook(fractal->win_ptr, KeyPress, KeyPressMask, key_handler, fractal);
	mlx_hook(fractal->win_ptr, ButtonPress, ButtonPressMask, mouse_handler,
		fractal);
	mlx_hook(fractal->win_ptr, DestroyNotify, StructureNotifyMask,
		close_handler, fractal);
	mlx_hook(fractal->win_ptr, MotionNotify, PointerMotionMask, julia_track,
		fractal);
}
