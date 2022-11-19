OBJS = srcs/ft_do-op.o srcs/ft_atoi.o srcs/ft_putnbr.o srcs/ft_putstr.o srcs/ft_cal.o

SRCS = srcs/ft_do-op.c srcs/ft_atoi.c srcs/ft_putnbr.c srcs/ft_putstr.c srcs/ft_cal.c

NAME = do-op

INCLUDEDIR = -I ./includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} $^ -o $@

%.o : %.c
	${CC} ${CFLAGS} ${INCLUDEDIR} -c $< -o $@

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all
