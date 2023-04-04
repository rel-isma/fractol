/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:51:52 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/04 12:32:27 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render(t_data *data)
{
	int x, y;
	
	y = 0;
	while (y < 400)
	{
		x = 0;
		while (x < 600)
		{
			if ((x > 600/2 - 50 && x < 600/2 + 50) && (y > 400/2 - 50 && y < 400/2 + 50))
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0x0000FF);
			if (sqrt(pow(600/2 - x, 2) + pow(400/2 - y, 2)) > 100)
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
	return (0);
}

int main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window");
	mlx_loop_hook(data.mlx_ptr, render, &data);
	mlx_loop(data.mlx_ptr);

}
