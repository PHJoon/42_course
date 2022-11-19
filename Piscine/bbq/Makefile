OBJS = srcs/ft_file_to_map.o srcs/ft_first_line.o srcs/ft_line_len.o srcs/ft_putstr.o srcs/ft_square_in_map.o srcs/ft_strcpy.o srcs/ft_strlen.o srcs/ft_strncpy.o srcs/ft_valid_check.o srcs/ft_write_result.o srcs/ft_buf_first_line.o srcs/ft_valid_buf.o srcs/main.o

SRCS = srcs/ft_file_to_map.c srcs/ft_first_line.c srcs/ft_line_len.c srcs/ft_putstr.c srcs/ft_square_in_map.c srcs/ft_strcpy.c srcs/ft_strlen.c srcs/ft_strncpy.c srcs/ft_valid_check.c srcs/ft_write_result.c srcs/ft_buf_first_line.c srcs/ft_valid_buf.c srcs/main.c

NAME = BSQ

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
