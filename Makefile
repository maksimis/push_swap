NAME = push_swap

SRCS = main.c utils/i_l_add_back.c utils/i_l_add_front.c \
		utils/i_l_new.c utils/i_l_size.c utils/i_l_clear.c \
		utils/i_l_delone.c utils/i_l_iter.c utils/i_l_last.c\
		utils/push.c utils/swap.c utils/rotate.c utils/reverse.c \
		utils/utils1.c utils/utils2.c utils/a_to_b.c utils/b_to_a.c \
		utils/exits.c utils/sorts.c utils/set_pvt.c

SRCS_B = bonus/checker.c

NAME_B = checker

HEADER = main.h

HEADER_B = bonus/checker.h

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/

OBJS = ${SRCS:%.c=%.o}
OBJS_B = ${SRCS_B:%.c=%.o}

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

bonus:  ${OBJS_B} ${HEADER_B}
		make -C libft
		${CC} ${CFLAGS} -o ${NAME_B} ${OBJS_B}

re:	fclean all
