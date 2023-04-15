/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:01:09 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/15 01:16:40 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 100
# define MANDELBROT 1
# define FRACTOL_BONUS 3
# define JULIA 2
# define ON_DESTROY 17

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

	double	move_x;
	double	move_y;
	double	j_re;
	double	j_im;
	double	zoom;
	double	clr;

}			t_data;

void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			get_color(int iter, int max_iter, t_data *data);
int			render(t_data *data);
int			mous_hook(int button, int x, int y, t_data *data);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_mandelbrot(t_complex c, int max_iter);
int			ft_julia(t_complex z, int max_iter, t_data *data);
int			ft_close(t_data *data);
void		ft_maping(t_complex *z, int x, int y, t_data *data);
void		draw(t_data *data);
int			ft_key_hook(int key, t_data *data);
int			ft_fractol_bonus(t_complex c, int max_iter);
void		init(t_data *data);
void		ft_check_args(int ac, char *av[], t_data *data);
void		init(t_data *data);

#endif