/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:51:52 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/09 02:22:05 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_mandelbrot(t_complex z, int max_iter)
{
    int i = 0;
    t_complex c = z;
    t_complex tmp;

    while (i < max_iter)
    {
        tmp.re = z.re * z.re - z.im * z.im + c.re;
        tmp.im = 2 * z.re * z.im + c.im;
        z = tmp;
        if (z.re * z.re + z.im * z.im > 4)
            break;
        i++;
    }
    return i;
}

void    ft_maping(t_complex z, int x, int y, t_data *data)
{
    z.re = data->xmin + x * (data->xmax - data->xmin) / (double) WIDTH;
    z.im = data->ymin + y * (data->ymax - data->ymin) / (double) HEIGHT;
}

void draw(t_data *data)
{
    int x, y;
    int iter;
    t_complex z = {0, 0};

    y = 0; 
    while (y < HEIGHT)
    {
        x = 0; 
        while(x < WIDTH)
        {
            ft_maping(z, x, y, data);
            if (data->fractol == 1)
            {
                iter = ft_mandelbrot(z, data->max_iter);
                my_mlx_pixel_put(data, x, y, get_color(iter, data->max_iter));
            }
            x++;
        }
        y++;
    }
    mlx_clear_window(data->mlx, data->win);
    mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int render(t_data *data)
{
    draw(data);
    return (0);
}

void create_window(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
            &(data->line_length), &(data->endian));
    mlx_loop_hook(data->mlx, render, data);
    mlx_loop(data->mlx);
}

void    init(t_data *data)
{
    data->xmax = 2;
    data->xmin = -2;
    data->ymax = 2;;
    data->ymin = -2;
    data->max_iter = 100;
    
}

void    check_args(int ac, char *av[], t_data *data)
{
    if (ac == 1)
        exit(1);
    if (strcmp(av[2], "mandelbrot") == 0)
        data->fractol = MANDELBROT;
    if (strcmp(av[2], "julia") == 0)
        data->fractol = JULIA;
}
int main(int ac, char *av[])
{
    t_data  data;

    check_args(ac, av, &data);
    init(&data);
    create_window(&data);
    
    return 0;
}
