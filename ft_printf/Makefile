OBJS = srcs/ft_printf.o srcs/ft_put_cs.o srcs/ft_put_diu.o srcs/ft_put_pxx.o

SRCS = srcs/ft_printf.c srcs/ft_put_cs.c srcs/ft_put_diu.c srcs/ft_put_pxx.c

NAME = libftprintf.a

INCLUDE = -I ./includes/

LIBFTDIR = ./libft/

AR = ar

ARFLAGS = rsc

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	make -C ${LIBFTDIR} all
	cp ${LIBFTDIR}/libft.a ./${NAME}
	${AR} ${ARFLAGS} $@ $^

%.o : %.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean :
	make -C ${LIBFTDIR} clean
	rm -rf ${OBJS}

fclean : clean
	make -C ${LIBFTDIR} fclean
	rm -rf ${NAME}

re : fclean all

.PHONY : all bonus clean fclean re
