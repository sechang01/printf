# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 16:05:33 by sechang           #+#    #+#              #
#    Updated: 2018/08/31 22:21:20 by sechang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  lettermatch.c \
	  fmtr.c \
	  charific.c \
	  numeric.c \
	  octdechex.c \
	  itoabase.c \
	  ft_bzero.c \
	  ft_get_intlen.c \
	  ft_isdigit.c \
	  ft_itoa.c \
	  ft_strcpy.c \
	  ft_strlen.c \
	  ft_strsub.c 

OBJ = $(SRC:.c=.o)
all: $(NAME)

$(NAME): 
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)	
#	gcc $(FLAGS) main.c $(SRC) $(NAME)
	
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all