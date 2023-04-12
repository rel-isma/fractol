/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:21:25 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/12 23:26:59 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_hook(int key, t_data *data)
{
	if (key == 53)
		ft_close(data);
	if (key == 123)
	{
		data->move_x -= 0.3 * data->zoom;
		render(data);
	}
	if (key == 124)
	{
		data->move_x += 0.3 * data->zoom;
		render(data);
	}
	if (key == 125)
	{
		data->move_y += 0.3 * data->zoom;
		render(data);
	}
	if (key == 126)
	{
		data->move_y -= 0.3 * data->zoom;
		render(data);
	}
	return (0);
}

int	mous_hook(int button, int x, int y, t_data *data)
{
	if (button == 1 && data->fractol == 2)
	{
		data->j_re = (x - WIDTH / 2) * (4.0 / WIDTH * data->zoom)
			+ data->move_x;
		data->j_im = (y - HEIGHT / 2) * (4.0 / HEIGHT * data->zoom)
			+ data->move_y;
		render(data);
	}
	else if (button == 4)
	{
		data->zoom *= 1.5;
		render(data);
	}
	else if (button == 5)
	{
		data->zoom /= 1.5;
		render(data);
	}
	return (0);
}
