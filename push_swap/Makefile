# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 20:24:07 by hyungjpa          #+#    #+#              #
#    Updated: 2023/02/01 20:29:18 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME = main free error parsing_1 parsing_2 parsing_3 \
operation_1 operation_2 operation_3 sort_1 sort_2 sort_3 \
sort_4 stack_func_1 stack_func_2

SRC = ${addsuffix .c, ${SRCNAME}}

OBJ = ${SRC:.c=.o}

NAME = push_swap

LIBFT_DIR = ./libft/

INCLUDE_LIBFT = -L ./libft -lft

INCLUDE = -I ./

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
		make -C ${LIBFT_DIR} all
		${CC} ${CFLAGS} ${INCLUDE} ${INCLUDE_LIBFT} $^ -o $@

clean :
		make -C ${LIBFT_DIR} clean
		rm -rf ${OBJ}

fclean : clean
		make -C ${LIBFT_DIR} fclean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re

	
