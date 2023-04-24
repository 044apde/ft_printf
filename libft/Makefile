NAME	= libft.a
CC		= cc
CFLAGS  = -Wall -Wextra -Werror
AR		= ar
ARFLAGS = -rc
INC		= ./libft.h
SRCS	= ft_nbrlen.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_putunbr.c
OBJ_FILES	= $(SRCS:.c=.o)

all : $(NAME)

clean :
	rm -f $(OBJ_FILES) 

fclean : clean
	rm -f $(NAME) 

re :
	make fclean
	make all

$(NAME) : $(OBJ_FILES)
	$(AR) $(ARFLAGS) ../$@ $?

.PHONY : all bonus clean fclean re