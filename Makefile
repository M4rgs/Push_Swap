CC = cc

CFLAGS = -Wall

NAME = push_swap

SRCS = push_swap.c ft_strjoin.c ft_split.c init.c helper_func.c sorts.c instruc_a.c

OBJ = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

%.o: %.c push_swap.h  
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all
