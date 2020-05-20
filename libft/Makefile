# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tollivan <tollivan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/04 18:55:34 by jslave            #+#    #+#              #
#    Updated: 2019/10/16 17:39:03 by tollivan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	srcs/ft_bzero.c srcs/ft_memset.c srcs/ft_strcat.c srcs/ft_strcpy.c \
		srcs/ft_strdup.c srcs/ft_strlen.c srcs/ft_strncat.c srcs/ft_strncpy.c \
		srcs/ft_strstr.c srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_putendl.c \
		srcs/ft_putnbr.c srcs/ft_putchar_fd.c srcs/ft_putstr_fd.c srcs/ft_putendl_fd.c \
		srcs/ft_putnbr_fd.c srcs/ft_isdigit.c srcs/ft_isalpha.c srcs/ft_isalnum.c \
		srcs/ft_isascii.c srcs/ft_isprint.c srcs/ft_strcmp.c srcs/ft_strclr.c \
		srcs/ft_memalloc.c srcs/ft_memdel.c srcs/ft_strnew.c srcs/ft_strdel.c \
		srcs/ft_striter.c srcs/ft_striteri.c srcs/ft_strmap.c srcs/ft_strmapi.c \
		srcs/ft_toupper.c srcs/ft_tolower.c srcs/ft_strncmp.c srcs/ft_strnstr.c \
		srcs/ft_memcpy.c srcs/ft_strequ.c srcs/ft_strnequ.c srcs/ft_memccpy.c \
		srcs/ft_itoa_base.c srcs/ft_memmove.c srcs/ft_memchr.c srcs/ft_memcmp.c srcs/ft_strchr.c \
		srcs/ft_strrchr.c srcs/ft_atoi.c srcs/ft_strlcat.c srcs/ft_strsub.c \
		srcs/ft_strjoin.c srcs/ft_itoa.c srcs/ft_strtrim.c srcs/ft_strsplit.c \
		srcs/ft_lstnew.c srcs/ft_lstdelone.c srcs/ft_lstdel.c srcs/ft_lstadd.c \
		srcs/ft_lstiter.c srcs/ft_lstmap.c srcs/ft_lstdellast.c srcs/ft_lstpushelem.c \
		srcs/ft_lstappendelem.c srcs/ft_count_if.c srcs/ft_strjoinfree.c srcs/get_next_line.c srcs/ft_atoi_base.c \
		srcs/ft_itoa_base_unsigned.c srcs/ft_atoi_long_long.c srcs/find_len_of_num.c srcs/ft_itoa_long_long.c srcs/ft_strreverse.c

SRC_PRINTF = src_printf/char_str_perc.c src_printf/precision.c src_printf/floats.c src_printf/floats_2.c \
        src_printf/floats_3.c src_printf/floats_4.c src_printf/ft_printf.c src_printf/ints.c src_printf/parsing.c \
        src_printf/pnt_uns_hex.c src_printf/str.c src_printf/utils.c src_printf/int_utils_1.c src_printf/int_utils_2.c \
        src_printf/int_utils_3.c src_printf/oct.c src_printf/hex.c src_printf/unsigned.c src_printf/unsigned_2.c src_printf/int_utils_4.c

HEADER = ./includes/libft.h

PRINTF_HEADER = ./includes/ft_printf.h

OUT = $(SRC:%.c=%.o)

OUT_PRINTF = $(SRC_PRINTF:%.c=%.o)

INCLUDES = includes

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OUT) $(OUT_PRINTF)
	ar rc $(NAME) $(OUT) $(OUT_PRINTF)
	ranlib $(NAME)

%.o: %.c $(HEADER) $(PRINTF_HEADER)
	gcc $(FLAG) -o $@ -I$(INCLUDES) -c $<

clean:
	/bin/rm -f $(OUT) $(OUT_PRINTF)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re