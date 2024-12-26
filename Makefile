NAME	=	libftprintf.a

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror
AR	=	ar
ARFLAGS	=	rcs
RM	=	rm -rf

SRC	=	ft_printf.c \
		ft_print_hex.c \
		ft_print_number.c \
		ft_print_ptr.c \
		ft_print_unsigned.c \
		ft_print_str.c

OBJ	=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

//Target: Dependencies
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re