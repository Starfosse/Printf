NAME = libftprintf.a

SRC = ft_printnbr.c ft_printunsigned.c ft_print_nbr_base.c ft_print_unsigned_nbr_base.c ft_printf.c

OBJ = ft_printnbr.o ft_printunsigned.o ft_print_nbr_base.o ft_print_unsigned_nbr_base.o ft_printf.o
	
CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
		$(CC) $(CFLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
clean:
		$(RM) $(OBJ) 

fclean: clean
		$(RM) $(NAME)

re: fclean all