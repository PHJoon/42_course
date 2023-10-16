# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyungjpa <hyungjpa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/01 16:53:26 by hyungjpa          #+#    #+#              #
#    Updated: 2023/10/16 11:05:25 by hyungjpa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCNAME = megaphone

SRC = $(addsuffix .cpp, $(SRCNAME))

OBJ = $(SRC:cpp=o)

NAME = megaphone

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