# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 02:58:50 by yait-el-          #+#    #+#              #
#    Updated: 2019/10/31 19:32:34 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a 

SRC = main.c get_next_line.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME):$(OBJ)
		@echo "\033[95mmake libft and minilibx_macos"
		@make -C ./libft
	    @Make -C ./minilibx_macos
		@echo "\033[92mdone!\033[0m"
		$(CC) $(CFLAGS) $(OBJ) $(LIB)  -o $(NAME)
clean:
		@echo "\033[94mcleaning..."
		@Make clean -C ./libft
		#@Make clean -C ./minilibx_macos
		rm -rf $(OBJ) 
		@echo "\033[93mlibft and minilibx  object files removed!\033[0m"
		@echo "\033[92mdone!\033[0m"
fclean: clean 
		@rm -f $(NAME)
		@echo "\033[93mfdf executable removed!\033[0m"
		@Make fclean -C ./libft 
		@Make fclean -C ./minilibx_macos
		@echo "\033[92mdone!\033[0m"
		
re: fclean all
norme:
		@echo "\033[96mnorminette...""]"
		norminette $(SRC)
		norminette fdf.h
