/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbendidi <mbendidi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:51:13 by mbendidi          #+#    #+#             */
/*   Updated: 2024/12/04 16:53:02 by mbendidi         ###   ########.fr       */
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

# define WIDTH 1980
# define HEIGHT 1600
# define NUM_COLOR_SCHEMES 2

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

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

int			main(int ac, char **av);
void		fractal_init(t_fractal *fractal);
void		data_init(t_fractal *fractal);
void		malloc_error(void);
void		init_mandelbrot_burning_ship(char **av, t_fractal *fractal);
void		init_julia(char **av, t_fractal *fractal);
int			key_handler(int keysym, t_fractal *fractal);
void		handle_arrows(int keysym, t_fractal *fractal);
void		handle_color_and_iterations(int keysym, t_fractal *fractal);
int			close_handler(t_fractal *fractal);
void		events_init(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);
int			julia_track(int x, int y, t_fractal *fractal);
void		zoom_in_out(int button, double mouse_re, double mouse_im,
				t_fractal *fractal);
void		fractal_render(t_fractal *fractal);
void		handle_pixel(int x, int y, t_fractal *fractal);
void		calculate_fractal(t_complex *z, t_complex *c, int *index,
				t_fractal *fractal);
void		process_pixel_color(t_pixel *pixel, int index, t_fractal *fractal);
void		my_pixel_put(int x, int y, t_img *img, int color);
void		get_initial_values(int x, int y, t_fractal *fractal, t_complex *z);
void		process_burning_ship(double *zx, double *zy);
double		ft_atodbl(char *s);
long		ft_atodbl_part1(char *s, int *i);
double		ft_atodbl_part2(char *s, int *i);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
void		ft_putstr_fd(char const *s, int fd);
double		map(t_map_args args);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
int			get_color(int iteration, int max_iteration, int color_mode);
void		ft_get_color_scheme(double t, int color_mode, t_color *color);
int			calculate_color(int iter, double zx, double zy, t_fractal *fractal);
void		window_init(t_fractal *fractal);
void		image_init(t_fractal *fractal);

#endif
