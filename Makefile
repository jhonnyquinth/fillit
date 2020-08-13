# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbrynn <sbrynn@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 03:01:45 by iuolo             #+#    #+#              #
#    Updated: 2019/11/21 16:48:30 by sbrynn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

INC=includes/fillit.h

LIBFT := includes/libft

SRC		:= src/main.c \
		   src/valid.c \
		   src/brute_force.c \
		   src/map.c \
		   src/solution.c


OBJ		:= $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

all: $(NAME)

$(NAME):
	make -C $(LIBFT)
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) -I $(INC) includes/libft/libft.a $<
clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all

.PHONY: fclean clean re