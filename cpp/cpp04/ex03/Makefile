# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 04:36:19 by hyungjpa          #+#    #+#              #
#    Updated: 2023/10/25 15:33:31 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME = AMateria Character Cure Ice ICharacter IMateriaSource main

SRC = $(addsuffix .cpp, $(SRCNAME))

OBJ = $(SRC:cpp=o)

NAME = a.out

INCLUDE = -I ./

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
		$(CXX) $(CXXFLAGS) $(INCLUDE) $^ -o $@

%.o : %.cpp
		$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean :
		rm -rf $(OBJ)

fclean : 
		$(MAKE) clean
		rm -rf $(NAME)

re : 
		$(MAKE) fclean
		$(MAKE) all

.PHONY : all clean fclean re