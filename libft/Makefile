# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: swofferh <swofferh@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/19 21:39:04 by swofferh      #+#    #+#                  #
#    Updated: 2020/06/19 22:15:14 by swofferh      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 	libft.a
INC =	libft.h
CFLAGS = -Wall -Wextra -Werror

SRC = 	ft_isalnum.c ft_isascii.c ft_isalpha.c ft_isdigit.c ft_tolower.c \
		ft_isprint.c ft_toupper.c ft_strlen.c ft_memccpy.c \
		ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_strlcpy.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c ft_putendl_fd.c \
		ft_memmove.c ft_memchr.c ft_memcmp.c ft_strncmp.c \
		ft_strchr.c ft_strrchr.c ft_strlcat.c ft_calloc.c ft_strdup.c \
		ft_strnstr.c ft_itoa.c ft_strmapi.c ft_substr.c ft_lenbase.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_maxof.c \

OBJ = $(SRC:%.c=%.o)

LIST = 	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \

BONUS = $(LIST)

B_OBJ = $(BONUS:%.c=%.o)

# COLORS
PINK	= \x1b[35m
BLUE	= \x1b[34m
YELLOW	= \x1b[33m
GREEN	= \x1b[32m
RED		= \x1b[31m
RESET	= \x1b[0m

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@echo "$(YELLOW)		Linking library..."
	@$(AR) rcs $@ $^
	@ranlib $(NAME)
	@mkdir -p obj
	@mv $(OBJ) obj
	@echo "$(GREEN)~~~~~~~~~ Done \n"

%.o: %.c
	@echo "$(PINK)Compiling$(RESET) $< $@"
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $@

clean: clean_b
	@$(RM) -rf obj
	@echo "$(GREEN)$@ $(PINK)libft"
	@echo "$(YELLOW)~~~~~~~~~~~~ Done\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(GREEN)$@ $(PINK)libft"
	@echo "$(YELLOW)~~~~~~~~~~~~ Done\n"

re: fclean all
	@echo "\n$(RESET)	   Done"
	@echo "	$(PINK)RE$(GREEN)COM$(YELLOW)PI$(BLUE)LING"
	@echo "	$(RESET)   Libft\n"

bonus: $(B_OBJ) $(OBJ) $(NAME)
	@echo ""
	@echo "$(GREEN)                 Linking bonus into library"
	@$(AR) rc $(NAME) $(B_OBJ) $(OBJ)
	@ranlib $(NAME)
	@echo "$(YELLOW)~~~~ Done \n"

clean_b:
	@$(RM) $(B_OBJ)
	@$(RM) $(OBJ)
