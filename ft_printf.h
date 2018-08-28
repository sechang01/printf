/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 16:48:40 by sechang           #+#    #+#             */
/*   Updated: 2018/08/27 23:36:22 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/includes/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <locale.h>
# define BUFF_SIZE 10000

typedef struct		s_printbuf              
{
	char			buf[BUFF_SIZE + 1];
	int				len;
}					t_printbuf;

typedef struct		s_flag
{
	unsigned long	i;
	int				flag[12];
	unsigned long	width;
	unsigned long	preci;
	va_list			vg;
	char			space;
	t_printbuf		*store;
}					t_flag;	

int					ft_printf(const char *s, ...);
void				initzero(t_flag *mods);
t_flag				chrfmt(t_flag *match, char c, char key);
int					parse(char **s, t_flag *mods);
int					flag_found(char c);
int					width_n_c(t_flag *mods, unsigned long long len, char key);
char				*itoabase(unsigned long long n, int base, char key);
size_t				get_intlen(unsigned long long n, int base);
char				*imax_itoa(intmax_t n);
size_t				long_get_intlen(unsigned long long n);
char				*numx(t_flag *mods);
char				*ouxx(t_flag *mods, int base, char key);

void				printf_c(t_flag *mods);
void				printf_s(t_flag *mods);
void				printf_big_s(t_flag *mods);
void				printf_d(t_flag *mods);
void				printf_u(t_flag *mods);
void				printf_x(t_flag *mods);
void				printf_o(t_flag *mods);
void				printf_p(t_flag *mods);
#endif