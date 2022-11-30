// NAME			= fractol

// SRCS			= fractol.c 

// OBJS			= ${SRCS:.c=.o}

// CC				= gcc
// RM				= rm -f
// HDR_PATH		= include
// MLX 			= make -C ./minilibx-linux
// MLX_HDR			= minilibx-linux/
// CFLAGS			= -Wall -Wextra -Werror -g3 -I ${HDR_PATH} -I ${MLX_HDR}

// all:			${NAME}

// %.o: %.c
// ## A REFAIRE

// $(NAME):		$(OBJ)
				
// 				@$(CC) ${CFLAGS} ${SRCS} -L ${MLX_HDR} -lmlx_Linux -L -lXext -lX11 -lm -lz -o $(NAME)

// clean:
// 				${RM} ${OBJS}

// fclean:			clean
// 				${RM} ${NAME}

// re:				fclean ${NAME}

// .PHONY:			all clean fclean re

//222222222222

// NAME		= fractol
// 
// MLX_DIR 	= ./minilibx-linux
// 
// MLX		= ./minilibx-linux/libmlx.a
// 
// SRCS		= fractol.c
// 
// OBJS		= ${SRCS:.c=.o}
// 
// RM		= rm -f
// 
// CC		= gcc
// 
// FLAGS		= -Wall -Wextra -Werror -g3
// 
// FLAGS_LIB	= -L $(MLX)minilibx-linux -lmlx -lm -lX11 -lXext -lpthread
// 
// all		: ${NAME}
// 
// .c.o		:
		//   @${CC} ${FLAGS} -c $< -o ${<:.c=.o}
// 
// ${MLX}		:
		//   @echo "\033[35m----Building MLX----"
		//   @make -sC ${MLX_DIR}
		//   @echo "OK"
// 
// ${NAME}		: ${OBJS} ${MLX}
		//   @echo "\033[34m----Compiling----"
		//   @${CC} ${FLAGS} ${OBJS} -L ${MLX_DIR} -lmlx -lm ${FLAGS_LIB} -o ${NAME}
		//   @echo "OK"
// 
// clean		:
		//   @echo "\033[31m----Cleaning MLX----"
		//   @make clean -sC ${MLX_DIR}
		//   @echo "OK"
		//   @echo "\033[31m----Cleaning objects----"
		//   @${RM} ${OBJS}
		//   @echo "OK"
// 
// fclean		: clean
		//   @echo "\033[33m----Cleaning all----"
		//   @${RM} ${NAME}
		//   @${RM} ${LIBFT}
		//   @${RM} ${MLX}
		//   @echo "OK"
// 
// re		: fclean all
// 
// .PHONY		: all clean fclean re