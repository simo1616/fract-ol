/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 17:52:13 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/04 15:48:27 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

static void	print_error_and_exit(void)
{
	ft_putstr_fd("Please enter:\n\t"
		"\"./fractol mandelbrot\" or\n\t"
		"\"./fractol julia <value_1> <value_2>\" or\n\t"
		"\"./fractol burning_ship\"\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (ac < 2)
	{
		print_error_and_exit();
	}
	if (ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)
			|| !ft_strncmp(av[1], "burning_ship", 12)))
	{
		init_mandelbrot_burning_ship(av, &fractal);
	}
	else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	{
		init_julia(av, &fractal);
	}
	else
	{
		print_error_and_exit();
	}
	return (0);
}
