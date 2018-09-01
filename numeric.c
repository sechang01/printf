/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:02:51 by sechang           #+#    #+#             */
/*   Updated: 2018/08/31 22:19:33 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
void		printf_d(t_flag *mods)
{
		char	*x;
		unsigned long long		len;
		unsigned long long		newlen;

// Read in argument, store into x as char *
		printf("flags=%d\n", mods->flag[10]);
		x = (mods->flag[10] == 'D') ? imax_itoa(va_arg(mods->vg, long)) : \
			numx(mods); //ft_itoa(va_arg(mods->vg, int));
//		printf("x=%s\n", x);
// Find string length of char *
		printf("s= %s", x);
		len = (unsigned long long)ft_strlen(x);
		if (len == 1 && x[0] == '0' && mods->flag[11] == 0 && mods->flag[4] == 0 && mods->preci == 0)
		{
			if (mods->flag[0] > 0 && mods->width == 0)
				return ;
			else if (mods->flag[0] > 0 && mods->preci == 0)
				x[0] = ' ';
		} 
// If number is negative, remove 1 from len;
		newlen = len;
		if ((x[0] == '-') && ((mods->preci > mods->width) || (mods->preci > (len - 1))))
			len--;
//	printf("len=%llu\n", len);
// Use temp variable to add modify length (because we compare newlen with width)
// We still need original len to compare with precision later
		if (mods->flag[5] > 0 && mods->flag[4] == 0 && x[0] != '-')
			newlen++;
		if (mods->preci > len)
			newlen = newlen + (mods->preci - len);
		if (mods->flag[4] > 0 && x[0] != '-')
			newlen++;
//		printf("%s\n", mods->store->buf);
//		printf("3dnlen=%llu\n", len);
//		printf("3dnlen=%llu\n", newlen);
// If no flag '-', no flag '0', but width > preci, print [zero or space]
//		printf("flag2:%d\n", mods->flag[2]);
//		printf("flag3:%d\n", mods->flag[3]);
		if (mods->flag[3] == 0 && mods->flag[2] == 0 && (mods->width > mods->preci))
			width_n_c(mods, newlen, 'n');
//		printf("%s\n", mods->store->buf);
	//	print '-', '+', or ' ' in that order.
		if (x[0] == '-')
			mods->store->buf[mods->i++] = *x++;
		else if (mods->flag[4] > 0)
			mods->store->buf[mods->i++] = '+';
		else if (mods->flag[5] > 0)
			mods->store->buf[mods->i++] = ' ';
	//	print zero
		
//		printf("%s\n", mods->store->buf);
		if (mods->flag[3] == 0 && mods->flag[2] > 0)
			width_n_c(mods, newlen, 'n');
	//	print zeros
//	printf("len=%llu\n", len);
		len = preci(mods, len);
//		printf("%s\n", mods->store->buf);
		if (*x == '-' && mods->flag[2] == 0)
			mods->store->buf[mods->i++] = *x++;

//		printf("%s\n", mods->store->buf);
		while (*x)
			mods->store->buf[mods->i++] = *x++;

//		printf("%s\n", mods->store->buf);
		if (mods->flag[3] > 0)
			width_n_c(mods, newlen, 'n');
}