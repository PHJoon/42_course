# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 15:09:43 by hyungjpa          #+#    #+#              #
#    Updated: 2023/02/01 15:09:44 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME = atod check_argv color error fractal main mlx_event mlx struct

SRC = ${addsuffix .c, ${addprefix fractol_, ${SRCNAME}}}

OBJ = ${SRC:.c=.o}

NAME = fractol

INCLUDE_MLX = -I .mlx -Lmlx -lmlx -framework OpenGL -framework Appkit

INCLUDE_LIBFT = -L ./libft -lft

INCLUDE = -I ./

MLX_DIR = ./mlx/

LIBFT_DIR = ./libft/

CC = cc

CFLAGS = -O3 -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJ}
		make -C ${MLX_DIR} all
		make -C ${LIBFT_DIR} all
		${CC} ${CFLAGS} ${INCLUDE_MLX} ${INCLUDE_LIBFT} ${INCLUDE} $^ -o $@

%.o : %.C
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean :
		make -C ${MLX_DIR} clean
		make -C ${LIBFT_DIR} clean
		rm -rf ${OBJ}

fclean : clean
		make -C ${MLX_DIR} clean
		make -C ${LIBFT_DIR} fclean
		rm -rf ${NAME}

re : fclean all

.PHONY : all clean fclean re