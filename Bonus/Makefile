NAME = push_swap
NAME_BONUS = checker

SRCS = push_swap.c ft_strjoin.c ft_split.c init.c helper_func.c sorts.c instruc_a.c helpme.c instruc_b.c sorting_stacks.c
SRCS_BONUS = push_swap.c ft_strjoin.c ft_split.c init.c helper_func.c sorts.c instruc_a.c helpme.c instruc_b.c sorting_stacks.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c checker.c

CC = cc

HEADER = Mandatory/push_swap.h
HEADER_BONUS = Bonus/push_swap.h

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)

Mandatory/%.o: Mandatory/%.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@

Bonus/%.o: Bonus/%.c $(HEADER_BONUS) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all