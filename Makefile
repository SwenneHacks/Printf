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

NAME 	= libftprintf.a
LIB 	= libft.a
INC 	= printf.h
FLAGS 	= -Wall -Wextra -Werror
TEST 	= test.c
TRASH	= a.out test test_p test_s

DIR = lib/

SRC = 	src/ft_printf.c \
		src/functions.c \
		src/percentage.c \
		arg/type_s.c \
		arg/type_d.c \
		arg/type_c.c \
		arg/type_x.c \
		arg/type_p.c \
		arg/type_u.c \

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@ar rcs $@ $^
	@ranlib $(NAME)
	@mv $(NAME) $(DIR)
	@mkdir obj
	@mv $(OBJ) obj
	@echo "~~~~ Done creating libftprintf.a \n"
	
%.o: %.c
	@echo "Compiling $< $@"
	@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
	
clean:
	@$(RM) -rf obj
	@echo "Removing $@"
	@$(RM) $(TRASH)
	@echo "~~~~ Done Cleaning \n"
	
fclean: clean
	@$(RM) $(DIR)$(NAME)
	@echo "Removing $@"
	@echo "~~~~ Done with Fabulous Cleaning \n"

re: fclean all
	@echo "~~~~ Done Restarting \n"

test: re
	$(CC) $(FLAGS) $(TEST) $(DIR)$(LIB) $(DIR)$(NAME) -o test
	@echo ""
	@./test
	
add:
	git add $(SRC) Makefile $(INC) $(TEST)
	git status
