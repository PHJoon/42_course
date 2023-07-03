# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 15:33:19 by hyungjpa          #+#    #+#              #
#    Updated: 2023/07/03 16:46:09 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = philo_main \
			ft_atoi \

SRC = ${addsuffix .c, ${SRC_NAME}}
		
OBJ = ${addsuffix .o, ${SRC_NAME}}

NAME = philo

INCLUDE = -I ./

P_INCLUDE = -lpthread

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
		${CC} ${CFLAGS} ${INCLUDE} ${P_INCLUDE} $^ -o $@

%.o : %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean :
		rm -rf ${OBJ}

fclean : clean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re