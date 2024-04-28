NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_putstr.c ft_putnbr.c ft_putnbr_uint.c ft_puthexvalue.c ft_putchar.c ft_printf.c ft_itoa.c ft_hexdigit.c ft_memcpy.c ft_strchr.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -Ift_printf

EXTERNAL_FUNCS = malloc free write va_start va_arg va_copy va_end

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: all clean fclean re

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all