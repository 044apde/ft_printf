NAME		= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar
ARFLAGS		= -rc

SRCS		= ft_nbrlen.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strlen.c ft_putunbr.c
OBJS		= $(SRCS:.c=.o)

all			: $(NAME)

$(NAME)     : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean 		:
	rm -f $(OBJS)

fclean		: clean
	rm -f $(NAME)

re			: fclean all

.PHONY		: all clean fclean re