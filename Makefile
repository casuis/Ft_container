# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimon <asimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:12:01 by asimon            #+#    #+#              #
#    Updated: 2022/10/20 14:14:55 by asimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_container

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              SHELL                              #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

CXX			=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -g3

INC			=	-I./private/ -I./templates/vector/ -I./templates/iterator/ -I./templates/functions/

MKDIR		=	/bin/mkdir -p

RM			=	/bin/rm -rf

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              SRC                                #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

SRC_DIR		=	./src/

SRC_CPP		=	main.cpp

SRC			=	$(addprefix $(SRC_DIR), $(SRC_CPP))

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              VECTOR                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

V_DIR		=	$(addprefix $(SRC_DIR), vector/)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              OBJECT                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

OBJ			=	$(SRC:.cpp=.o)

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              RULES                              #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all

.PHONY: all re clean fclean