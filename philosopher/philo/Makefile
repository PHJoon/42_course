# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 15:33:19 by hyungjpa          #+#    #+#              #
#    Updated: 2023/07/07 13:45:53 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = philo_main \
			philo_check_argv \
			philo_free \
			philo_init \
			philo_loop \
			philo_print \
			philo_utils \
			ft_atoll \
			ft_strncmp \

SRC = ${addsuffix .c, ${SRC_NAME}}
		
OBJ = ${addsuffix .o, ${SRC_NAME}}

NAME = philo

INCLUDE = -I ./

P_INCLUDE = -lpthread

CC = cc

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

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