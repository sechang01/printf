/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octdechex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:07:47 by sechang           #+#    #+#             */
/*   Updated: 2018/08/31 19:44:04 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// decimal
void		printf_u(t_flag *mods)
{
		char	*x;
		unsigned long	len;
		unsigned long 	newlen;

		x = NULL;
		if (mods->flag[10] == 'U')
			x = itoabase(va_arg(mods->vg,unsigned long long), 10, 'a');
		else if (mods->flag[11] == 1)
			x = ouxx(mods, 10, 'a');
		else if (mods->flag[10] == 'u')
			x = itoabase(va_arg(mods->vg, unsigned int), 10, 'a');
		len = (unsigned long)ft_strlen(x);

		if (len == 1 && x[0] == '0' && mods->flag[11] == 0 && mods->flag[4] == 0 && mods->preci == 0 && mods->flag[1] == 0)
		{
			if (mods->width == 0 && mods->preci == 0 && mods->flag[0] > 0 && mods->flag[1] == 0)
				return ;
			else if (mods->width > 0 && mods->preci == 0 && mods->flag[0] > 0)
				x[0] = ' ';
		}

		newlen = len;
		if (mods->preci > len)
			newlen = newlen + (mods->preci - len);
		if (mods->flag[3] == 0)
			width_n_c(mods, newlen, 'n');
		len = preci(mods, len);
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



		if (len == 1 && x[0] == '0' && mods->flag[11] == 0 && mods->flag[4] == 0 && mods->preci == 0 && mods->flag[1] == 0)
		{
			if (mods->width == 0 && mods->preci == 0 && mods->flag[0] > 0 && mods->flag[1] == 0)
				return ;
			else if (mods->width > 0 && mods->preci == 0 && mods->flag[0] > 0)
				x[0] = ' ';
		}


		if (mods->flag[1] > 0 && x[0] != '0')
			len++;
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
		unsigned long 	newlen;

		if (mods->flag[11] == 1 || mods->flag[10] == 'p')
			x = ouxx(mods, 16, (mods->flag[10] == 'x' || mods->flag[10] ==\
				'p') ? 'a' : 'A');
		else
			x = itoabase((unsigned long long)va_arg(mods->vg, unsigned int), \
				16, mods->flag[10] == 'x' || mods->flag[10] == 'p' ? 'a' : 'A');
		len = (unsigned long long)ft_strlen(x);
		
		if (len == 1 && x[0] == '0' && mods->flag[11] == 0 && mods->flag[4] == 0 && mods->preci == 0)
		{
			if (mods->width == 0 && mods->preci == 0 && mods->flag[0] > 0)
				return ;
			else if (mods->width > 0 && mods->preci == 0 && mods->flag[0] > 0)
				x[0] = ' ';
		}
		newlen = len;
		if ((mods->flag[1] > 0 && x[0] != '0') || mods->flag[10] == 'p')
			newlen = newlen + 2;
		if (mods->preci > len)
			newlen = newlen + (mods->preci - len);
		if (mods->flag[3] == 0 && mods->flag[2] == 0)
			width_n_c(mods, newlen, 'a');
		if ((mods->flag[1] > 0 && x[0] != '0') || mods->flag[10] == 'p')
		{
			mods->store->buf[mods->i++] = '0';
			if (mods->flag[10] == 'X')
				mods->store->buf[mods->i++] = 'X';
			else if (mods->flag[10] == 'x' || mods->flag[10] == 'p')
				mods->store->buf[mods->i++] = 'x';
		}
		if (mods->flag[3] == 0 && mods->flag[2] > 0)
			width_n_c(mods, newlen, 'a');
		len = preci(mods, len);
		while (*x)
			mods->store->buf[mods->i++] = *x++;
		if (mods->flag[3] > 0)
			width_n_c(mods, newlen, 'a');
}

