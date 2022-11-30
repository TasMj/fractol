# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmejri <tmejri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 16:33:21 by tmejri            #+#    #+#              #
#    Updated: 2022/11/30 13:28:36 by tmejri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol

MLX_DIR 	= ./minilibx-linux

MLX		= ./minilibx-linux/libmlx.a

SRCS		= 

OBJS		= ${SRCS:.c=.o}

RM		= rm -f

CC		= gcc

FLAGS		= -Wall -Wextra -Werror -g3

FLAGS_LIB	= -lXext -lX11

all		: ${NAME}

.c.o		:
		  @${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${MLX}		:
		  @echo "\033[35m----Building MLX----"
		  @make -sC ${MLX_DIR}
		  @echo "OK"

${NAME}		: ${OBJS} ${MLX}
		  @echo "\033[34m----Compiling----"
		  @${CC} ${FLAGS} ${OBJS} -L ${MLX_DIR} -lmlx -lm ${FLAGS_LIB} -o ${NAME}
		  @echo "OK"

clean		:
		  @echo "\033[31m----Cleaning MLX----"
		  @make clean -sC ${MLX_DIR}
		  @echo "OK"
		  @echo "\033[31m----Cleaning objects----"
		  @${RM} ${OBJS}
		  @echo "OK"

fclean		: clean
		  @echo "\033[33m----Cleaning all----"
		  @${RM} ${NAME}
		  @${RM} ${LIBFT}
		  @${RM} ${MLX}
		  @echo "OK"

re		: fclean all

.PHONY		: all clean fclean re