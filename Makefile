# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/07 13:44:20 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2019/01/18 11:18:14 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = ft_printf

SRC = main.c \
	  ft_printf.c \
	  determ_data.c \
	  add_conversion.c \
	  conversion_type.c \
	  conversion_type2.c \
	  add_flags.c \
	  handle_float.c \
	  free.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS = -g3 -Wall -Werror -Wextra

LIBFT = ./libftprintf/

LIBFT.A = ./libftprintf/libftprintf.a

all : libs $(NAME)

$(NAME): $(OBJ) $(LIBFT.A)
		@$(CC) -o $(NAME) $(OBJ) $(LIBFT.A)
		@echo "\033[1;32mFT_PRINTF				OK\033[0m"

libs:
		@(cd $(LIBFT) && $(MAKE))

%.o: %.c ft_printf.h
		@$(CC) $(FLAGS) -I. -c $(SRC)

clean:
		@rm -f $(OBJ)
		@rm -f *.gch
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mCLEAN FT_PRINTF			OK\033[0m"

fclean: clean
		@rm -f $(NAME)
		@(cd $(LIBFT) && $(MAKE) $@)
		@echo "\033[1;31mFCLEAN FT_PRINTF			OK\033[0m"

re: fclean all

.PHONY : all clean fclean re
