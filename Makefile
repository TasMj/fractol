# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tas <tas@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:33:21 by tmejri            #+#    #+#              #
#    Updated: 2022/12/25 02:04:34 by tas              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

SRCS		= burningship.c fractol.c julia.c keyboard.c main.c \
			mandelbrot.c mouse.c tools.c window.c \

OBJ			= ${SRCS:.c=.o}
	
RM			= rm -f
	
CC			= gcc

FLAGS		= -Wall -Wextra -Werror -g3



all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -c $< -o $@


$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
	@echo "$(GREEN)Project successfully compiled"


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