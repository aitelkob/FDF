# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 02:58:50 by yait-el-          #+#    #+#              #
#    Updated: 2019/10/12 02:59:00 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIBFT = libft/libft.a
SRC = main.c
SRC += 
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):$(OBJ)
		@make -C libft 
		@echo "make libft"
		@echo "\033[92mdone!\033[0m"
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
clean:
		@echo "cleaning..."
		@make clean -C ./libft 
		rm -rf $(OBJ) 
		@echo "libft object files removed!"
		@echo "\033[92mdone!\033[0m"
fclean: clean 
		@rm -f $(NAME)
		@echo "fdf executable removed!"
		@make fclean -C ./libft 
		@echo "\033[92mdone!\033[0m"
		
re: fclean all
norme:
		norminette $(SRC)
		norminette fdf.h
