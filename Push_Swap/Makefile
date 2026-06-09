NAME = push_swap
BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

INC = -Iinc

CORE_SRC = \
src/core/manipulate_stacks.c
src/core/operations/op_swap.c \
src/core/operations/op_push.c \
src/core/operations/op_rotate.c \
src/core/operations/op_reverse_rotate.c \
src/core/parsing/parse_args.c \
src/core/parsing/validate.c \
src/core/parsing/duplicates.c \
src/core/parsing/split_args.c \
src/core/utils/ft_atoi.c \
src/core/utils/ft_split.c \
src/core/utils/ft_strdup.c \
src/core/utils/ft_strlen.c \
src/core/utils/ft_strncmp.c \
src/core/utils/memory.c

PUSH_SWAP_SRC = \
src/push_swap/main.c \
src/push_swap/sort.c \
src/push_swap/sort_three.c \
src/push_swap/sort_simple.c \
src/push_swap/sort_medium.c \
src/push_swap/sort_complex.c \
src/push_swap/sort_adaptive.c \
src/push_swap/update_plan_a.c \
src/push_swap/update_plan_b.c \
src/push_swap/ranking.c \
src/push_swap/benchmark.c \
src/print/print.c

CHECKER_SRC = \
src/checker/main.c \
src/checker/checker.c \
src/checker/apply_ops.c \
src/checker/gnl.c \
src/print/print.c

OBJ = $(CORE_SRC:.c=.o) $(PUSH_SWAP_SRC:.c=.o)
OBJ_BONUS = $(CORE_SRC:.c=.o) $(CHECKER_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

re: fclean all