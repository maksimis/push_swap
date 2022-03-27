NAME = push_swap

SRCS = main.c utils/i_l_add_back.c utils/i_l_add_front.c \
		utils/i_l_new.c utils/i_l_size.c utils/i_l_clear.c \
		utils/i_l_delone.c utils/i_l_iter.c \
		utils/operations1.c utils/operations2.c utils/operations3.c

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
