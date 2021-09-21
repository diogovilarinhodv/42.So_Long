CC	= gcc

CFLAGS	= -Wall -Wextra -Werror -Imlx

NAME	= run

AR	= ar rc

RM	= rm -rf

OBJS	= ${SRC:.c=.o}

OBJS_MLX	= ${MLX:.c=.o}

SRC	= src/so_long.c utils/inicialization.c utils/printing_textures.c utils/reading.c gnl/get_next_line.c gnl/get_next_line_utils.c

MLX	= mlx/*.c

LIB_NAME	= so_long.a

LIB_FOLDER	= lib

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all:	| $(LIB_FOLDER) $(NAME)  

$(NAME): ${OBJS}
	${AR} ${LIB_FOLDER}/${LIB_NAME} ${OBJS} ${OBJS_MLX}
	${CC} ${CFLAGS} ${LIB_FOLDER}/${LIB_NAME} -Lmlx -lmlx -framework OpenGL -framework AppKit -o so_long

$(LIB_FOLDER):
	mkdir -p $(LIB_FOLDER)

clean:
	${RM} ${OBJS}
	${RM} ${OBJS_MLX}
	${RM} so_long

fclean:	clean
	${RM} ${LIB_FOLDER}/${LIB_NAME}
	${RM} $(LIB_FOLDER)
	
re:	fclean all

bonus: ${OBJS}
	${AR} ${LIB} ${OBJS}
	${CC} ${CFLAGS} ${LIB} -o so_long

rebonus: re bonus

.PHONY:	all bonus rebonus clean fclean re