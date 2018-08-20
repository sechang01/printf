/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:48:40 by sechang           #+#    #+#             */
/*   Updated: 2018/08/19 19:34:35 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>
# define BUFF_SIZE 4200

typedef struct		s_ptbuf              
{
	char			buf[BUFF_SIZE + 1];
	int				len;
}					t_ptbuf;

typedef struct		s_flag
{
	char			flag[10];
	unsigned long	wth;
	unsigned long	prc;
	t_ptbuf			ptbuf;
}					t_flag;				//initialize to 0

int					ft_printf(const char *s, ...);
t_flag				flagnlen(t_flag *match, char c, char key);
int					flag_found(char c);
int					printf_c(char c);


#endif