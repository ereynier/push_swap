SRCS1	= checker_srcs/checker.c checker_srcs/utils.c checker_srcs/checker_func.c checker_srcs/checker_func2.c checker_srcs/checker_func3.c checker_srcs/ft_split.c checker_srcs/utils2.c

OBJS1	= ${SRCS1:.c=.o}

SRCS = push_swap_srcs/push_swap.c push_swap_srcs/ps_utils.c push_swap_srcs/action.c checker_srcs/utils.c checker_srcs/checker_func.c checker_srcs/checker_func2.c checker_srcs/checker_func3.c checker_srcs/ft_split.c push_swap_srcs/ps_utils2.c checker_srcs/utils2.c push_swap_srcs/ps_utils3.c

OBJS	= ${SRCS:.c=.o}

INCS	= checker/checker.h 

NAME1	= checker

NAME	= push_swap

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c	$(INCS)
		gcc $(CFLAGS) -I $(INCS) -o $@ -c $<

$(NAME):	${OBJS1} ${OBJS}
			gcc -o ${NAME} ${OBJS}
			gcc -o ${NAME1} ${OBJS1}

all:		${NAME}

clean:		
			rm -f ${OBJS1}
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}
			rm -f ${NAME1}

re:			fclean all

.PHONY:		all clean fclean checker