NAME        	:=	push_swap
BONUS			:=	checker

CC          	:=	cc -Wall -Wextra -Werror -I./inc
SRC_DIR     	:=	src
OBJ_DIR     	:=	obj

CORE_SRC		:= src/core/manipulate_stacks.c \
				src/core/parsing/libft.c \
				src/core/parsing/parsing_utils.c \
				src/core/parsing/split.c \
				src/core/utils/operations.c \
				src/core/print/printf.c \
				src/core/print/prints.c

PUSH_SWAP_SRC	:= src/push_swap/main.c \
				src/push_swap/twist_it.c \
				src/push_swap/sort.c \
				src/push_swap/simple_utils.c \
				src/push_swap/medium_utils.c \
				src/push_swap/complex_utils.c \
				src/push_swap/benchmark.c \
				src/push_swap/stack_to_array.c \
				src/push_swap/ops/push_or_swap.c \
				src/push_swap/ops/rotation.c \
				src/push_swap/ops/rrotation.c \
				src/core/utils/update_planA.c \
				src/core/utils/update_planB.c \
				src/core/utils/update_stacks.c \
				src/core/utils/utils.c

CHECKER_SRC		:= src/checker/main.c \
				src/checker/get_next_line.c \
				src/checker/valid_op.c

CORE_OBJ = $(CORE_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CHECKER_OBJ = $(CHECKER_SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(CORE_OBJ) $(PUSH_SWAP_OBJ)
	$(CC) $(CORE_OBJ) $(PUSH_SWAP_OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(CORE_OBJ) $(CHECKER_OBJ)
	$(CC) $(CORE_OBJ) $(CHECKER_OBJ) -o $(BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@

clean:
	rm -f $(CORE_OBJ) $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)

fclean: clean
	rm -rf $(NAME) $(BONUS) $(OBJ_DIR)

re: fclean all