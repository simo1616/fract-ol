/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:45:25 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/04 16:34:01 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_mandelbrot_burning_ship(char **av, t_fractal *fractal)
{
	fractal->name = av[1];
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_ptr);
}

void	init_julia(char **av, t_fractal *fractal)
{
	fractal->name = av[1];
	fractal->julia_x = ft_atodbl(av[2]);
	fractal->julia_y = ft_atodbl(av[3]);
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_ptr);
}
