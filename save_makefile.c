NAME			= fractol

SRCS			= fractol.c 

OBJS			= ${SRCS:.c=.o}

CC				= gcc
RM				= rm -f
HDR_PATH		= include
MLX 			= make -C ./minilibx-linux
MLX_HDR			= minilibx-linux/
CFLAGS			= -Wall -Wextra -Werror -g3 -I ${HDR_PATH} -I ${MLX_HDR}

all:			${NAME}

%.o: %.c
## A REFAIRE

$(NAME):		$(OBJ)
				
				@$(CC) ${CFLAGS} ${SRCS} -L ${MLX_HDR} -lmlx_Linux -L -lXext -lX11 -lm -lz -o $(NAME)

clean:
				${RM} ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean ${NAME}

.PHONY:			all clean fclean re