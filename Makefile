NAME = fractol

SOURCES_FILES = colors.c \
				hooks.c \
				init.c \
				main.c \
				maths.c \
				utils.c

SRCS_F_DIR = src

SRCS_F = $(addprefix $(SRCS_F_DIR)/, $(SOURCES_FILES))

SRCO_F = $(SRCS_F:.c=.o)

MAKE_LIBFT = $(MAKE) -C ./libft
LIBFT = ./libft/libft.a

FLAG = -g3 -Wall -Wextra -Werror
INC = -I includes/

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NO_COLOR = \033[0m

all : $(NAME)

$(LIBFT):
	$(MAKE_LIBFT)

$(NAME) : $(SRCO_F) | $(LIBFT)
	@cc $(FLAG) -o $(NAME) $(SRCO_F) $(INC) $(LIBFT) -L minilibx-linux/ -lmlx -L/usr/include/../lib -lXext -lX11 -lm -lbsd
	@echo "$(GREEN)Fractol created!$(NO_COLOR)"

%.o : %.c
	@cc $(FLAG) -c -o $@ $< $(INC)

clean :
	@/bin/rm -f $(SRCO_F)
	@$(MAKE_LIBFT) clean
	@echo "$(YELLOW)Make clean done! $(NO_COLOR)"
        

fclean : clean
	@/bin/rm -f $(NAME)
	@$(MAKE_LIBFT) fclean
	@echo "$(RED)Make fclean done! $(NO_COLOR)"

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
