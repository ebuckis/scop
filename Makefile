.PHONY: all clean fclean re

NAME = scop

WFLAGS = -Wall -Wextra -Werror -g
OSX_FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -Framework Appkit
GNU_FLAGS = -L minilibx_linux/ -lmlx -lm -lX11 -lXext

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
OBJ_PATH_GNU = ./obj/
MLX_MACOS = ../minilibx_macos/
MLX_LINUX = ../minilibx_linux/


SRC = $(addprefix $(SRC_PATH),$(N_SRCS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
GNU_OBJ = $(addprefix $(OBJ_PATH_GNU),$(OBJ_NAME))
INC_MACOS = -I $(MLX_MACOS) -I $(INC_PATH)
INC_LINUX = -I $(MLX_LINUX) -I $(INC_PATH) -I$(MLX_LINUX)

OBJ_NAME = $(N_SRCS:.c=.o)

N_SRCS =	main.c

all : $(NAME)

$(NAME):	$(OBJ)
			make -C $(MLX_MACOS)
			gcc $(OBJ) $(INC_MACOS) -o $(NAME)
			@printf "\033[35;5m compile OK ! \n\033[0m"

linux :		$(GNU_OBJ)
			make -C $(MLX_LINUX)
			gcc $(OBJ) -o $(NAME)
			@printf "\033[35;5m compile OK ! \n\033[0m"

$(OBJ_PATH)%.o:	$(SRC_PATH)%.c
				@mkdir -p $(OBJ_PATH)
				@gcc -c $(WFLAGS) $(OSX_FLAGS) $(INC_MACOS) -o $@ $<
				@printf "\033[45m \033[0m"

$(OBJ_PATH_GNU)%.o:	$(SRC_PATH)%.c
					mkdir -p $(OBJ_PATH_GNU)
					gcc -c $(INC_LINUX) $(WFLAGS) $(GNU_FLAGS)  -o $@ $<
					@printf "\033[45m \033[0m"

clean :
		@rm -rf $(OBJ_PATH)

fclean : 	clean
			@rm -rf $(NAME)

re : fclean clean all
