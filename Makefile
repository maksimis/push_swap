NAME = push_swap

SRCS = main.c

HEADER = main.h

OBJS = ${SRCS:%.c=%.o}

CC = gcc
CFLAGS = -Wextra -Wall -Werror
RM = rm -rf

.PHONY: all clean fclean re bonus

%.o : %.c ${HEADER}
		 ${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS} ${HEADER}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	 @${RM} ${OBJS} ${OBJS_B}

fclean: 	clean
			${RM} ${NAME}

re:	fclean all
