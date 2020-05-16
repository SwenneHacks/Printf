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
FLAGS 	= -Wall -Werror -Wextra
BTEST 	= test.c
DTEST	= test_d.c
DIR 	= lib/

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

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@ar rcs $@ $^
	@ranlib $(NAME) $(DIR)$(LIB)
	@mkdir obj
	@mv $(OBJ) obj
	@echo "~~~~ Done creating libftprintf.a \n"
	
%.o: %.c
	@echo "Compiling $< $@"
	@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
	
clean:
	@$(RM) -rf obj
	@echo "Removing $@"
	@$(RM) $(DIR)test
	@echo "~~~~ Done Cleaning \n"
	
fclean: clean
	@$(RM) $(NAME)
	@echo "Removing $@"
	@echo "~~~~ Done with (F)abulous (Clean)ing \n"

re: fclean all
	@echo "~~~~ Done Restarting \n"

testB: re
	$(CC) test/$(BTEST) $(NAME) -o test/test
	@echo ""
	@./test/test

testD: re
	$(CC) $(FLAGS) test/$(DTEST) $(NAME) -o test/test_d
	@echo ""
	@./test/test_d

fix: re
	@gcc -g $(SRC)
	@echo "---- Done compiling for debugger.\n"
	@./a.out

add:
	git add $(SRC) Makefile $(INC) $(TEST)
	git status
