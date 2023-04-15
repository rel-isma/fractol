/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:51:52 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/15 02:47:18 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw(t_data *data)
{
	int			iter;
	t_complex	z;
	int			x;
	int			y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_maping(&z, x, y, data);
			if (data->fractol == MANDELBROT)
				iter = ft_mandelbrot(z, data->max_iter);
			else if (data->fractol == JULIA)
				iter = ft_julia(z, data->max_iter, data);
			else if (data->fractol == FRACTOL_BONUS)
				iter = ft_fractol_bonus(z, data->max_iter);
			my_mlx_pixel_put(data, x, y, get_color(iter, data->max_iter, data));
			x++;
		}
		y++;
	}
}

int	render(t_data *data)
{
	draw(data);
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	create_window(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
			&(data->line_length), &(data->endian));
}

int	main(int ac, char *av[])
{
	t_data	data;

	ft_check_args(ac, av, &data);
	init(&data);
	create_window(&data);
	render(&data);
	mlx_hook(data.win, 2, 0, ft_key_hook, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_mouse_hook(data.win, mous_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
