#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykichena <ykichena@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/18 23:04:14 by ykichena          #+#    #+#              #
#    Updated: 2014/01/19 12:16:46 by ykichena         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

SRC =	main.c\
		ft_draw_lets_go.c\
		ft_read_and_parser.c\
		ft_tools.c\
		ft_draw_wall.c\
		ft_keycode.c\

OBJ = $(SRC:.c=.o)

DIR = libft/

FLAGS = -Wall -Wextra -Werror

FLAG_LIB = -L. -lft -L/usr/X11/lib -lXext -lmlx -lX11

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(DIR)
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(FLAG_LIB) -L $(DIR)
	@echo "\033[1;32m" Done !

%.o: %.c
	@echo Compilating wolf3d please wait
	@gcc $(FLAGS) -c $(SRC) -I $(DIR)/includes

clean :
	@make clean -C $(DIR)
	@rm -f $(OBJ)

fclean : clean
	@make fclean -C $(DIR)
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
