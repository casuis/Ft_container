# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asimon <asimon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/24 13:12:01 by asimon            #+#    #+#              #
#    Updated: 2023/02/21 22:03:52 by asimon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	ft_container

NAME_STD	:=	std_container

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              SHELL                              #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

CXX				:=	c++

CXXFLAGS		:=	-std=c++98 -g3 -Wall -Wextra -Werror 

INC				:=	-I./private/ -I./templates/map/ -I./templates/vector/ -I./templates/stack/ -I./templates/map/ -I./templates/iterator/ -I./templates/functions/

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

MAIN_SBONUS	:=	main_set.cpp

EXEC_V		:=	vector_output

EXEC_S		:=	stack_output

EXEC_M		:=	map_output

EXEC_SBONUS	:=	set_output

FT_OUT		:=	ft_output

STD_OUT		:=	std_output

RES			:=	diff

FT			:=	ft_

STD			:=	std_


# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              COLORS                             #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

M_YELLOW 		= \033[1;33m
M_GREEN			= \033[1;32m
M_RED			= \033[1;31m
M_BLACK			= \033[1;30m
M_CYAN			= \033[1;36m
M_RESET			= \033[0m
VALIDATE		= ✅
UNVALIDATE		= ❌

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #
#                              RULES                              #
# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

all: test

$(NAME):
	@clear;
	@echo "$(M_YELLOW)Creation of FT's executables ..$(M_RESET)"

	@if [ -f $(SRC_DIR)$(MAIN_V) ]; then \
		$(CXX) $(CXXFLAGS) -o $(FT)$(EXEC_V) $(INC) $(SRC_DIR)$(MAIN_V); \
	else \
		echo "$(M_RED) No main for vector test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_V) ]; then \
		echo "$(M_GREEN)vector test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for vector$(M_RESET)"; \
	fi
	
	@if [ -f $(SRC_DIR)$(MAIN_S) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_S) $(SRC_DIR)$(MAIN_S); \
	else \
		echo "$(M_RED) No main for stack test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_S) ]; then \
		echo "$(M_GREEN)stack test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for stack$(M_RESET)"; \
	fi

	@if [ -f $(SRC_DIR)$(MAIN_M) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_M) $(SRC_DIR)$(MAIN_M); \
	else \
		echo "$(M_RED)No main for map test check $(M_CYAN)src$(M_RED) dir $(M_RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_M) ]; then \
		echo "$(M_GREEN)Map test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for map$(M_RESET)"; \
	fi
	
	@if [ -f $(SRC_DIR)$(MAIN_SBONUS) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_SBONUS) $(SRC_DIR)$(MAIN_SBONUS); \
	else \
		echo "$(M_RED) No main for set test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_SBONUS) ]; then \
		echo "$(M_GREEN)set test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for set$(M_RESET)"; \
	fi

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

$(NAME_STD): 
	@echo "$(M_YELLOW)Creation of STD's executable ..$(M_RESET)";

	@if [ -f $(SRC_DIR)$(MAIN_V) ]; then \
		$(CXX) $(CXXFLAGS) -D STD=1 -o $(STD)$(EXEC_V) $(INC) $(SRC_DIR)$(MAIN_V); \
	else \
		echo "$(M_RED) No main for vector test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_V) ]; then \
		echo "$(M_GREEN)vector test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for vector$(M_RESET)"; \
	fi
	
	@if [ -f $(SRC_DIR)$(MAIN_S) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -D STD=1 -o $(STD)$(EXEC_S) $(SRC_DIR)$(MAIN_S); \
	else \
		echo "$(M_RED) No main for stack test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_S) ]; then \
		echo "$(M_GREEN)stack test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for stack$(M_RESET)"; \
	fi

	@if [ -f $(SRC_DIR)$(MAIN_M) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -D STD=1 -o $(STD)$(EXEC_M) $(SRC_DIR)$(MAIN_M); \
	else \
		echo "$(M_RED)No main for map test check $(M_CYAN)src$(M_RED) dir $(M_RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_M) ]; then \
		echo "$(M_GREEN)Map test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for map$(M_RESET)"; \
	fi

	@if [ -f $(SRC_DIR)$(MAIN_SBONUS) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -D STD=1 -o $(STD)$(EXEC_SBONUS) $(SRC_DIR)$(MAIN_SBONUS); \
	else \
		echo "$(M_RED) No main for set test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_SBONUS) ]; then \
		echo "$(M_GREEN)set test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for set$(M_RESET)"; \
	fi

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

vector: fclean
	@clear;
	@echo "$(M_YELLOW)Creation of FT's executables ..$(M_RESET)"

	@if [ -f $(SRC_DIR)$(MAIN_V) ]; then \
		$(CXX) $(CXXFLAGS) -o $(FT)$(EXEC_V) $(INC) $(SRC_DIR)$(MAIN_V); \
	else \
		echo "$(M_RED) No main for vector test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_V) ]; then \
		echo "$(M_GREEN)vector test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for vector$(M_RESET)"; \
	fi
	
	@echo "$(M_YELLOW)Creation of STD's executable ..$(M_RESET)";

	@if [ -f $(SRC_DIR)$(MAIN_V) ]; then \
		$(CXX) $(CXXFLAGS) -D STD=1 -o $(STD)$(EXEC_V) $(INC) $(SRC_DIR)$(MAIN_V); \
	else \
		echo "$(M_RED) No main for vector test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_V) ]; then \
		echo "$(M_GREEN)vector test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for vector$(M_RESET)"; \
	fi

	@mkdir -p res
	@mv *_output res/

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

map: fclean
	@clear;
	@echo "$(M_YELLOW)Creation of FT's executables ..$(M_RESET)"

	@if [ -f $(SRC_DIR)$(MAIN_M) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_M) $(SRC_DIR)$(MAIN_M); \
	else \
		echo "$(M_RED)No main for map test check $(M_CYAN)src$(M_RED) dir $(M_RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_M) ]; then \
		echo "$(M_GREEN)Map test created$(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for map$(M_RESET)"; \
	fi
	
	@echo "$(M_YELLOW)Creation of STD's executable ..$(M_RESET)";

	@if [ -f $(SRC_DIR)$(MAIN_M) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -D STD=1 -o $(STD)$(EXEC_M) $(SRC_DIR)$(MAIN_M); \
	else \
		echo "$(M_RED)No main for map test check $(M_CYAN)src$(M_RED) dir $(M_RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_M) ]; then \
		echo "$(M_GREEN)Map test created$(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for map$(M_RESET)"; \
	fi
	@mkdir -p res
	@mv *_output res/

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

stack: fclean
	@clear
	@echo "$(M_YELLOW)Creation of FT's executables ..$(M_RESET)"
	@if [ -f $(SRC_DIR)$(MAIN_S) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_S) $(SRC_DIR)$(MAIN_S); \
	else \
		echo "$(M_RED) No main for stack test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_S) ]; then \
		echo "$(M_GREEN)stack test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for stack$(M_RESET)"; \
	fi
	@echo "$(M_YELLOW)Creation of STD's executable ..$(M_RESET)";
	@if [ -f $(SRC_DIR)$(MAIN_S) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -D STD=1 -o $(STD)$(EXEC_S) $(SRC_DIR)$(MAIN_S); \
	else \
		echo "$(M_RED) No main for stack test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_S) ]; then \
		echo "$(M_GREEN)stack test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for stack$(M_RESET)"; \
	fi

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

set: fclean
	@clear
	@echo "$(M_YELLOW)Creation of FT's executables ..$(M_RESET)"
	@if [ -f $(SRC_DIR)$(MAIN_SBONUS) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -o $(FT)$(EXEC_S) $(SRC_DIR)$(MAIN_SBONUS); \
	else \
		echo "$(M_RED) No main for set test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(FT)$(EXEC_SBONUS) ]; then \
		echo "$(M_GREEN)set test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for set$(M_RESET)"; \
	fi
	@echo "$(M_YELLOW)Creation of STD's executable ..$(M_RESET)";
	@if [ -f $(SRC_DIR)$(MAIN_SBONUS) ]; then \
		$(CXX) $(CXXFLAGS) $(INC) -D STD=1 -o $(STD)$(EXEC_SBONUS) $(SRC_DIR)$(MAIN_SBONUS); \
	else \
		echo "$(M_RED) No main for set test check $(M_CYAN)src$(M_RED) dir$(M_RESET)"; \
	fi

	@if [ -f $(STD)$(EXEC_SBONUS) ]; then \
		echo "$(M_GREEN)set test created $(VALIDATE)$(M_RESET)"; \
	else \
		echo "$(M_RED)Error during creation of tests for set$(M_RESET)"; \
	fi

# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #

test:
	@$(MAKE) -i $(NAME)
	@$(MAKE) -i $(NAME_STD)
	@mkdir -p res/Vector/bin res/Vector/diff res/Set/bin res/Set/diff res/Stack/bin res/Stack/diff res/Map/bin res/Map/diff 
	@mv *vector_output res/Vector/bin/
	@mv *stack_output res/Stack/bin/
	@mv *set_output res/Set/bin/
	@mv *map_output res/Map/bin/
	@./res/Vector/bin/ft_vector_output > ./res/Vector/diff/ft_output
	@./res/Vector/bin/std_vector_output > ./res/Vector/diff/std_output
	@./res/Set/bin/ft_set_output > ./res/Set/diff/ft_output
	@./res/Set/bin/std_set_output > ./res/Set/diff/std_output
	@./res/Map/bin/ft_map_output > ./res/Map/diff/ft_output
	@./res/Map/bin/std_map_output > ./res/Map/diff/std_output
	@./res/Stack/bin/ft_stack_output > ./res/Stack/diff/ft_output
	@./res/Stack/bin/std_stack_output > ./res/Stack/diff/std_output
	@diff ./res/Vector/diff/ft_output ./res/Vector/diff/std_output > ./res/Vector/diff/diff.log || true
	@diff ./res/Stack/diff/ft_output ./res/Stack/diff/std_output > ./res/Stack/diff/diff.log || true
	@diff ./res/Set/diff/ft_output ./res/Set/diff/std_output > ./res/Set/diff/diff.log || true
	@diff ./res/Map/diff/ft_output ./res/Map/diff/std_output > ./res/Map/diff/diff.log || true


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