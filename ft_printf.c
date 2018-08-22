/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:15:24 by sechang           #+#    #+#             */
/*   Updated: 2018/08/21 19:23:18 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatch.h"
#include <stdio.h>
#include <unistd.h>


void		prntout(t_printbuf otpt)
{
		int			i;

		printf("\n\nOutput: \n-----------------------------\n\n\n");
		write(1, otpt.buf, otpt.len); //BUFF_SIZE);
		printf("\n\n\n-----------------------------\n");
		getchar();
}

// deals with found '\' or '%'. stores %str into ptbuf. returns i for store function to jump ahead i.
int		parse(char *s, t_flag *mods)
{
//		int			i;
		int			g;
//		t_flag		*mods;	
//intmax_t
		initzero(mods);
		printf("\n\nInitiating Parse\n");
		if (*s == '\\') // what happens when you do \x? && ...?
		{
			return (0);  //return what?.
		}
		if (*s == '%')
		{
			printf("%% Found\n");
			chrfmt(mods, 0, 'c');
			while (flag_found(*s))  // s++ for all;
			{
				printf("Flag Found\n");
				chrfmt(mods, *s, 'a');
				s++;
			}
			while (ft_isdigit(*s))  // what if 2nd '%' at any point?
			{
				printf("Field Width\n");
				mods->width *= 10;
				mods->width += *s - '0';
				s++;
			}
			printf("Field Width=\t%lu\n", mods->width);
			if (*s == '.' && (*s++))
			{
				printf("Precision Width\n");
				while (ft_isdigit(*s))
				{
					mods->preci *= 10;
					mods->preci += *s - '0';
					s++;
				}
			}
			printf("Field Preci=\t%lu\n", mods->preci);
			while (flag_found(*s))
			{
				printf("Modifier Found\n");
				chrfmt(mods, *s, 'b');
			}
			g = 0;
			printf("------: %c\n", *s);
			while (g < 15 && *s != g_type[g++].fmt)
			{
				//getchar();
				printf("%d\n", g);
				printf("Dispatch Table - Format\n");
//				s++;
			}

			printf("Format Found?\n");
			/// send va-arg directly to handler fnctn
//			chrfmtb(mods, 0, 'c');
//			chrfmtb(mods, *s, 'a');
			g_type[--g].f(mods);
				
//			mods.varg = va_arg(vg, char *);
//			printf("%d", 1000);
//			"1000"
			//
			// print (or store in print buf
			// next % + arg if exists
		}
		return (0);
}

// storing into pbuf for the purpose of using write function once.
int		store_to_buf(char *s, t_flag *mods)
{

		mods->store = (t_printbuf *)malloc(sizeof(t_printbuf));
		ft_bzero(mods->store->buf, BUFF_SIZE + 1);
		mods->store->len = 0;
		mods->i = 0;
		while (*s)
		{
			if (*s == '/' || *s == '%') 
			   	parse(s, mods);
			else
				mods->store->buf[mods->i] = *s;
			printf("\t\t---------: %c\n", *s);
			printf("%d--------: %c\n", mods->i, mods->store->buf[mods->i]);
			s++;
			mods->i++;
		}
		mods->store->len = ft_strlen(mods->store->buf);
		printf("strlen= %d", mods->store->len);
		mods->store->buf[mods->store->len + 1] = '\0';
		prntout(*mods->store);
		return (0);
}

//dealing with argument 2+ as variables or not variables.

int		ft_printf(const char *s, ...)
{
	t_flag		*mods;

	if (!(mods = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
	va_start(mods->vg, s);
//	if (s[0] == '"')
		store_to_buf((char *)s, mods);
	return (0);
//	va_arg(vg, char *)
}

int		main(void)
{
	char	s[] = "asdfg";

//	ft_printf("hello walker pizza!\n");
//	printf("sdklflsj%-----10s", "mmm");

//	c
//	ft_printf("hello everyone%5.30c\n", '!');

//  s
//	ft_printf("hello everyone%5.30s\n", "he");

//	d
//	ft_printf("hello everyone%1.30111111111d\n", 10042);

// u
//	ft_printf("hellooo%3.100u\n", 987654321);
//x
	ft_printf("heylo...%x\n", 31);
	return (0);
}