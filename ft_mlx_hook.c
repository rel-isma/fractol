/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:21:25 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/15 02:50:54 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_julia(int x, int y, t_data *data)
{
	data->j_re = (x - WIDTH / 2) * (4.0 / WIDTH * data->zoom) + data->move_x;
	data->j_im = (y - HEIGHT / 2) * (4.0 / HEIGHT * data->zoom) + data->move_y;
}

int	ft_key_hook(int key, t_data *data)
{
	if (key == 38)
		data->fractol = JULIA;
	if (key == 46)
		data->fractol = MANDELBROT;
	if (key == 11)
		data->fractol = FRACTOL_BONUS;
	if (key == 49)
		data->clr += 1;
	if (key == 3)
		init(data);
	if (key == 53)
		ft_close(data);
	if (key == 123)
		data->move_x -= 0.3 * data->zoom;
	if (key == 124)
		data->move_x += 0.3 * data->zoom;
	if (key == 125)
		data->move_y += 0.3 * data->zoom;
	if (key == 126)
		data->move_y -= 0.3 * data->zoom;
	render(data);
	return (0);
}

int	mous_hook(int button, int x, int y, t_data *data)
{
	t_complex	old_m;
	t_complex	new_m;

	ft_maping(&old_m, x, y, data);
	if (button == 1 && data->fractol == 2)
		ft_init_julia(x, y, data);
	else if (button == 4)
	{
		data->zoom *= 1.2;
		ft_maping(&new_m, x, y, data);
		data->move_x += old_m.re - new_m.re;
		data->move_y += old_m.im - new_m.im;
	}
	else if (button == 5)
	{
		data->zoom *= 0.8;
		ft_maping(&new_m, x, y, data);
		data->move_x += old_m.re - new_m.re;
		data->move_y += old_m.im - new_m.im;
	}
	render(data);
	return (0);
}
