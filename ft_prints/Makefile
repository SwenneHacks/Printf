# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swofferh <swofferh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/16 17:46:43 by swofferh       #+#    #+#                 #
#    Updated: 2020/01/28 17:48:27 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libprint.a
FLAGS = -Wall -Wextra -Werror
MAIN =  main.c -g -o test
TEST = test.dSYM test

SRC = ft_prints.c ft_utils.c \

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re bonus test add

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@echo "Creating .a library file"
	@ar rcs $(NAME) $^
	@echo "					DONE library"
	
%.o: %.c
	@echo ""
	@echo "Compiling $< $@"
	@gcc -c $< $(FLAGS)
	@echo "					DONE compiling"
	
clean:
	@rm -f $(OBJ)
	@rm -f a.out test
	@echo "					DONE cleaning objects"
	
fclean: clean
	@rm -rf $(NAME) $(TEST)
	@echo "					DONE cleaning all"

re: fclean all
	@echo "					DONE recompiling"
	
test: $(NAME)
	@echo ""
	gcc $(FLAGS) $(SRC) $(MAIN)
	@echo ""
	@./test
	@echo "				DONE testing main"

add:
	git add $(SRC) Makefile print.h
	git status
	@echo "					DONE updating git"