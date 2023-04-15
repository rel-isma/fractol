/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:03:58 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/15 01:07:01 by rel-isma         ###   ########.fr       */
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

int	get_color(int iter, int max_iter, t_data *data)
{
	int	color_final;

	if (iter == max_iter)
		return (0);
	max_iter = max_iter + data->clr;
	color_final = iter * (0x00ffff / max_iter << 1);
	return (color_final);
}

void	ft_maping(t_complex *z, int x, int y, t_data *data)
{
	z->re = (x - WIDTH / 2) * (4.0 / WIDTH * data->zoom) + data->move_x;
	z->im = (y - HEIGHT / 2) * (4.0 / HEIGHT * data->zoom) + data->move_y;
}

void	init(t_data *data)
{
	data->move_x = 0;
	data->move_y = 0;
	data->max_iter = 100;
	data->j_re = 0;
	data->j_im = 0.8;
	data->zoom = 1;
	data->clr = 1;
}
