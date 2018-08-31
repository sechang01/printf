/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octdechex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:07:47 by sechang           #+#    #+#             */
/*   Updated: 2018/08/30 17:11:42 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// decimal
void		printf_u(t_flag *mods)
{
		char	*x;
		unsigned long	len;
		unsigned long	i;

		i = 0;
		x = NULL;
		if (mods->flag[10] == 'U')
			x = itoabase(va_arg(mods->vg,unsigned long long), 10, 'a');
		else if (mods->flag[11] == 1)
			x = ouxx(mods, 10, 'a');
		else if (mods->flag[10] == 'u')
			x = itoabase(va_arg(mods->vg, unsigned int), 10, 'a');
		len = (unsigned long)ft_strlen(x);
		if (mods->flag[3] == 0)
			width_n_c(mods, len, 'n');
		while (*x) // && ((mods->preci)) && i++ <= mods->preci)	
			mods->store->buf[mods->i++] = *x++;
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'n');
}

// octali 0o
void		printf_o(t_flag *mods)
{
		char	*x;
		unsigned long	len;
		unsigned long	i;

		i = 0;

		if (mods->flag[11] == 1)
			x = ouxx(mods, 8, 'a');
		else
			x = (mods->flag[10] == 'O') ? itoabase((unsigned long long)va_arg\
				(mods->vg, unsigned long), 8, 'a') : itoabase((unsigned \
					int)va_arg(mods->vg, unsigned int), 8, 'A');
//		printf("~~~~~~tmp=%s\n", x);
		len = (unsigned long)ft_strlen(x);

		if (mods->flag[1] > 0 && x[0] != '0')
			len = len + 1;
		if (mods->flag[3] == 0)
			(len > mods->preci) ? width_n_c(mods, len, 'n') : width_n_c(\
				mods, mods->preci, 'n');
//		printf("olen=%lu\n", len);
		len = preci(mods, len);
//		printf("olen=%lu\n", len);
		if (mods->flag[1] > 0 && x[0] != '0')
		{
			mods->store->buf[mods->i++] = '0';
	//		mods->store->buf[mods->i++] = 'o';
		}
		while (*x) // && ((mods->preci)) && i++ <= mods->preci)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'n');
}

// hexidecimal 0x
void		printf_x(t_flag *mods)
{
		char	*x;
		unsigned long	len;
		unsigned long	i;

		i = 0;
		if (mods->flag[11] == 1)
			x = ouxx(mods, 16, (mods->flag[10] == 'x' || mods->flag[10] == \
				'p') ? 'a' : 'A');
		else
			x = itoabase((unsigned long long)va_arg(mods->vg, unsigned int), \
				16, mods->flag[10] == 'x' || mods->flag[10] == 'p' ? 'a' : 'A');
//		if (mods->flag[1] && mods->flag[0] && mods->preci == 0 && *x == '0')
//			return;
		len = (unsigned long long)ft_strlen(x);
		if (mods->flag[1] > 0 && x[0] != '0')
			len = len + 2;
		if (mods->flag[3] == 0 && mods->flag[2] == 0)
			width_n_c(mods, len, 'a');
		if (mods->flag[1] > 0 && x[0] != '0')
		{
			mods->store->buf[mods->i++] = '0';
			if (mods->flag[10] == 'X')
				mods->store->buf[mods->i++] = 'X';
			else if (mods->flag[10] == 'x')
				mods->store->buf[mods->i++] = 'x';
		}
		if (mods->flag[3] == 0 && mods->flag[2] > 0)
			width_n_c(mods, len, 'a');
		while (*x)// && ((mods->preci)) && i++ <= mods->preci)
		{
			mods->store->buf[mods->i++] = *x++;
		}
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'a');
}

