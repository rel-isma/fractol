# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rel-isma <rel-isma@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 12:13:23 by rel-isma          #+#    #+#              #
#    Updated: 2023/04/04 12:25:32 by rel-isma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Wextra -Werror -Imlx

SOURCES = main.c
NAME = FRACT

OBJECTS = $(SOURCES:%.c=%.o)


# NAME = push_swap

# LIBFT_PATH  = ./libft
# LIBFT_NAME  = ft

all: $(NAME)

# libft:
# 	make -C $(LIBFT_PATH)

%.o: %.c push_swap.h
	$(CC)  $(CFLAGS) -c $< -o $@

# bonus: libft $(NAME_CH)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
clean:
	rm -rf $(OBJECTS)
#   make clean -C $(LIBFT_PATH)

fclean: clean
	rm -rf $(NAME)
#   make fclean -C $(LIBFT_PATH)

re: fclean all
