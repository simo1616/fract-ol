/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 19:25:55 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/03 20:42:01 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	else
	{
		handle_arrows(keysym, fractal);
		handle_color_and_iterations(keysym, fractal);
		fractal_render(fractal);
	}
	return (0);
}
