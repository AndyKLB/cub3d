#######################################################
## ARGUMENTS
LIBFT_PATH = ./lib/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a

MLX_PATH = ./lib/mlx
MLX_LIB	= $(MLX_PATH)/libmlx.a

NAME = cub3d

CC = cc
RM = rm -f
FLAG = -Wall -Wextra -Werror -g3
MLX_FLAG = -lX11 -lXext

#######################################################
## SOURCES
SRCS_FILES = parsing.c cub3d.c check_elements_order.c data_init.c free.c map_reader.c \
			 utils.c get_textures.c get_textures_utils1.c get_textures_utils2.c game_init.c \
			 print_data.c parsing_utils.c map_reader_utils.c \

SRCS_DIR = srcs
OBJ_DIR = obj

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJECTS = $(addprefix $(OBJ_DIR)/, $(SRCS_FILES:.c=.o))

#######################################################
## RULES
all: $(NAME)

# Création du dossier obj si nécessaire et compilation des .c en .o dans obj/
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(FLAG) -c $< -o $@

# Création du dossier obj si non existant
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJECTS)
	$(CC) $(FLAG) $(OBJECTS) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAG) -o $(NAME)

$(LIBFT_LIB):	
	$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
	$(MAKE) -C $(MLX_PATH)

clean:
	$(MAKE) -C $(LIBFT_PATH) clean
	$(MAKE) -C $(MLX_PATH) clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
