# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 04:36:19 by hyungjpa          #+#    #+#              #
#    Updated: 2023/10/12 11:07:16 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME = main

SRC = $(addsuffix .cpp, $(SRCNAME))

OBJ = $(SRC:cpp=o)

NAME = SedIsForLosers

INCLUDE = -I ./

CFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
		$(CXX) $(CFLAGS) $(INCLUDE) $^ -o $@

%.o : %.cpp
		$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean :
		rm -rf $(OBJ)

fclean : 
		$(MAKE) clean
		rm -rf $(NAME)

re : 
		$(MAKE) fclean
		$(MAKE) all

.PHONY : all clean fclean re