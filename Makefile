# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sechang <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 16:05:33 by sechang           #+#    #+#              #
#    Updated: 2018/09/01 12:10:16 by sechang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  lettermatch.c \
	  fmtr.c \
	  charific.c \
	  numeric.c \
	  printf_u.c \
	  printf_o.c \
	  printf_x.c \
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
	
clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all