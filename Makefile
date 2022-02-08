# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 00:47:28 by jihoh             #+#    #+#              #
#    Updated: 2022/02/09 01:43:19 by jihoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall

NAME = push_swap

HEADER = include

SRCS = $(addprefix src/, main.c choose_best_elem.c do_op.c op.c ft_utils.c \
			get_values.c pb_and_set_b.c simple_sort.c stack_utils.c)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ -I $(HEADER)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "done"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADER)

clean:
	@rm -rf $(OBJS)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "clean"

fclean: clean
	@rm -rf $(NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "fclean"

re: fclean all

.PHONY: all clean fclean re
