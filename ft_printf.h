/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:48:40 by sechang           #+#    #+#             */
/*   Updated: 2018/08/21 18:19:10 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stdio.h>
# define BUFF_SIZE 4200

typedef struct		s_printbuf              
{
	char			buf[BUFF_SIZE + 1];
	int				len;
}					t_printbuf;

typedef struct		s_flag
{
	int				i;
	char			flag[10];
	unsigned long	width;
	unsigned long	preci;
	va_list			vg;
	char			space;
//	intmax_t		varg;
	t_printbuf		*store;
}					t_flag;				//initialize to 0

int					ft_printf(const char *s, ...);
void				initzero(t_flag *mods);
t_flag				chrfmt(t_flag *match, char c, char key);
int					flag_found(char c);
int					width_a_b(t_flag *mods, unsigned long len, char key);
char				*ft_itoabase(int n, int base);


void				printf_c(t_flag *mods);
void				printf_s(t_flag *mods);
void				printf_d(t_flag *mods);
void				printf_u(t_flag *mods);
void				printf_x(t_flag *mods);
#endif