/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:02:51 by sechang           #+#    #+#             */
/*   Updated: 2018/08/31 00:00:55 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_d(t_flag *mods)
{
		char	*x;
		unsigned long long		len;
		unsigned long long		newlen;

		x = (mods->flag[10] == 'D') ? ft_itoa(va_arg(mods->vg, unsigned int)) : \
			numx(mods); //ft_itoa(va_arg(mods->vg, int));
		len = (mods->flag[4] > 0 && x[0] != '-') ? (unsigned long long)\
			ft_strlen(x) : (unsigned long long)ft_strlen(x);
		if (x[0] == '-')
			len--;
		newlen = len;
		printf("1dlen=%llu\n", len);
//		if (x[0] == '0' && mods->preci > 0)
//			newlen++;
		if (mods->flag[5] > 0 && mods->flag[4] == 0 && x[0] != '-')
			newlen++;
		printf("2dlen=%llu\n", newlen);
		if (mods->preci > len)
			newlen = newlen + (mods->preci - len);
		if (mods->flag[4] > 0 && x[0] != '-')
			newlen++;
		printf("3dlen=%llu\n", newlen);
		if (mods->flag[3] == 0 && mods->flag[2] == 0 && mods->width > mods->preci)
			width_n_c(mods, newlen, 'n'); //(mods->preci > len) ? len + (mods->preci - len) : len, 'n');
//		printf("%s\n", mods->store->buf);
		if (x[0] == '-')
			mods->store->buf[mods->i++] = *x++;
		else if (mods->flag[4] > 0)// && x[0] != '-') // only for signed #
			mods->store->buf[mods->i++] = '+';
		else if (mods->flag[5] > 0)// && mods->flag[4] == 0)// && x[0] != '-') // only for signed #
			mods->store->buf[mods->i++] = ' ';
//		if (*x == '-' && mods->flag[2] > 0)
//			mods->store->buf[mods->i++] = *x++;
//		if (mods->flag[3] == 0)
//			(len > mods->preci) ? width_n_c(mods, len, 'n') : width_n_c(\
//				mods, mods->preci, 'n');
		if (mods->flag[3] == 0 && mods->flag[2] > 0)
			width_n_c(mods, newlen, 'n');
//		printf("dlen=%llu\n", len);
		len =  preci(mods, len);
//		printf("dlen=%llu\n", len);
		if (*x == '-' && mods->flag[2] == 0)
			mods->store->buf[mods->i++] = *x++;
		while (*x) // && (mods->preci != 0) && i++ <= mods->preci)
			mods->store->buf[mods->i++] = *x++;
		if (mods->flag[3] > 0)
			width_n_c(mods, newlen, 'n');
}