# Standard
NAME				= push_swap

# Directories
LIBFT				= ./lib/mylib/libmylib.a
INC					= include/
SRC_DIR				= sources/
OBJ_DIR				= obj/

# Compiler and CFlags
CC          = cc
CFLAGS      = -Wall -Werror -Wextra -I$(INC)
RM          = rm -f

# $(LIBFT):
# 	@make CFLAGS="$(LIBCFLAGS)" -C ./lib/mylib

# $(NAME): $(OBJ) $(LIBFT)
# 	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME) -pie
	
# Source Files
COMMANDS_DIR		=	$(SRC_DIR)commands/moves.c \
						$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_stacks.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/handle_errors.c \
						$(SRC_DIR)push_swap/init_a_to_b.c \
						$(SRC_DIR)push_swap/init_b_to_a.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/split_utils.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/stack_utils.c

# Concatenate all source files
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR)

# Apply the pattern substitution to each source file in SRC and produce a corresponding list of object files in the OBJ_DIR
OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:
	@make all

$(LIBFT):
	@make -C ./lib/mylib

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) -L ./lib/mylib -l mylib -o $(NAME)

# Compile object files from source files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./lib/mylib

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

# Phony targets represent actions not files
.PHONY: start all clean fclean re
