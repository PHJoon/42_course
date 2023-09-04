# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 17:13:19 by hyungjpa          #+#    #+#              #
#    Updated: 2023/09/04 14:39:49 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME = contact phonebook main

SRC = $(addsuffix .cpp, $(SRCNAME))

OBJ = $(SRC:cpp=o)

NAME = phonebook

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