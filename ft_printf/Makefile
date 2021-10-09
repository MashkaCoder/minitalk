NAME = libftprintf.a

NAME_LIBFT = libft.a

PATH_LIBFT = ./libft/

PATH_SRC = ./src/

SRC = ft_itoa_hex.c\
	ft_itoa_uns.c\
	ft_printf.c\
	print_str.c\
	print_str_null.c\
	print_str_int.c\
	print_char.c\
	print_p.c\
	print_percent.c\
	print_x.c\
	print_int.c\
	print_uns_int.c\


OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -g -Wall -Wextra -Werror

HDRS = ft_printf.h

RM = rm -f

$(NAME) : ft_printf.h $(OBJ)
		make -C $(PATH_LIBFT)
		cp $(PATH_LIBFT)$(NAME_LIBFT) $(NAME)
		$(CC) $(FLAGS) -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

all: $(NAME)

bonus: all

test:
	$(CC) $(SRC)

clean:
	$(RM) $(OBJ)
	make clean -C $(PATH_LIBFT)

fclean: clean
	make fclean -C $(PATH_LIBFT)
	$(RM) $(OBJ)
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean test
