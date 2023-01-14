# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/06 12:41:05 by hyungjpa          #+#    #+#              #
#    Updated: 2023/01/06 12:41:09 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME = pipex_cmd pipex_error pipex_file pipex_free pipex_init pipex_path pipex

SRC= ${addsuffix .c, ${SRCNAME}}

OBJ = ${SRC:.c=.o}

NAME = pipex

INCLUDE_1 = -I ./

INCLUDE_2 = -I ./libft/

LIBFTDIR = ./libft/

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
	make -C ${LIBFTDIR} all
	${CC} ${CFLAGS} ${INCLUDE_1} ${INCLUDE_2} $^ -o $@ -L./libft -lft

%.o : %.c
	${CC} ${CFLAGS} ${INCLUDE_1} ${INCLUDE_2} -c $< -o $@

clean :
	make -C ${LIBFTDIR} clean
	rm -rf ${OBJ}

fclean : clean
	make -C ${LIBFTDIR} fclean
	rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re
