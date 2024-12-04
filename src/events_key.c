/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:49:26 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/04 15:53:07 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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

void	handle_arrows(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Left)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
}

void	handle_color_and_iterations(int keysym, t_fractal *fractal)
{
	if (keysym == XK_plus || keysym == XK_KP_Add)
		fractal->color_mode = (fractal->color_mode + 1) % NUM_COLOR_SCHEMES;
	else if (keysym == XK_minus || keysym == XK_KP_Subtract)
		fractal->color_mode = (fractal->color_mode - 1 + NUM_COLOR_SCHEMES)
			% NUM_COLOR_SCHEMES;
	else if (keysym == XK_Page_Up)
		fractal->iteration_definition += 10;
	else if (keysym == XK_Page_Down)
		fractal->iteration_definition -= 10;
}

int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_ptr, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
	mlx_destroy_display(fractal->mlx_ptr);
	free(fractal->mlx_ptr);
	exit(EXIT_SUCCESS);
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
