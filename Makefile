NAME = push_swap

SRCS = push_swap.c ft_strjoin.c ft_split.c init.c helper_func.c sorts.c instruc_a.c helpme.c instruc_b.c sorting_stacks.c

CC = cc

HEADER = push_swap.h

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c $(HEADER) 
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all