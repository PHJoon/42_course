OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

NAME = libft.a

INCLUDEDIR = -I ./includes/

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	ar rscv ${NAME} ${OBJS}

%.o : %.c
	${CC} ${CFLAGS} ${INCLUDEDIR} -c $< -o $@

clean :
	rm -rf ${OBJS}

fclean : clean
	rm -rf ${NAME}

re : fclean all
