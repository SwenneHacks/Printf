# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swofferh <swofferh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/16 17:46:43 by swofferh       #+#    #+#                 #
#    Updated: 2019/12/21 18:37:30 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libprint.a
FLAGS = -Wall -Wextra -Werror 
TEST =  main.c -g -o test

SRC = ft_print.c ft_print_functions.c \

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re bonus test add

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@ar rcs $(NAME) $^
	
%.o: %.c
	@echo ""
	@echo "Compiling $< $@"
	@gcc -c $< $(FLAGS)
	
clean:
	@rm -f $(OBJ)
	@rm -f a.out test
	
fclean: clean
	@rm -f $(NAME)

re: fclean all
	
test: $(NAME)
	@gcc $(FLAGS) $(SRC) $(TEST)
	@echo "\n > gcc flags src -o test \n"
	@./test 

add:
	git add $(SRC) Makefile print.h
	git status