NAME = push_swap
FLAG = -Wall -Wextra -Werror

HEADER_DIR = ./includes/
HEADER = -I$(HEADER_DIR)

SRC_DIR = ./src/
SRC_LIST =	push_swap.c\
			def_data.c\
			sort_stack_a.c\
			stack_actions.c
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

all:
	clang -o $(NAME) $(HEADER) $(SRC) $(FLAG)

man:
	# clang -o qw $(HEADER) $(SRC) ./src/manual_input.c $(FLAG)
	gcc -o qw $(HEADER) $(SRC) ./src/manual_input.c
