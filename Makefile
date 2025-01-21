#######################################################
## ARGUMENTS
LIBFT_PATH = ./lib/libft
LIBFT_LIB = $(LIBFT_PATH)/libft.a


MLX_PATH = ./lib/mlx
MLX_LIB	= $(MLX_PATH)/libmlx.a

NAME	= cub3d

CC	= cc
RM = rm -f
FLAG	= -Wall -Wextra -Werror -g3
MLX_FLAG	= -lX11 -lXext

#######################################################
## SOURCES
SRCS_FILES = parsing.c cub3d.c check_elements_order.c data_init.c \

			
SRCS_DIR = srcs

SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

OBJECTS = $(SRCS:.c=.o)

#######################################################
## RULES
all:	$(NAME)

.c.o:
				$(CC) $(FLAG) -c $< -o $(<:.c=.o)

$(NAME):	$(LIBFT_LIB)  $(MLX_LIB) $(OBJECTS)
				$(CC) $(FLAG) $(OBJECTS) $(LIBFT_LIB)  $(MLX_LIB) $(MLX_FLAG) -o $(NAME)


$(LIBFT_LIB):	
				$(MAKE) -C $(LIBFT_PATH)

$(MLX_LIB):
				$(MAKE) -C $(MLX_PATH)
				

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(MAKE) -C $(MLX_PATH) clean
				$(RM) $(OBJECTS)
				

fclean:		clean 
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)


re:		fclean all


.PHONY: all clean  fclean  re