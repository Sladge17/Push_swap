NAME = push_swap
FLAG = -Wall -Wextra -Werror

HEADER_DIR = ./includes/
HEADER = -I$(HEADER_DIR)

SRC_DIR = ./src/
SRC_LIST =	push_swap.c\
			stack_actions.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

all:
	# clang -o $(NAME) $(HEADER) $(SRC) $(FLAG)
	clang -o $(NAME) $(HEADER) $(SRC)

man:
	clang -o qw $(HEADER) $(SRC) ./src/manual_input.c $(FLAG)
