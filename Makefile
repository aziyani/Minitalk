SRC = client.c 
SRC1 = server.c
NAME = minitalk
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

%.o : %.c
	${CC} ${CFLAGS} -c $< -o $@
all : ${NAME}

$(NAME): client server

client : ${OBJS}
	$(CC) $(CFLAGS) ${SRCS} client.c -o client
server : ${OBJS} 
	$(CC) $(CFLAGS) ${SRCS} server.c  -o server


clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(client) $(server)

re: fclean all
