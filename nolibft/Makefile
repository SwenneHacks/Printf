# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swofferh <swofferh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/16 17:46:43 by swofferh      #+#    #+#                  #
#    Updated: 2020/06/16 15:51:00 by sofferha      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
INC 	= printf.h

SRC 	= ft_printf.c \
		percentage.c \
		functions.c \
		type_s.c \
		type_d.c \
		type_c.c \
		type_x.c \
		type_p.c \
		type_u.c \

OBJ = $(SRC:%.c=%.o)

PINK	= \x1b[35m
BLUE	= \x1b[34m
YELLOW	= \x1b[33m
GREEN	= \x1b[32m
RED		= \x1b[31m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@ranlib $@
	@mkdir -p obj
	@mv $(OBJ) obj
	@echo "\n$(YELLOW)Dooone$(RESET) creating $@"

%.o: %.c
	@echo "$(BLUE)Compiling$(RESET) $< $@"
	@$(CC) -I $(INC) -c $< -o $@
	
clean:
	@echo "\n$(BLUE)$@"
	@$(RM) -rf obj
	@$(RM) $(OBJ)
	@echo "$(YELLOW)~~~~ Done Cleaning\n$(RESET)"
	
fclean: clean
	@echo "\n$(BLUE)$@"
	@$(RM) -rf $(NAME)
	@echo "$(YELLOW)~~~~ Done Fabulous cleaning \n$(RESET)"

re: fclean all
	@echo "\n\n$(RESET)	   Done"
	@echo "	$(PINK)RE$(GREEN)ST$(YELLOW)AR$(BLUE)TING"
	@echo "	$(RESET)   Printf.\n$(RESET)"

