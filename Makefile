# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dteemo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 12:32:25 by student           #+#    #+#              #
#    Updated: 2020/07/30 16:58:19 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_1		=	checker

NAME_2		=	push_swap

FLAGS		=	-Wall -Werror -Wextra

SRC_PATH	=	./src/

OBJ_PATH	=	./obj/

OBJ_DIR		= 	obj

CH_SRC		=	$(NAME_1).c actions.c actions_p.c add_data.c sort.c print_stack.c strequ.c

PS_SRC		=	$(NAME_2).c actions.c actions_p.c add_data.c sort.c print_stack.c strequ.c algo.c algo2.c algo_helpers.c

CHC = $(addprefix $(OBJ_PATH), $(CH_SRC))

PSC = $(addprefix $(OBJ_PATH), $(PS_SRC))

CHO = $(patsubst %.c, %.o, $(CHC))

PSO = $(patsubst %.c, %.o, $(PSC))

all: $(OBJ_DIR) $(NAME_1) $(NAME_2)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(NAME_1): $(OBJ_PATH) $(CHO)
	@gcc $(FLAGS) $(CHO) -o $(NAME_1)
	@echo "\033[32m$(NAME_1) created.\033m"

$(NAME_2): $(OBJ_PATH) $(PSO)
	@gcc $(FLAGS) $(PSO) -o $(NAME_2)
	@echo "\033[32m$(NAME_2) created.\033m"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) -c $< -o $@

clean: 
	@rm -rf $(OBJ_DIR)
	@echo "\033[33mObjects files removed\033[0m"

fclean: clean
		@rm -f $(NAME_1) $(NAME_2)
		@echo "\033[33mExec removed\033[0m"

re: fclean all

.PHONY: all fclean clean re
