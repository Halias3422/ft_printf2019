# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/07 13:44:20 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2019/01/07 20:07:28 by dcoat       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_printf

SRC =

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Werror -Wextra

LIBFT = ./libftprintf/

LIBFT.A = ./libftprintf/libftprintf.a

all : libs $(NAME)

$(NAME): $(OBJ) $(LIBFT.A)
		@$(CC) -o $(NAME) $(OBJ) $(LIBFT.A)
		@echo "\033[1;32mFDF				OK\033[0m"

libs:
		@(cd $(LIBFT) && $(MAKE))

%.o: %.c ft_printf.h
		@$(CC) $(FLAGS) -I. -c $(SRC)

clean:
		@rm -f $(OBJ)
		@rm -f *.gch
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mCLEAN FDF			OK\033[0m"

fclean: clean
		@rm -f $(NAME)
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mFCLEAN FDF			OK\033[0m"

re: fclean all

.PHONY : all clean fclean re
