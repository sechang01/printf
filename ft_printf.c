/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:15:24 by sechang           #+#    #+#             */
/*   Updated: 2018/08/19 19:34:32 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatch.h"
#include <stdio.h>
#include <unistd.h>


void		prntout(t_ptbuf otpt)
{
		int			i;

		write(1, otpt.buf, otpt.len); //BUFF_SIZE);
}

// deals with found '\' or '%'. stores %str into ptbuf. returns i for store function to jump ahead i.
int		parse(const char *s, va_list vg)
{
		int			i;
		int			g;
		t_flag		*mods;	


		if (!(mods = (t_flag *)malloc(sizeof(t_flag))))
			return (0);
//		intmax_t 
		i = 0;
		if (*s == '\\') // what happens when you do \x? && ...?
		{
			return (0);  //return what?.
		}
		if (*s == '%')
		{
			flagnlen(mods, 0, 'c');
			while (flag_found(*s))  // s++ for all;
			{
				flagnlen(mods, *s, 'a');
			}
			while (ft_isdigit(*s))  // what if 2nd '%' at any point?
			{
				mods->wth += mods->wth * 10;
			}
			if (*s == '.' && (*s++))
			{
				while (ft_isdigit(*s))
					mods->prc += mods->prc * 10;
			}
			while (flag_found(*s))
			{
				flagnlen(mods, *s, 'b');
			}
			g = 0;
			while (g < 14 && *s != g_type.fmt[g++] || *s != '%')
			{
				s++;
			}
			 g_type[--g].f(mods);
				
			// dispatch table
			//
			// va_arg(vg, char *)
			//
			// print (or store in print buf
			// next % + arg if exists

			//legal char's after %?	
			//look for flags, #, 0, -, +, _ // num?
			//minimum field with
			//precision field with
			//length
			//convertion type
		}
		return (0);
}

// storing into pbuf for the purpose of using write function once.
int		store_to_buf(const char *s, va_list vg)
{
		int			i;
		t_ptbuf		*store;

		i = 0;
		store = (t_ptbuf *)malloc(sizeof(t_ptbuf));
		ft_bzero(store->buf, BUFF_SIZE + 1);
		store->len = 0;
		while (*s)
		{
			if (*s == '/' || *s == '%') 
			   	parse(s, vg);
			else
				store->buf = *s;
			s++;
		}
		store->len = ft_strlen(store->buf);
		store->buf[store->len + 1] = '\0';
		prntout(*store);
		return (0);
}

//dealing with argument 2+ as variables or not variables.

int		ft_printf(const char *s, ...)
{
	va_list		vg;
	int			i;

	va_start(vg, s);
//	if (s[0] == '"')
		store_to_buf(s, vg);
	return (0);
//	va_arg(vg, char *)
}


int		main(void)
{
	ft_printf("hello walker pizza!");
//	printf("sdklflsj%#42.42ll%d", 100);

	return (0);
}