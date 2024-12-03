/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 21:23:07 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/03 21:25:50 by mbendidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define ERROR_MESSAGE "Please enter:\n\t" \
"\"./fractol mandelbrot\" or\n\t" \
"\"./fractol julia <value_1> <value_2>\" or\n\t" \
"\"./fractol burning_ship\"\n"

# define WIDTH 1980
# define HEIGHT 1600
# define NUM_COLOR_SCHEMES 2

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF
# define GRAY 0x808080
# define ORANGE 0xFFA500
# define PURPLE 0x800080
# define PINK 0xFFC0CB
# define BROWN 0xA52A2A
# define TEAL 0x008080
# define GOLD 0xFFD700
# define INDIGO 0x4B0082
# define SALMON 0xFA8072
# define TURQUOISE 0x40E0D0
# define CORAL 0xFF7F50
# define NAVY 0x000080
# define LIME 0x32CD32
# define BEIGE 0xF5F5DC
# define MINT 0x98FF98
# define PEACH 0xFFDAB9
# define LAVENDER 0xE6E6FA
# define SKY_BLUE 0x87CEEB
# define FOREST_GREEN 0x228B22
# define CRIMSON 0xDC143C
# define AMETHYST 0x9966CC
# define AQUA 0x00FFFF
# define FUCHSIA 0xFF00FF
# define LIGHT_BLUE 0xADD8E6
# define LIGHT_GREEN 0x90EE90
# define LIGHT_CORAL 0xF08080
# define LIGHT_YELLOW 0xFFFFE0
# define LIGHT_PINK 0xFFB6C1
# define LIGHT_GOLD 0xFFFACD
# define LIGHT_PURPLE 0xD8BFD8
# define LIGHT_GRAY 0xD3D3D3

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixel_ptr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	double	escape_value;
	int		iteration_definition;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
	int		color_mode;
}	t_fractal;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_map_args
{
	double	index;
	double	new_min;
	double	new_max;
	double	old_min;
	double	old_max;
}	t_map_args;

typedef struct s_pixel
{
	int			x;
	int			y;
	t_complex	z;
}	t_pixel;

void	fractal_init(t_fractal *fractal);
void	fractal_render(t_fractal *fractal);
double	map(t_map_args args);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int		key_handler(int keysym, t_fractal *fractal);
int		close_handler(t_fractal *fractal);
int		mouse_handler(int button, int x, int y, t_fractal *fractal);
double	ft_atodbl(char *s);
int		julia_track(int x, int y, t_fractal *fractal);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
int		get_color(int iteration, int max_iteration, int color_mode);
long	ft_atodbl_part1(char *s, int *i);
double	ft_atodbl_part2(char *s, int *i);
void	handle_arrows(int keysym, t_fractal *fractal);
void	handle_color_and_iterations(int keysym, t_fractal *fractal);
void	ft_get_color_scheme(double t, int color_mode, t_color *color);
void	my_pixel_put(int x, int y, t_img *img, int color);
void	process_burning_ship(double *zx, double *zy);
void	get_initial_values(int x, int y, t_fractal *fractal, t_complex *z);
int		calculate_color(int iteration, double zx, double zy, t_fractal *fractal);
void	window_init(t_fractal *fractal);
void	image_init(t_fractal *fractal);
void	events_init(t_fractal *fractal);
void	handle_pixel(int x, int y, t_fractal *fractal);
void	malloc_error(void);

#endif
