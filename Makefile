SRCS1	= checker_srcs/checker.c checker_srcs/utils.c checker_srcs/checker_func.c checker_srcs/checker_func2.c checker_srcs/checker_func3.c

OBJS1	= ${SRCS1:.c=.o}

INCS	= checker/checker.h 

NAME	= checker

CFLAGS	= -Wall -Werror -Wextra

%.o: %.c	$(INCS)
		gcc $(CFLAGS) -I $(INCS) -o $@ -c $<

$(NAME):	${OBJS1}
			gcc -o ${NAME} ${OBJS1}

all:		${NAME}

clean:		
			rm -f ${OBJS1}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean checker