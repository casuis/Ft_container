# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimon <asimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:12:01 by asimon            #+#    #+#              #
#    Updated: 2023/01/30 20:28:54 by asimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ft_container

NAME_STD	:=	std_container

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              SHELL                              #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

CXX				:=	c++

CXXFLAGS		:=	-Wall -Wextra -Werror -std=c++98 -g3

INC				:=	-I./private/ -I./templates/vector/ -I./templates/stack/ -I./templates/map/ -I./templates/iterator/ -I./templates/functions/

MKDIR			=	/bin/mkdir -p

RM				=	/bin/rm -rf

SRC_DIR			:=	./src/

TEMPLATE_DIR	:=	./templates/

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              SRC                                #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


MAIN_V		:=	main_vector.cpp

MAIN_S		:=	main_stack.cpp

MAIN_M		:=	main_map.cpp

EXEC_V		:=	vector_output

EXEC_S		:=	stack_output

EXEC_M		:=	map_output

FT_OUT		:=	ft_output

STD_OUT		:=	std_output

RES			:=	diff

FT			:=	ft_

STD			:=	std_

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              VECTOR                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #


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
	@clear;
	@echo "$(YELLOW)Creation of FT's executables ..$(RESET)"

	@if [ -f $(SRC_DIR)$(MAIN_V) ]; then \
		$(CXX) $(CXXFLAGS) -o $(FT)$(EXEC_V) $(INC) $(SRC_DIR)$(MAIN_V); \
	else \
		echo "$(RED) No main for vector test check $(CYAN)src$(RED) dir$(RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_V) ]; then \
		echo "$(GREEN)vector test created $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for vector$(RESET)"; \
	fi
	
	@if [ -f $(SRC_DIR)$(MAIN_S) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_S) $(SRC_DIR)$(MAIN_S); \
	else \
		echo "$(RED) No main for stack test check $(CYAN)src$(RED) dir$(RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_S) ]; then \
		echo "$(GREEN)stack test created $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for stack$(RESET)"; \
	fi

	@if [ -f $(SRC_DIR)$(MAIN_M) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_M) $(SRC_DIR)$(MAIN_M); \
	else \
		echo "$(RED)No main for map test check $(CYAN)src$(RED) dir $(RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_M) ]; then \
		echo "$(GREEN)Map test created$(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for map$(RESET)"; \
	fi

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

$(NAME_STD): 
	@echo "$(YELLOW)Creation of STD's executable ..$(RESET)";

	@if [ -f $(SRC_DIR)$(MAIN_V) ]; then \
		$(CXX) $(CXXFLAGS) -o $(STD)$(EXEC_V) $(INC) $(SRC_DIR)$(MAIN_V); \
	else \
		echo "$(RED) No main for vector test check $(CYAN)src$(RED) dir$(RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_V) ]; then \
		echo "$(GREEN)vector test created $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for vector$(RESET)"; \
	fi
	
	@if [ -f $(SRC_DIR)$(MAIN_S) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(STD)$(EXEC_S) $(SRC_DIR)$(MAIN_S); \
	else \
		echo "$(RED) No main for stack test check $(CYAN)src$(RED) dir$(RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_S) ]; then \
		echo "$(GREEN)stack test created $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for stack$(RESET)"; \
	fi

	@if [ -f $(SRC_DIR)$(MAIN_M) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(STD)$(EXEC_M) $(SRC_DIR)$(MAIN_M); \
	else \
		echo "$(RED)No main for map test check $(CYAN)src$(RED) dir $(RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_M) ]; then \
		echo "$(GREEN)Map test created$(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for map$(RESET)"; \
	fi

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

vector: fclean
	@clear;
	@echo "$(YELLOW)Creation of FT's executables ..$(RESET)"

	@if [ -f $(SRC_DIR)$(MAIN_V) ]; then \
		$(CXX) $(CXXFLAGS) -o $(FT)$(EXEC_V) $(INC) $(SRC_DIR)$(MAIN_V); \
	else \
		echo "$(RED) No main for vector test check $(CYAN)src$(RED) dir$(RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_V) ]; then \
		echo "$(GREEN)vector test created $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for vector$(RESET)"; \
	fi
	
	@echo "$(YELLOW)Creation of STD's executable ..$(RESET)";

	@if [ -f $(SRC_DIR)$(MAIN_V) ]; then \
		$(CXX) $(CXXFLAGS) -D STD=1 -o $(STD)$(EXEC_V) $(INC) $(SRC_DIR)$(MAIN_V); \
	else \
		echo "$(RED) No main for vector test check $(CYAN)src$(RED) dir$(RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_V) ]; then \
		echo "$(GREEN)vector test created $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for vector$(RESET)"; \
	fi

	@mkdir -p res
	@mv *_output res/

# stack: fclean
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

map: fclean
	@clear;
	@echo "$(YELLOW)Creation of FT's executables ..$(RESET)"

	@if [ -f $(SRC_DIR)$(MAIN_M) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_M) $(SRC_DIR)$(MAIN_M); \
	else \
		echo "$(RED)No main for map test check $(CYAN)src$(RED) dir $(RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_M) ]; then \
		echo "$(GREEN)Map test created$(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for map$(RESET)"; \
	fi
	
	@echo "$(YELLOW)Creation of STD's executable ..$(RESET)";

	@if [ -f $(SRC_DIR)$(MAIN_M) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -D STD=1 -o $(STD)$(EXEC_M) $(SRC_DIR)$(MAIN_M); \
	else \
		echo "$(RED)No main for map test check $(CYAN)src$(RED) dir $(RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_M) ]; then \
		echo "$(GREEN)Map test created$(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for map$(RESET)"; \
	fi
	@mkdir -p res
	@mv *_output res/


stack: fclean
	@clear
	@echo "$(YELLOW)Creation of FT's executables ..$(RESET)"
	@if [ -f $(SRC_DIR)$(MAIN_S) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_S) $(SRC_DIR)$(MAIN_S); \
	else \
		echo "$(RED) No main for stack test check $(CYAN)src$(RED) dir$(RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_S) ]; then \
		echo "$(GREEN)stack test created $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for stack$(RESET)"; \
	fi
	@echo "$(YELLOW)Creation of STD's executable ..$(RESET)";
	@if [ -f $(SRC_DIR)$(MAIN_S) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -D STD=1 -o $(STD)$(EXEC_S) $(SRC_DIR)$(MAIN_S); \
	else \
		echo "$(RED) No main for stack test check $(CYAN)src$(RED) dir$(RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_S) ]; then \
		echo "$(GREEN)stack test created $(VALIDATE)$(RESET)"; \
	else \
		echo "$(RED)Error during creation of tests for stack$(RESET)"; \
	fi

test:
	@$(MAKE) -i $(NAME)
	@$(MAKE) -i $(NAME_STD)
	@mkdir -p res
	@mv *_output res/

go: re
	./$(NAME)

clean:
	@clear
	$(RM) ./res/$(NAME) ./res/$(NAME_STD)

fclean: clean
	$(RM) ./res/

re: fclean all

.PHONY: all re clean fclean

# SRCDIR         = ./src

# SRCS         = $(shell find $(SRCDIR) -name "*.cpp")

# OBJS        = $(SRCS:.cpp=.o)

# CXX            =  c++

# CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -g3 -fsanitize=address 

# INCLUDES     = $(shell find . -type f -name "*.hpp" | cut -c 3-)

# NAME        = ft_containers

# NAME_STD     = std_containers

# SWAP_COMPIL = 0

# all :	$(NAME_STD)

# %.o:	%.cpp $(INCLUDES)
# 	ifeq ($(SWAP_COMPIL), 0) 
# 		@echo "======= SWAP_COMPIL is odd ======\n" ;\ 
# 		$(CXX) $(CXXFLAGS) -D STD=1 -c $< -o $@ ; \
# 	else
# 		@echo "======= SWAP_COMPIL is even ======\n" ;
# 		$(CXX) $(CXXFLAGS) -D STD=2 -c $< -o $@ ;
	
# 	endif
    

# $(NAME)     :  $(OBJS) $(INCLUDES)
# 	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
# 	make clean

# $(NAME_STD)    : $(OBJS) $(INCLUDES)
# 	$(CXX) $(CXXFLAGS) -o $(NAME_STD) $(OBJS)
# 	rm -f $(NAME_STD)
# 	make clean
# 	SWAP_COMPIL=1;
# 	make $(NAME)