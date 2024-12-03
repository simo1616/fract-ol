/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:13 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/03 20:42:12 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	init_mandelbrot_burning_ship(char **av, t_fractal *fractal)
{
	fractal->name = av[1];
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_ptr);
}

static void	init_julia(char **av, t_fractal *fractal)
{
	fractal->name = av[1];
	fractal->julia_x = ft_atodbl(av[2]);
	fractal->julia_y = ft_atodbl(av[3]);
	fractal_init(fractal);
	fractal_render(fractal);
	mlx_loop(fractal->mlx_ptr);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)
			|| !ft_strncmp(av[1], "burning_ship", 12)))
		init_mandelbrot_burning_ship(av, &fractal);
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
		init_julia(av, &fractal);
	else
	{
		ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
