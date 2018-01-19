NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
INCLUDES = -Iincludes/ -Ilibft/includes
LDLIB = -Llibft/
LDFLAGS = -lft
SRCDIR= srcs/
LIB = libft.a
LIBDIR = libft

SRC =	main.c \
		parse/checking.c \
		parse/parse.c \
		output/print_room.c \
		output/print_elem.c \
		structure/find_room.c \
		structure/free_room.c \
		structure/is_connected.c \
		structure/room_cmp.c \
		algo/dijkstra.c \
		algo/astart.c \
		algo/path_finding.c

SRC := $(addprefix $(SRCDIR), $(SRC))
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(LIBDIR)/$(LIB):
	@$(MAKE) -C $(LIBDIR)

%.o: %.c
	@zsh -c "echo -n '\tCompiling $<'"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@zsh -c 'echo -e "\r\t\033[32mCompiled $@\033[0m "'

$(NAME): $(OBJ) $(LIBDIR)/$(LIB)
	@echo "\tLinking $@"
	@$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $(OBJ) $(LDLIB) $(LDFLAGS)

clean:
	@rm -f $(OBJ) && $(MAKE) -C $(LIBDIR) clean && echo "Removed object files."

fclean: clean
	@rm -f $(NAME) && $(MAKE) -C $(LIBDIR) fclean && echo "Removed target(s)."

re: fclean $(NAME)

.PHONY: all clean fclean re $(LIBDIR)/$(LIB)
