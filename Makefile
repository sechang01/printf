# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 16:05:33 by sechang           #+#    #+#              #
#    Updated: 2018/08/24 17:05:02 by sechang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
FLAGS = -Wall -Wextra -Werror
CC = gcc

OPTION = -c -I

SRC = ft_printf.c lettermatch.c fmtr.c charific.c numeric.c octdechex.c itoabase.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	make -C libft/
	$(CC) $(FLAGS) -I ./libft/includes/ -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	gcc -g main.c $(SRC) ./libft/libft.a

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all