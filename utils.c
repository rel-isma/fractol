/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:03:58 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/12 23:31:48 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->img);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter, int max_iter)
{
	double	t;
	int		red;
	int		green;
	int		blue;

	if (iter == max_iter)
		return (0);
	t = (double)iter / max_iter;
	red = (int)(9 * (1 - t) * t * t * t * 255);
	green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((red << 16) | (green << 8) | blue);
}

void	ft_maping(t_complex *z, int x, int y, t_data *data)
{
	z->re = 0;
	z->im = 0;
	z->re = (x - WIDTH / 2) * (4.0 / WIDTH * data->zoom) + data->move_x;
	z->im = (y - HEIGHT / 2) * (4.0 / HEIGHT * data->zoom) + data->move_y;
}
