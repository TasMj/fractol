# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tas <tas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:33:21 by tmejri            #+#    #+#              #
#    Updated: 2022/12/30 16:24:44 by tas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

SRCS		= burningship.c fractol.c hook_tools.c julia.c keyboard.c main.c \
			mandelbrot.c menu.c mouse.c tools.c window.c \

OBJ			= ${SRCS:.c=.o}
	
RM			= rm -f
	
CC			= gcc

FLAGS		= -Wall -Wextra -Werror -g3



all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)"
	@echo "$(GREEN)******************************************************************"
	@echo "$(GREEN)Project successfully compiled"
	@echo "$(GREEN)"
	@echo "$(GREEN)Please enter ./fractol to see the name of the available fractals."
	@echo "$(GREEN)Then enter ./fractol follow by the name of the fractal chosen."
	@echo "$(GREEN)When the window is open, press H for help."
	@echo "$(GREEN)Enjoy :) "
	@echo "$(GREEN)******************************************************************"


clean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "$(GREEN)Supressing libraries files$(CYAN)"
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean