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

NAME = printf.a
INC = printf.h
FLAGS = -Wall -Wextra -Werror
TEST = test.c

SRC = ft_printf.c \
functions.c \
percentage.c \
conversion_s.c \
conversion_d.c \
conversion_c.c \
conversion_x.c \
conversion_p.c \
conversion_u.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@ar rcs $@ $^
	@ranlib $(NAME)
	@echo "~~~~ Done creating printf.a \n"
	
%.o: %.c
	@echo "Compiling $< $@"
	@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
	
clean:
	@$(RM) $(OBJ)
	@echo "Removing $@"
	@$(RM) a.out test
	@echo "~~~~ Done Cleaning \n"
	
fclean: clean
	@$(RM) $(NAME)
	@echo "Removing $@"
	@echo "~~~~ Done with Fabulous Cleaning \n"

re: fclean all
	@echo "~~~~ Done Restarting \n"

test: $(NAME)
	gcc $(FLAGS) $(TEST) $(NAME) -o test 
	@echo ""
	@./test

add:
	git add $(SRC) Makefile $(INC) $(TEST)
	git status
