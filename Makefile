NAME = push_swap
NAME_BONUS = checker

SRCS = Mandatory/push_swap.c Mandatory/ft_strjoin.c Mandatory/ft_split.c Mandatory/init.c Mandatory/helper_func.c Mandatory/sorts.c Mandatory/instruc_a.c Mandatory/helpme.c Mandatory/instruc_b.c Mandatory/sorting_stacks.c
SRCS_BONUS = Bonus/push_swap_bonus.c Bonus/ft_strjoin_bonus.c Bonus/ft_split_bonus.c Bonus/init_bonus.c Bonus/helper_func_bonus.c Bonus/instruc_a_bonus.c Bonus/helpme_bonus.c Bonus/instruc_b_bonus.c Bonus/add_instructs_bonus.c Bonus/get_next_line/get_next_line.c Bonus/get_next_line/get_next_line_utils.c Bonus/checker_bonus.c Bonus/ft_strncmp_bonus.c

CC = cc

HEADER = Mandatory/push_swap.h
HEADER_BONUS = Bonus/push_swap_bonus.h Bonus/get_next_line/get_next_line.h

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
	$(RM) $(NAME) $(NAME_BONUS)

re:	fclean all