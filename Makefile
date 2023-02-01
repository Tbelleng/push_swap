# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbelleng <tbelleng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 15:19:51 by tbelleng          #+#    #+#              #
#    Updated: 2023/01/30 16:03:31 by tbelleng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	checker.c	\
	main.c      \
	push.c		\
	reverse.c	\
	rotate.c 	\
	sort_x.c 	\
	sorting_choice.c \
	swap.c 		\
	three_five_sort.c \
	utils.c		\
	utils2.c    \


OBJ = $(SRC:.c=.o)

CC = cc

NAME = push_swap

CFLAGS =	-Wall -Wextra -Werror

all :	$(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re