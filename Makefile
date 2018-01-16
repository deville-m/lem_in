NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = includes/
SRCDIR= srcs/

SRC =	main.c \
\
		structures/add_back.c \
		structures/add_elem.c \
		structures/del_list.c \
		structures/find_room.c \
		structures/new_elem.c \
		structures/r_rotate.c \
		structures/rotate.c \
\
		utilities/ft_strcmp.c \
		utilities/ft_strcpy.c \
		utilities/ft_strlen.c \
		utilities/ft_strdup.c \
		utilities/ft_strnew.c \
		utilities/ft_memalloc.c \
		utilities/get_next_line.c


SRC := $(addprefix $(SRCDIR), $(SRC))
OBJ := $(SRC:.c=.o)

%.o: %.c
	@zsh -c "echo -n '\tCompiling $<'"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@
	@zsh -c 'echo -e "\r\t\033[32mCompiled $@\033[0m "'

$(NAME): $(OBJ)
	@echo "\tLinking $@"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $^

clean:
	@rm -f $(OBJ) && echo "Removed object files."

fclean: clean
	@rm -f $(NAME) && echo "Removed target(s)."

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re
