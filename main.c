/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 21:51:52 by rel-isma          #+#    #+#             */
/*   Updated: 2023/04/12 03:30:21 by rel-isma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int ft_julia(t_complex z, t_complex c, int max_iter)
{
    int i = 0;
    t_complex tmp;

    while (i < max_iter && (z.re * z.re + z.im * z.im) < 4)
    {
        tmp.re = z.re * z.re - z.im * z.im + c.re;
        tmp.im = 2 * z.re * z.im + c.im;
        z = tmp;
        i++;
    }
    return i;
}

int ft_mandelbrot(t_complex c, int max_iter)
{
    int i = 0;
    t_complex z;
    t_complex tmp;

    z.im = 0;
    z.re = 0;
    while (i < max_iter && (z.re * z.re + z.im * z.im) < 4)
    {
        tmp.re = z.re * z.re - z.im * z.im + c.re;
        tmp.im = 2 * z.re * z.im + c.im;
        z = tmp;
        i++;
    }
    return i;
}

void ft_maping(t_complex *z, int x, int y, t_data *data)
{
    z->re = (x - WIDTH / 2) * (4.0 / WIDTH * data->zoom);
	z->im = (y - HEIGHT / 2) * (3.0 / HEIGHT * data->zoom);
}

void draw(t_data *data)
{
    int x, y;
    int iter;
    t_complex z = {0, 0};
    t_complex c;

    y = 0; 
    while (y < HEIGHT)
    {
        x = 0; 
        while(x < WIDTH)
        {
            ft_maping(&z, x, y, data);
            if (data->fractol == MANDELBROT)
                iter = ft_mandelbrot(z, data->max_iter);
            else if (data->fractol == JULIA)
            {
                c.re = data->j_re;
                c.im = data->j_im;
                iter = ft_julia(z, c, data->max_iter);
            }
            my_mlx_pixel_put(data, x, y, get_color(iter, data->max_iter));
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

int    ft_close(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_image(data->mlx, data->img);
    exit(0);
}

int ft_key_hook(int key, t_data *data)
{
    if (key == 53)
        ft_close(data);
    return (0);
}


void create_window(t_data *data)
{
    data->mlx = mlx_init();
    data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "Fract'ol");
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &(data->bits_per_pixel),
            &(data->line_length), &(data->endian));
}

void    init(t_data *data)
{
    data->xmax = 2;
    data->xmin = -2;
    data->ymax = 2;
    data->ymin = -2;
    data->max_iter = 100;
    data->j_re = -0.8;
    data->j_im = 0.156;
    data->zoom = 1;
}

void    check_args(int ac, char *av[], t_data *data)
{
    if (ac != 2)
        exit(1);
    if (strcmp(av[1], "mandelbrot") == 0)
        data->fractol = MANDELBROT;
    else if (strcmp(av[1], "julia") == 0)
        data->fractol = JULIA;
    else
        exit(1);
}

void    fun()
{
    system("leaks fractol");
}

int main(int ac, char *av[])
{
    t_data  data;

    //atexit(fun);
    check_args(ac, av, &data);
    init(&data);
    create_window(&data);
    
    mlx_loop_hook(data.mlx, render, &data);
    mlx_hook(data.win, 2, 0, ft_key_hook, &data);
    mlx_hook(data.win, 17, 0, ft_close, &data);
    mlx_mouse_hook(data.win, mous_hook, &data);
    mlx_loop(data.mlx);
    return 0;
}
