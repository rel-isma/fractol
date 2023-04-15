# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:13:23 by rel-isma          #+#    #+#              #
#    Updated: 2023/04/15 00:55:37 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c utils.c ft_strcmp.c ft_mandelbrot.c ft_julia.c ft_mlx_hook.c ft_fractol_bonus.c ft_check_args.c
NAME = fractol
NAME_BOUNS = fractol

OBJECTS = $(SOURCES:%.c=obj/%.o)


all: $(NAME)

obj/%.o: %.c fractol.h | obj
	$(CC) $(CFLAGS) -c $< -o $@ -g

obj:
	mkdir obj

bonus: $(NAME_BOUNS)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_BOUNS): 

clean:
	rm -rf obj
fclean: clean
	rm -rf $(NAME)
re: fclean all
