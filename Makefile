NAME = libftprintf.a

C_SOURCE = ft_putchar.c ft_putstr.c ft_printnbr.c ft_itoh.c ft_printunbr.c ft_printptr.c \
ft_printf.c

H_SOURCE = ./

OBJ = $(C_SOURCE:.c=.o)

CC = cc

CC_FLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CC_FLAGS) -I $(H_SOURCE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
