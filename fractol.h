/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 21:01:09 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/04 12:31:47 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H


#include <stdlib.h>
#include <mlx.h>
#include <math.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 400

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
}	t_data;


#endif