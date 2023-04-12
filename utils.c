/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:03:58 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/12 03:38:26 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int get_color(int iter, int max_iter)
{
    if (iter == max_iter)
        return 0;
    double t = (double)iter / max_iter;
    int red = (int)(9 * (1 - t) * t * t * t * 255);
    int green = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
    int blue = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);

    return (red << 16) | (green << 8) | blue;
}

int mous_hook(int button, int x, int y, t_data *data)
{
    if (button == 1 && data->fractol == 2)
    {
        data->j_re = data->xmin + x * (data->xmax - data->xmin) / WIDTH;
    	data->j_im = data->ymin + y * (data->ymax - data->ymin) / HEIGHT;
		render(data);
    }
	else if (button == 4)
	{
		data->zoom += 1.5;
		render(data);
	}
	else if (button == 5)
	{
		data->zoom /= 1.5;
		render(data);
	}
	return (0);
}
