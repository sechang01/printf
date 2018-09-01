/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 15:15:24 by sechang           #+#    #+#             */
/*   Updated: 2018/08/31 22:11:48 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "dispatch.h"
#include "libft/libft.h"

void		prntout(t_printbuf otpt)
{
//		printf("\n\nOutput: \n-----------------------------\n\n\n");
		write(1, otpt.buf, otpt.len); //BUFF_SIZE);
//		printf("$");                //illegals
//		printf("\n\n\n-----------------------------\n");
//		getchar();
}

// deals with found '\' or '%'. stores %str into ptbuf. returns i for store function to jump ahead i.
int		parse(char **s, t_flag *mods)
{
//		int			i;
		int			g;
//		t_flag		*mods;	
//intmax_t
		initzero(mods);
//		printf("\n\nInitiating Parse\n");
		if (*(*s) == '\\') // what happens when you do \x? && ...?
		{
			return (0);  //return what?.
		}
		if (*(*s) == '%' && ((*s)++))
		{
//			printf("%% Found\n");
			chrfmt(mods, 0, 'c');
			while (flag_found(*(*s)))  // s++ for all;
			{
//				printf("Flag Found: %c\n", *(*s));
				chrfmt(mods, *(*s), 'a');
//				printf("mods->flag[0]=%d\n", mods->flag[0]);
//				printf("mods->flag[1]=%d\n", mods->flag[1]);
//				printf("mods->flag[2]=%d\n", mods->flag[2]);
//				printf("mods->flag[3]=%d\n", mods->flag[3]);
//				printf("mods->flag[4]=%d\n", mods->flag[4]);
//				printf("mods->flag[5]=%d\n", mods->flag[5]);
				(*s)++;
			}
//			printf("Flag:%c\n", mods->flag[*s-1]);
			while (ft_isdigit(*(*s)))  // what if 2nd '%' at any point?
			{
//				printf("Field Width\n");
				mods->width *= 10;
				mods->width += *(*s) - '0';
				(*s)++;
			}
//			printf("Field Width=\t%lu\n", mods->width);
			
			if (*(*s) == '.' && ((*s)++))
			{
//				printf("*s= %s\n", s);
//				printf("Precision Width\n");
				mods->flag[0]++;
//				printf("%d\n", mods->flag[0]);
				if (!ft_isdigit(*(*s)))
					mods->flag[0]++;
				while (ft_isdigit(*(*s)))
				{
					mods->preci *= 10;
					mods->preci += *(*s) - '0';
					(*s)++;
				}
//				printf("*s= %s\n", s);
				if (mods->preci > 0)
					mods->flag[2] = 0;
			}
//			printf("Field Preci=\t%lu\n", mods->preci);
			while (len_found(*(*s)))
			{
//				printf("Modifier Found\n");
				chrfmt(mods, *(*s), 'b');
				mods->flag[11] = 1;
				(*s)++;
			}
			g = 0;
//			printf("------: %c\n", (*(*s)));
			while (g <= 15) // && *(*s) != g_type[g].fmt)
			{
				//getchar();
//				printf("g=%d, *s= %c, g_type[g]=%c\n", g, *(*s), g_type[g].fmt);
				
//				printf("Dispatch Table - Format\n");
//				s++;
//				printf("g=%d\n", g);
				if (*(*s) == g_type[g].fmt)
				{
					mods->flag[10] = g_type[g].fmt;
//					printf("~~~~~~~~~~~~~Format Found:  %c\n", mods->flag[10]);
					g_type[g].f(mods);
				}
				g++;
//			printf("end\n");
			}
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
			   	parse(&s, mods);
			else
				mods->store->buf[mods->i++] = *s;
//			printf("mainloop-printout: %s\n", mods->store->buf);
	//		printf("\t\t---------: %c\n", *s);
	//		printf("%d--------: %c\n", mods->i, mods->store->buf[mods->i]);
			if (mods->i >= 9000)
			{
				mods->store->len = ft_strlen(mods->store->buf);
				mods->store->buf[mods->store->len + 1] = '\0';
				prntout(*mods->store);
				mods->i = 0;
				store_to_buf(s, mods);
			}
			s++;
//			mods->i++;
		}
//		printf("*S read finished\n");
		mods->store->len = mods->i; 
//		printf("%s\n", mods->store->buf);
//		printf("strlen= %d\n", mods->store->len);
		mods->store->buf[mods->store->len + 1] = '\0';
		prntout(*mods->store);
		return (mods->store->len);
}

//dealing with argument 2+ as variables or not variables.

int		ft_printf(const char *s, ...)
{
	t_flag		*mods;

	if (!(mods = (t_flag *)malloc(sizeof(t_flag))))
		return (0);
//	mods->s_ptr = &s;
	va_start(mods->vg, s);
	return (store_to_buf((char *)s, mods));
//	return (0);
}