# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: niabraha <niabraha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 14:27:18 by tclaereb          #+#    #+#              #
#    Updated: 2024/06/11 16:40:34 by niabraha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

_SRCS = colors.c \
		hooks.c \
		init.c \
		main.c \
		maths.c \
		utils.c

SRCS_DIR = src

SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))

SRCO = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror
INC = -I includes/

all : $(NAME)

$(NAME) : $(SRCO) 
	cc $(FLAG) -o $(NAME) $(SRCO) -L minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd

%.o : %.c
	cc $(FLAG) -c $< -o $@ $(INC)

clean :
	/bin/rm -f $(SRCO)

fclean : clean
	/bin/rm -f $(NAME)

re :
	make fclean
	make