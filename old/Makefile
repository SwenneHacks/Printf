# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swofferh <swofferh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/16 17:46:43 by swofferh       #+#    #+#                 #
#    Updated: 2019/12/22 21:42:57 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
INC = printf.h
TEST = main.c
FLAGS = -Wall -Wextra -Werror -g

LIBDIR = libft
LIBNAME = libft.a

SRC = ft_printf.c ft_print_functions.c ft_check_flags.c ft_check_conversions.c \

OBJ = $(SRC:.c=.o)

.PHONY: clean fclean re bonus test

all: library $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@cp libft/$(LIBNAME) $(NAME)
	@ar rcs $(NAME) $^
	
%.o: %.c
	@echo "Compiling $< $@"
	@gcc -c $< $(FLAGS)
	
clean:
	@rm -f $(OBJ)
	@rm -f a.out test
	
fclean: clean
	@cd $(LIBDIR) && make fclean
	@rm -f $(NAME)

re: fclean all

library:
	@echo "Compiling Libft first:"
	@cd libft && $(MAKE) all
	
test: $(NAME)
	gcc $(TEST) -L. -lftprintf -Ilibft -Llibft -lft -g -fsanitize=address -o test 
	@echo ""
	@./test | cat -e

add:
	git add $(SRC) Makefile $(INC) $(TEST)
	git status