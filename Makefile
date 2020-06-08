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
INC 	= printf.h
FLAGS 	= -Wall -Werror -Wextra
LIB 	= lib/libft.a

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
	@ranlib $(NAME)
	@ar -q $(LIB) $(OBJ)
	@cp $(LIB) $(NAME)
	@echo "~~ Done linking libft.a \n"
	@mkdir obj
	@mv $(OBJ) obj
	@echo "~~~~ Done creating libftprintf.a \n"
	
%.o: %.c
	@echo "Compiling $< $@"
	@$(CC) $(FLAGS) -I $(INC) -c $< -o $@
	
clean:
	@$(RM) -rf obj
	@$(RM) $(OBJ) 
	@echo "Removing $@"
	@echo "~~~~ Done Cleaning \n"
	
fclean: clean
	@$(RM) $(NAME)
	@echo "Removing $@"
	@echo "~~~~ Done with (F)abulous (Clean)ing \n"

re: fclean all
	@echo "~~~~ Done Restarting \n"

