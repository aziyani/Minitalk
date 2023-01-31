SRC = client.c
SRC1 = server.c
NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

all : ${NAME}

$(NAME): client server

client : ${SRCS} client.c
	$(CC) $(CFLAGS) ${SRCS} client.c -o client
server : ${SRCS} server.c
	$(CC) $(CFLAGS) ${SRCS} server.c  -o server


clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) client server

re: fclean all