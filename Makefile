NAME        = libftprintf.a
CC          = gcc
CFLAGS      = -Wall -Wextra -Werror
AR          = ar
ARFLAGS     = -rc
INCLUDES    = -Ilibft

SRCS        = ft_printf.c
SRCS_LIBFT  = libft/ft_nbrlen.c libft/ft_putchar.c libft/ft_putnbr.c libft/ft_putstr.c libft/ft_strlen.c
OBJS        = $(SRCS:.c=.o)
OBJS_LIBFT  = $(SRCS_LIBFT:.c=.o)

all         : $(NAME)

$(NAME)     : $(OBJS) $(OBJS_LIBFT)
	$(AR) $(ARFLAGS) $(NAME) libft.a ft_printf.a
	rm -rf libft.a ft_printf.a

$(OBJS)     : $(SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_LIBFT): $(SRCS_LIBFT)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean       :
	rm -f $(OBJS) $(OBJS_LIBFT)
	rm -f *.o

fclean      : clean
	rm -f $(NAME)

re          : fclean all

.PHONY      : all clean fclean re