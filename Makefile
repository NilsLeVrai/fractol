# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 14:25:31 by niabraha          #+#    #+#              #
#    Updated: 2024/05/29 13:59:56 by niabraha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_F = fractol

SRC = errors.c \
		init.c \
		introduction.c \
		main.c \
		maths.c \
		utils.c 

SRCS_DIR = src

SRCO_F = $(addprefix $(SRCS_DIR)/, $(SRC))

FLAG = -O3 -Wall -Wextra -Werror -fsanitize=address -g3 -I./MLX42/include/MLX42

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

MLX = ./MLX42/build/libmlx42.a

all : $(NAME_F) $(MLX)

$(MLX) : 
	@cmake ./MLX42 -B ./MLX42/build && make -s -C ./MLX42/build -j4
	@rm -rf ./MLX42/build
	@rm -rf ./MLX42/CMakeFiles
	@echo "$(GREEN)MLX compiled! ✅$(NO_COLOR)"

$(NAME_F) : $(SRCO_F)
	@cc $(FLAG) -o $(NAME_F) $(SRCO_F) $(MLX)
	@echo "$(GREEN)Fractol compiled! ✅$(NO_COLOR)"

clean :
	@/bin/rm -f $(SRCO_F)
	@echo "$(YELLOW)Make clean done! 🤡$(NO_COLOR)"
	

fclean : clean
	@/bin/rm -f $(NAME_F)
	@/bin/rm -f $(SRCO_F)
	@echo "$(RED)Make fclean done! 🚮$(NO_COLOR)"

re :
	make fclean
	make
