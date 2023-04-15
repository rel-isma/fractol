/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:11:22 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/15 01:16:22 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_julia(t_complex z, int max_iter, t_data *data)
{
	int			i;
	t_complex	tmp;
	t_complex	c;

	c.re = data->j_re;
	c.im = data->j_im;
	i = 0;
	while (i < max_iter && (z.re * z.re + z.im * z.im) < 4)
	{
		tmp.re = z.re * z.re - z.im * z.im + c.re;
		tmp.im = 2 * z.re * z.im + c.im;
		z = tmp;
		i++;
	}
	return (i);
}
