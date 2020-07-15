# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swofferh <swofferh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/16 17:46:43 by swofferh      #+#    #+#                  #
#    Updated: 2020/07/10 20:59:41 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
INC 	= printf.h
FLAGS 	= -Wall -Werror -Wextra
LIB 	= libft/libft.a

SRC = src/ft_printf.c \
	src/percentage.c \
	src/pfunctions.c \
	src/preci_width.c \
	src/type_s.c \
	src/type_d.c \
	src/type_c.c \
	src/type_x.c \
	src/type_p.c \
	src/type_u.c \

OBJ = $(SRC:%.c=%.o)
BOBJ = $(SRC:%.c=%_bonus.o)

P = \x1b[35m
B = \x1b[34m
Y = \x1b[33m
G = \x1b[32m
R = \x1b[31m
W = \x1b[0m

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@ar rcs $@ $^
	@ar -q $(LIB) $(OBJ)
	@echo "\n$(Y)Adding$(W) srcs to $@"
	@cp $(LIB) $(NAME)
	@echo "\n$(Y)Adding$(W) libft to $@"
	@mkdir -p obj
	@mv $(OBJ) obj
	@echo "\n$(Y)Dooone$(W) creating $@"

$(LIB):
	@echo "$(Y)NOW $(W)libft"
	@$(MAKE) -C libft 

%.o: %.c
	@echo "$(B)Compiling$(W) $< $@"
	@$(CC) $(FLAGS) -I $(INC).h -c $< -o $@

bonus: $(BOBJ) $(LIB)
	@/bin/rm -rf $(NAME)
	@ar rcs $(NAME) $^
	@ranlib $(NAME)
	@mkdir -p obj
	@mv $(BOBJ) obj
	@echo "\n$(Y)Dooone$(W) adding bonus to $(NAME) :)\n\n"

%_bonus.o: %.c
	@echo "$(B)Compiling$(W) $< $@"
	@$(CC) $(FLAGS) -I $(INC) -c $< -o $@

clean:
	@echo "\n$(G)$@ $(B)printf"
	@$(RM) -rf obj
	@$(RM) $(OBJ)
	@echo "$(Y)~~~~~~~~~~~~ Done\n"

fclean: clean
	@$(MAKE) fclean -C libft
	@echo "$(G)$@ $(B)printf"
	@$(RM) -rf $(NAME)
	@echo "$(Y)~~~~~~~~~~~~ Done\n"

re: fclean all
	@echo "\n\n$(W)	   Done"
	@echo "	$(P)RE$(G)ST$(Y)AR$(B)TING"
	@echo "	$(W)   Printf.\n\n\n$(W)"
