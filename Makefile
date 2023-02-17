NAME = minitalk

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC_SERVER = ft_printf.c server.c
			
SRC_CLIENT = ft_printf.c client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

RM = rm -f

all : ${NAME}

$(NAME): client server

client : $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o client

server : $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER)   -o server

clean:
	$(RM) ${OBJ_CLIENT} ${OBJ_SERVER}

fclean: clean
	$(RM) client server

re: fclean all

.PHONY : fclean clean re