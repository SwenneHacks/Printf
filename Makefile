# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swofferh <swofferh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/16 17:46:43 by swofferh      #+#    #+#                  #
#    Updated: 2020/12/19 22:49:35 by sofferha      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 	= libftprintf.a
LIB 	= libft/libft.a
INC 	= printf.h
DIR		= src
BDIR	= bonus
FLAGS 	= -Wall -Werror -Wextra

SRC = ft_printf \
	percentage \
	pfunctions \
	preci_width \
	type_s \
	type_d \
	type_c \
	type_x \
	type_p \
	type_u \

OBJ = $(addprefix $(DIR)/,$(notdir $(addsuffix .o,$(SRC))))
BOBJ = $(addprefix bonus/,$(notdir $(addsuffix _bonus.o,$(SRC))))

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
	@$(CC) $(FLAGS) -I $(DIR) -c $< -o $@

bonus: $(BOBJ) $(LIB)
	@/bin/rm -rf $(NAME)
	@ar rcs $(NAME) $^
	@ar -q $(LIB) $(BOBJ)
	@cp $(LIB) $(NAME)
	@mkdir -p obj
	@mv $(BOBJ) obj
	@echo "\n$(Y)Dooone$(W) adding bonus to $(NAME) :)\n\n"
	@echo "\n\n$(W)	   Done with"
	@echo "	     $(P)B$(G)O$(Y)N$(R)U$(B)S"
	@echo "	$(W)    Part :)\n\n\n$(W)"

%_bonus.o: %.c
	@echo "$(B)Compiling$(W) $< $@"
	@$(CC) $(FLAGS) -I $(BDIR) -c $< -o $@

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
