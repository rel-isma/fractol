/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 23:34:48 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/15 00:47:30 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_fractol_bonus(t_complex c, int max_iter)
{
	int			i;
	t_complex	z;
	t_complex	tmp;

	i = 0;
	z.im = 0;
	z.re = 0;
	while (i < max_iter && (z.re * z.re + z.im * z.im) < 4)
	{
		tmp.re = z.re * z.re * z.re - 3 * z.re * z.im * z.im + c.re;
		tmp.im = 3 * z.re * z.re * z.im - z.im * z.im * z.im + c.im;
		z = tmp;
		i++;
	}
	return (i);
}
