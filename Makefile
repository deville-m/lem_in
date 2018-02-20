NAME = lem-in
CC = gcc
CFLAGS = -Wall -Wextra -O3
INCLUDES = -Iincludes/ -Ilibft/includes
LDLIB = -Llibft/
LDFLAGS = -lft
SRCDIR= srcs/
LIB = libft.a
LIBDIR = libft

SRC =	main.c \
		log.c \
		parse/checking.c \
		parse/parse_connexions.c \
		parse/parse.c \
		output/print_room.c \
		output/print_elem.c \
		output/print_path.c \
		structure/find_room.c \
		structure/free_room.c \
		structure/is_connected.c \
		structure/disconnect.c \
		structure/reconnect.c \
		structure/room_cmp.c \
		algo/dijkstra.c \
		algo/path_finding.c \
		algo/generate.c \
		algo/solve.c \
		algo/score.c \
		algo/lem_in.c\
		algo/group.c \
		algo/alreadyfound.c \
		algo/path_cmp.c \
		algo/prepare.c \
		algo/tab.c \
		algo/ft_strclen.c \
		algo/apply.c \
		algo/get_path.c

SRC := $(addprefix $(SRCDIR), $(SRC))
OBJ := $(SRC:.c=.o)

all: $(NAME)

$(LIBDIR)/$(LIB):
	@$(MAKE) -j8 -C $(LIBDIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBDIR)/$(LIB)
	$(CC) $(CFLAGS) -I$(INCLUDES) -o $@ $(OBJ) $(LDLIB) $(LDFLAGS)

clean:
	rm -f $(OBJ) && $(MAKE) -C $(LIBDIR) clean && echo "Removed object files."

fclean: clean
	rm -f $(NAME) && $(MAKE) -C $(LIBDIR) fclean && echo "Removed target(s)."

re: fclean $(NAME)

.PHONY: all clean fclean re
