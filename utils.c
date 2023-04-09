/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:03:58 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/09 01:56:56 by rel-isma         ###   ########.fr       */
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
    int r, g, b;

    if (iter == max_iter)
        return 0;
    r = iter % 256;
    g = (iter * 2) % 256;
    b = (iter * 4) % 256;
    return (r << 16) | (g << 8) | b;
}

