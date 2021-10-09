NAME_CLIENT = client

NAME_SERVER = server

NAME_CLIENT_B = client_bonus

NAME_SERVER_B = server_bonus

NAME_PRINT = libftprintf.a

PATH_PRINT = ft_printf/

PRINT = $(addprefix $(PATH_PRINT), $(NAME_PRINT))

SRC_CLIENT =  mandatory/client.c\
			utils/ft_atoi.c\

SRC_SERVER = mandatory/server.c\

SRC_CLIENT_B = bonus/client_bonus.c\
				utils/ft_atoi.c\

SRC_SERVER_B = bonus/server_bonus.c

HDRS_CLIENT = mandatory/client.h

HDRS_SERVER = mandatory/server.h

HDRS_CLIENT_B = bonus/client_bonus.h

HDRS_SERVER_B = bonus/server_bonus.h

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT_B =$(SRC_CLIENT_B:.c=.o)

OBJ_SERVER_B = $(SRC_SERVER_B:.c=.o)

CC = gcc

FLAGS =  -Wall -Werror -Wextra

RM = rm -f

all: $(NAME_CLIENT) $(NAME_SERVER) 

$(NAME_SERVER): $(HDRS_SERVER) $(OBJ_SERVER)
				make -C $(PATH_PRINT)
				$(CC) $(FLAGS) $(PRINT) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT) : $(HDRS_CLIENT) $(OBJ_CLIENT)
				make -C $(PATH_PRINT)
				$(CC) $(FLAGS) $(PRINT) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(NAME_SERVER_B): $(HDRS_SERVER_B) $(OBJ_SERVER_B)
				make -C $(PATH_PRINT)
				$(CC) $(FLAGS) $(PRINT) $(OBJ_SERVER_B) -o $(NAME_SERVER_B)

$(NAME_CLIENT_B) : $(HDRS_CLIENT_B) $(OBJ_CLIENT_B)
				make -C $(PATH_PRINT)
				$(CC) $(FLAGS) $(PRINT) $(OBJ_CLIENT_B) -o $(NAME_CLIENT_B)

bonus: $(NAME_CLIENT_B) $(NAME_SERVER_B)

clean:
		$(RM) $(OBJ_CLIENT) $(OBJ_SERVER) $(OBJ_CLIENT_B) $(OBJ_SERVER_B)
		make clean -C $(PATH_PRINT)

fclean: clean
		make fclean -C $(PATH_PRINT)
		$(RM) $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_B) $(NAME_SERVER_B)

re: fclean all

.PHONY: all clean fclean
