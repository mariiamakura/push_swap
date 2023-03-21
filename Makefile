# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 16:28:31 by mparasku          #+#    #+#              #
#    Updated: 2023/03/17 15:55:30 by mishamakura      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_END=\033[0m

NAME = push_swap

all:$(NAME)

$(NAME):
	@cd printf && make all
	@cc -Wall -Wextra -Werror *.c printf/libftprintf.a -o $(NAME)
	@echo "$(COLOUR_GREEN)push_swap is done$(COLOUR_END)"
	
clean:
	@cd printf && make clean
	@rm -f push_swap
	@echo "$(COLOUR_RED)all objects and executable files have been deleted$(COLOUR_END)"

fclean: clean
	@cd printf && make fclean
	@echo "$(COLOUR_RED)all files have been deleted$(COLOUR_END)"

re: fclean all

.PHONY: all clean fclean re 