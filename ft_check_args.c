/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:50:52 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/15 00:51:28 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_check_args(int ac, char *av[], t_data *data)
{
	if (ac != 2)
	{
		write(2, "Error : Like this\n \
		./fractol ( mandelbrot or julia )\n", 55);
		exit(1);
	}
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		data->fractol = MANDELBROT;
	else if (ft_strcmp(av[1], "julia") == 0)
		data->fractol = JULIA;
	else if (ft_strcmp(av[1], "fractol_bonus") == 0)
		data->fractol = FRACTOL_BONUS;
	else
	{
		write(2, "3nadk ghalt fktaba (^_^)\n", 25);
		exit(1);
	}
}
