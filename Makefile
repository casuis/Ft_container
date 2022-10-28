# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimon <asimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:12:01 by asimon            #+#    #+#              #
#    Updated: 2022/10/21 17:24:39 by asimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_container

NAME_STD	=	std_container

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

SRC_DIR		:=	./src/

SRC_CPP		:=	main.cpp

SRC			:=	$(addprefix $(SRC_DIR), $(SRC_CPP))

FT_OUT		:= ft_output

STD_OUT		:= std_putput

RES			:= final_grade

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              VECTOR                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

V_DIR		=	$(addprefix $(SRC_DIR), vector/)


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              COLORS                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

YELLOW 		= \033[1;33m
GREEN		= \033[1;32m
RED			= \033[1;31m
BLACK		= \033[1;30m
CYAN		= \033[1;36m
RESET		= \033[0m
VALIDATE	= ✅
UNVALIDATE	= ❌

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              RULES                              #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: test

$(NAME):
	@echo "$(YELLOW)Creation de l'executable FT ..$(RESET)"
	$(CXX) $(CXXFLAGS) -o $(NAME) $(INC) $(SRC) 
	@if [ -f $@ ]; then \
		echo "$(GREEN)Executable $@ created! $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED) Failed to create Executable $(UNVALIDATE)$(RESET)"; \
	fi
	
$(NAME_STD): 
	@echo "$(YELLOW)Creation de l'executable STD ..$(RESET)"
	$(CXX) $(CXXFLAGS) -o $@ -D STD=1 $(INC) $(SRC)
	@if [ -f $@ ]; then \
		echo "$(GREEN)Executable $@ created! $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED) Failed to create Executable $(UNVALIDATE)$(RESET)"; \
	fi

test:
	@$(MAKE) $(NAME)
	@$(MAKE) $(NAME_STD)
	@mkdir -p res
	@mv $(NAME) $(NAME_STD) res/
	@./res/$(NAME) > ./res/$(FT_OUT)
	@./res/$(NAME_STD) > ./res/$(STD_OUT)
	@echo "$(YELLOW)Comparing the two outputs...$(RESET) "
	@diff -y ./res/$(FT_OUT) ./res/$(STD_OUT) > ./res/$(RES); [ $$? -eq 1 ]
	@echo "$(GREEN)ENDED$(RESET)"
	@echo "$(CYAN)pls look in the res/ directory, if final_grade is empty no diff has been found$(RESET)"

go: re
	./$(NAME)

clean:
	$(RM) ./res/$(NAME) ./res/$(NAME_STD)

fclean: clean
	$(RM) ./res/

re: fclean all

.PHONY: all re clean fclean