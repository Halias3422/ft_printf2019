# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: vde-sain <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/07 13:44:20 by vde-sain     #+#   ##    ##    #+#        #
#    Updated: 2019/01/23 11:00:13 by vde-sain    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_SRC = libft/ft_memset.c \
	  libft/ft_strlen.c \
	  libft/ft_strdup.c \
	  libft/ft_strcpy.c \
	  libft/ft_strncpy.c \
	  libft/ft_strcmp.c \
	  libft/ft_strncmp.c \
	  libft/ft_atoi.c \
	  libft/ft_bzero.c \
	  libft/ft_strcat.c \
	  libft/ft_strncat.c \
	  libft/ft_strlcat.c \
	  libft/ft_isdigit.c \
	  libft/ft_isalpha.c \
	  libft/ft_isalnum.c \
	  libft/ft_isascii.c \
	  libft/ft_isprint.c \
	  libft/ft_toupper.c \
	  libft/ft_tolower.c \
	  libft/ft_strchr.c \
	  libft/ft_strstr.c \
	  libft/ft_strnstr.c \
	  libft/ft_memcpy.c \
	  libft/ft_memccpy.c \
	  libft/ft_memmove.c \
	  libft/ft_memchr.c \
	  libft/ft_memcmp.c \
	  libft/ft_strrchr.c \
	  libft/ft_putchar.c \
	  libft/ft_putstr.c \
	  libft/ft_putnbr.c \
	  libft/ft_putendl.c \
	  libft/ft_strclr.c \
	  libft/ft_striter.c \
	  libft/ft_striteri.c \
	  libft/ft_strmap.c \
	  libft/ft_strmapi.c \
	  libft/ft_strequ.c \
	  libft/ft_strnequ.c \
	  libft/ft_putchar_fd.c \
	  libft/ft_putstr_fd.c \
	  libft/ft_putendl_fd.c \
	  libft/ft_putnbr_fd.c \
	  libft/ft_strsub.c \
	  libft/ft_strjoin.c \
	  libft/ft_strtrim.c \
	  libft/ft_memalloc.c \
	  libft/ft_memdel.c \
	  libft/ft_strnew.c \
	  libft/ft_strsplit.c \
	  libft/ft_strdel.c \
	  libft/ft_itoa.c \
	  libft/ft_lstnew.c \
	  libft/ft_lstdelone.c \
	  libft/ft_lstdel.c \
	  libft/ft_lstadd.c \
	  libft/ft_lstiter.c \
	  libft/ft_lstmap.c \
	  libft/ft_putnstrn.c \
	  libft/ft_strndup.c \
	  libft/ft_isblank.c \
	  libft/ft_isupper.c \
	  libft/ft_list_last.c \
	  libft/ft_range.c \
	  libft/ft_strrev.c \
	  libft/ft_itooct.c \
	  libft/ft_swap_let_string.c \
	  libft/check_num_length.c \
	  libft/ft_copy_part_str.c \
	  libft/ft_itoh.c

PRINTF_SRC = ft_printf/add_conversion.c \
	  ft_printf/add_flags.c \
	  ft_printf/conversion_type.c \
	  ft_printf/conversion_type2.c \
	  ft_printf/determ_data.c \
	  ft_printf/free.c \
	  ft_printf/ft_printf.c \
	  ft_printf/handle_float.c \
	  ft_printf/handle_prec_and_width.c \
	  ft_printf/handle_flags_order.c

LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

CC = @gcc

FLAGS = -Wall -Werror -Wextra
CFLAGS = -I. -c

OBJ_DIR = objects/

HEADERS = libft.h \
		  ft_printf.h

all : $(NAME)

$(NAME): $(LIBFT_OBJ) $(PRINTF_OBJ)
	@ar rcs $(NAME) $(LIBFT_OBJ) $(PRINTF_OBJ)
	@ranlib $(NAME)
	@echo "\033[1;32mLIBFT					OK\033[0m"
	@echo "\033[1;32mFT_PRINTF				OK\033[0m"

$(OBJ_DIR)%.o: %.c
	@$(CC) $(CFLAGS) $^

clean:
	@rm -f $(LIBFT_OBJ)
	@rm -f $(PRINTF_OBJ)
	@rm -f *.gch
	@rm -rf *.dSYM
	@echo "\033[1;31mCLEAN LIBFT				OK\033[0m"
	@echo "\033[1;31mCLEAN FT_PRINTF				OK\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out
	@echo "\033[1;31mFCLEAN LIBFT				OK\033[0m"
	@echo "\033[1;31mFCLEAN FT_PRINTF			OK\033[0m"

re: fclean all

.PHONY : all clean fclean re
