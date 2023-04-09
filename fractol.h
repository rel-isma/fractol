/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:01:09 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/09 02:04:04 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define WIDTH 500
# define HEIGHT 500
# define MAX_ITERATIONS 100
# define MANDELBROT 1
# define JULIA 2
typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		fractol;
	int		max_iter;

	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
}			t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int         get_color(int iter, int max_iter);

#endif