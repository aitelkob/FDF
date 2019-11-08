# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yait-el- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 02:58:50 by yait-el-          #+#    #+#              #
#    Updated: 2019/11/06 13:33:48 by yait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a  \
		minilibx_macos/libmlx.a 
INC = fdf.h libft/libft.h
SRC = main.c get_next_line.c read_fill_store.c
OBJ = $(SRC:.c=.o)

all: $(NAME) 
$(NAME):$(INC) $(OBJ)  
		@echo "\033[95m**********make libft and minilibx_macos [OK]"
		@make -C ./libft
	    @Make -C ./minilibx_macos
		@echo "\033[92m**********done!\033[0m [OK]"
		@ $(CC) $(CFLAGS) $(OBJ) $(LIB) -framework OpenGL -framework AppKit -o $(NAME)
clean:
		@echo "\033[94mcleaning..."
		@Make clean -C ./libft
		@Make clean -C ./minilibx_macos
		@rm -rf $(OBJ) 
		@echo "\033[91m**********object files removed!\033[0m [OK]"
		@echo "\033[91mdone!\033[0m"
fclean: clean 
		@rm -f $(NAME)
		@echo "\033[93m**********fdf executable removed!\033[0m [OK]"
		@Make fclean -C ./libft 
		#@Make fclean -C ./minilibx_macos
		@echo "\033[92m**********executable removed!\033[0m [OK]"
		
re: fclean all
norme:
		@echo "\033[96m**********norminette..."
		norminette $(SRC)
		norminette fdf.h
