# Compiler
CC					=		gcc

# Flags for Compiler
C_FLAGS				=		-Wall -Wextra -Werror
MLX_FLAGS 			=		-Imlx -lmlx -framework OpenGL -framework AppKit
NAME_FLAG 			=		-o
OBJ_FLAG 			=		-c

# Command for Library
AR					=		ar rc

# Folder Management
RM					=		rm -rf
CREATE_FOLDER 		= 		mkdir -p

# Norminette
NORM 				= 		norminette

# Library directory
LIB_FOLDER			= 		lib

# Files
LIB_FILE			= 		so_long.a
HEADER_FILES		= 		src/so_long.h
OBJ_FILES			= 		${SRC_FILES:.c=.o}
SRC_FILES			= 		src/so_long.c \
							utils/inicialization.c \
							utils/printing_textures.c \
							utils/reading.c \
							utils/movement.c \
							utils/gameover.c \
							utils/events.c \
							utils/enemy_animation.c \
							utils/enemy_movement.c \
							utils/error_handling/error.c \
							utils/error_handling/error_printing.c \
							utils/error_handling/error_reading.c \
							libft/ft_itoa.c \
							gnl/get_next_line.c \
							gnl/get_next_line_utils.c

# Name of executable file
EXECUTABLE_NAME 	= 		so_long

# Convert C Files to Object Files
.c.o:
					${CC} ${C_FLAGS} $(OBJ_FLAG) $< $(NAME_FLAG) ${<:.c=.o}

# all
all:				$(EXECUTABLE_NAME)  

# Build Project
$(EXECUTABLE_NAME): ${OBJ_FILES}
					$(CREATE_FOLDER) $(LIB_FOLDER)
					${AR} ${LIB_FOLDER}/${LIB_FILE} ${OBJ_FILES}
					${CC} ${C_FLAGS} ${LIB_FOLDER}/${LIB_FILE} $(MLX_FLAGS) $(NAME_FLAG) $(EXECUTABLE_NAME) 

# Norminette
norm:
					$(NORM) $(HEADER_FILES) $(SRC_FILES)

# Clean Project
clean:
					${RM} ${OBJ_FILES}
					${RM} $(EXECUTABLE_NAME)

fclean:				clean
					${RM} ${LIB_FOLDER}/${LIB_FILE}
					${RM} $(LIB_FOLDER)

# Clean and Build Project
re:					fclean all

# Bonus Commands
bonus: 				${OBJ_FILES}
					${AR} ${LIB_FOLDER}/${LIB_FILE} ${OBJ_FILES}
					${CC} ${C_FLAGS} ${LIB_FOLDER}/${LIB_FILE} $(MLX_FLAGS) $(NAME_FLAG) $(EXECUTABLE_NAME) 

rebonus: 			re bonus

# Phony (I dont remember what this do, i think is to reserve the name or something like that)
.PHONY:				all norm bonus rebonus clean fclean re
