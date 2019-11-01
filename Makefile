.PHONY: all clean fclean re

NAME = scop

WFLAGS = #-Wall -Wextra -Werror
MXL_FLAGS = -framework Opengl -framework Appkit

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
MLX_PATH = ./minilibx_macos/

SRC = $(addprefix $(SRC_PATH),$(N_SRCS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = -I $(MLX_PATH) -I $(INC_PATH)  

OBJ_NAME = $(N_SRCS:.c=.o)


N_SRCS =	main.c	\
			draw.c	\
			triangle.c	\
			version.c	\
			makeShaderProgram.c		\
			makeFloatVbo.c	\
			matrices_rotation.c

all : $(NAME)

$(NAME):	$(OBJ)
			@gcc $(MXL_FLAGS) $(INC) $(OBJ) minilibx_macos/libmlx.a -o $(NAME)
			@printf "\033[34;5m Scop OK ! \n\033[0m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@gcc -c  $(INC) $(WFLAGS) -o $@ $<
				@printf "\033[44m \033[0m"

clean :
			@rm -rf $(OBJ_PATH)

fclean : 	clean
			@rm -rf $(NAME)

re : fclean clean all
