# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 14:27:18 by tclaereb          #+#    #+#              #
#    Updated: 2024/05/29 16:49:40 by niabraha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_F = fractol

_SRCS = errors.c \
		init.c \
		introduction.c \
		main.c \
		maths.c \
		render.c \
		utils.c

SRCS_DIR = src

SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))

SRCO = $(SRCS:.c=.o)

FLAG = -g3 -Wall -Wextra -Werror -fsanitize=address
INC = -I includes/

all : $(NAME_C) $(NAME_F)

$(NAME_F) : $(SRCO) 
	cc $(FLAG) -o $(NAME_F) $(SRCO) MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm

%.o : %.c
	cc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO)

fclean : clean
	/bin/rm -f $(NAME_F)

re :
	make fclean
	make