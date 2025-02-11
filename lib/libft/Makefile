##########################################################
## ARGUMENTS

NAME = libft.a
CC = cc
FLAGS = -Wall -Wextra -Werror -g3 -I.
AR = ar
RM = rm -f

OBJ_DIR = obj

##########################################################
## SOURCES

FILES = ft_strdup.c ft_atoi.c ft_bzero.c \
		ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_strchr.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strncmp.c \
		ft_strnstr.c ft_strrchr.c ft_tolower.c \
		ft_toupper.c ft_calloc.c ft_putstr_fd.c \
		ft_putchar_fd.c ft_itoa.c ft_putnbr_fd.c \
		ft_substr.c ft_putendl_fd.c ft_strmapi.c \
		ft_strtrim.c ft_striteri.c ft_strjoin.c \
		ft_split.c

BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

ZIYADA = ft_atol.c get_next_line.c ft_strictcmp.c ft_rsubstr.c

PRINTFD = ft_printf_fd/ft_print_unsigned.c ft_printf_fd/ft_printchar.c \
          ft_printf_fd/ft_printf_fd.c ft_printf_fd/ft_printhex.c \
          ft_printf_fd/ft_printnbr.c ft_printf_fd/ft_printptr.c \
          ft_printf_fd/ft_printstr.c

# Création des fichiers objets dans obj/
OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
BOBJS = $(addprefix $(OBJ_DIR)/, $(BONUS:.c=.o))
ZIYOBJS = $(addprefix $(OBJ_DIR)/, $(ZIYADA:.c=.o))
PRINTOBJS = $(addprefix $(OBJ_DIR)/, $(PRINTFD:.c=.o))

OBJ_SUBDIRS = $(sort $(dir $(PRINTOBJS)))

##########################################################
## RULES

all: $(NAME)

# Création du dossier obj et sous-dossiers si nécessaire
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR) $(OBJ_SUBDIRS)

# Compilation avec placement des .o dans obj/
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS) $(BOBJS) $(ZIYOBJS) $(PRINTOBJS)
	$(AR) rcs $(NAME) $(OBJS) $(BOBJS) $(ZIYOBJS) $(PRINTOBJS)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

bonus: $(BOBJS) $(ZIYOBJS) $(PRINTOBJS)
	$(AR) rcs $(NAME) $(OBJS) $(BOBJS) $(ZIYOBJS) $(PRINTOBJS)

.PHONY: all clean fclean re bonus
