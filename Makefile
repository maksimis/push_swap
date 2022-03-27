NAME = push_swap

SRCS = main.c

HEADER = main.h

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/

OBJS = ${SRCS:%.c=%.o}

CC = gcc
CFLAGS = -Wextra -Wall -Werror
RM = rm -rf
LIBRARIES = -lft -L$(LIBFT_DIRECTORY)

.PHONY: all clean fclean re bonus

%.o : %.c ${HEADER}
		 ${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJS} ${HEADER}
	make -C libft
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBRARIES}

clean:
	 @${RM} ${OBJS} ${OBJS_B}

fclean: 	clean
			make -C libft fclean
			${RM} ${NAME}

re:	fclean all
