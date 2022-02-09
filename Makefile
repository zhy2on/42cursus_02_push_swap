# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoh <jihoh@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/09 00:47:28 by jihoh             #+#    #+#              #
#    Updated: 2022/02/09 17:14:41 by jihoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Werror -Wextra -Wall
INC = -I$(INC_DIR) -I$(LIB_DIR)$(INC_DIR)
LIB = -L$(LIB_DIR) -lft

PS_NAME = push_swap

LIB_DIR = libft/
INC_DIR = includes/
SRC_DIR = srcs/
OBJ_DIR = objs/

PS_SRCS = main.c choose_best_elem.c do_op.c op.c \
			get_values.c pb_and_set_b.c simple_sort.c stack_utils.c
PS_OBJS_NAME = $(PS_SRCS:.c=.o)
PS_OBJS = $(addprefix $(OBJ_DIR), $(PS_OBJS_NAME))

all: $(PS_NAME)

$(PS_NAME): $(PS_OBJS)
	@make -C $(LIB_DIR)
	$(CC) $(CFLAGS) $(PS_OBJS) -o $@ $(LIB)
	@printf '\033[32m[ ✔ ] %s\n\033[0m' "push_swap done"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@make -C $(LIB_DIR) clean
	@rm -rf $(OBJ_DIR)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "clean"

fclean: clean
	@make -C $(LIB_DIR) fclean
	@rm -rf $(PS_NAME)
	@printf '\033[31m[ ✔ ] %s\n\033[0m' "fclean"

re: fclean all

.PHONY: all clean fclean re
