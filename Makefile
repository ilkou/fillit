# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oouklich <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/18 14:32:27 by oouklich          #+#    #+#              #
#    Updated: 2019/01/25 21:51:34 by oouklich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = bloc.c\
      check.c\
      coordn.c\
      get_next_line.c\
      init.c\
      main.c\
      math.c\
      solve.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(FLAGS) $+ -o $@ -lft -L libft -I libft

$(OBJ): %.o: %.c
	gcc $(FLAGS) -c $< -o $@
clean:
	@make clean -C libft
	@rm -f *.o

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all
.PHONY: all, re, clean, fclean
