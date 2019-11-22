# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/01 12:31:15 by yait-el-          #+#    #+#              #
#    Updated: 2019/11/22 11:22:26 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC = libft.h
SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_contword.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_free_2D.c \
	  ft_erreur_fd.c \
	  ft_strsplittt.c \
	  ft_whitespace.c \
	  ft_isword.c \

OBJECTS = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INC)
	@ $(CC) $(CFLAGS) -c $(SRC) $(BUID_PRINT)
	@ar rc $(NAME) $(OBJECTS)
	@echo "\033[91m**********you just make library \033[0m [OK]"
clean:
	@echo "\033[91m**********you just cleaned libft \033[0m [OK]"
	@rm -f $(OBJECTS)

fclean: clean
	@echo "\033[91m**********libft  executable removed!\033[0m [OK]"
	@ rm -f $(NAME)

re: fclean all
