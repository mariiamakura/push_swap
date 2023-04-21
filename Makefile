# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:28:31 by mparasku          #+#    #+#              #
#    Updated: 2023/04/14 15:34:27 by mparasku         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_END=\033[0m

NAME = push_swap

SRC = 	*.c

OBJ = $(SRC:%.c=%.o)

all:$(NAME)

$(NAME):$(OBJ)
	@cd printf && make all
	@cc -g -Wall -Wextra -Werror *.c printf/libftprintf.a -o $(NAME)
	@echo "$(COLOUR_GREEN)push_swap is done$(COLOUR_END)"
	
clean:
	@cd printf && make clean
	@rm -f $(OBJ)
	@echo "$(COLOUR_RED)all objects and executable files have been deleted$(COLOUR_END)"

fclean: clean
	@cd printf && make fclean
	@rm -f $(NAME) 
	@echo "$(COLOUR_RED)all files have been deleted$(COLOUR_END)"

re: fclean all

run: all
	./$(NAME) $(ARGS)

.PHONY: all clean fclean re