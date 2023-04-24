NAME	= a.out
CC		= cc
CFLAGS  = -Wall -Wextra -Werror
AR		= ar
ARFLAGS = -rc
INC		= ./libft.h
SRCS	= ft_printf.c
OBJ_FILES	= $(SRCS:.c=.o)

all : $(NAME)

clean :
	rm -rf a.out ft_printf.h.gch

fclean:
	make clean
	rm -rf libft.a

re:
	make clean
	make all

$(NAME) : $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) libft.a -o $(NAME)