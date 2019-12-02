# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: babdelka <babdelka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 02:58:50 by yait-el-          #+#    #+#              #
#    Updated: 2019/11/28 03:48:28 by babdelka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a  \
		minilibx_macos/libmlx.a 
INC = inc/fdf.h libft/libft.h inc/get_next_line.h
SRC = src/main.c src/get_next_line.c src/read_fill_store.c src/keys.c \
	src/drawing.c src/iso.c src/putpixel.c src/mouse.c
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
