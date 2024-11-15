NAME = ibftprintf.a

C_SOURCE = ft_printf.c

H_SOURCE = ./

OBJ = $(C_SOURCE:.c=.o)

CC = cc

CC_FLAGS = -Wall -Werror -Wextra

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $@ $^

%.o: %.cc
	$(CC) $(CC_FLAGS) -I $(H_SOURCE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	(RM) $(NAME)

re: fclean all

