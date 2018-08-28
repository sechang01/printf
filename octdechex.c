/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octdechex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:07:47 by sechang           #+#    #+#             */
/*   Updated: 2018/08/27 21:05:12 by sechang          ###   ########.fr       */
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

		if (mods->flag[11] == 1)
			x = ouxx(mods, 10, 'a');
		else
			x = (mods->flag[10] == 'U') ? itoabase((unsigned long long)va_arg\
					(mods->vg,unsigned long), 10, 'a') : itoabase(\
						(unsigned int)va_arg(mods->vg, unsigned int), 10, 'a');
		len = (unsigned long)ft_strlen(x);
		if (mods->flag[3] == 0)
			width_n_c(mods, len, 'a');
		while (*x) // && ((mods->preci)) && i++ <= mods->preci)	
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'a');
}

// octali 0o
void		printf_o(t_flag *mods)
{
		char	*x;
		unsigned long	len;
		unsigned long	i;

		i = 0;
		if (mods->flag[1] > 0)
		{
			mods->store->buf[mods->i++] = '0';
			mods->store->buf[mods->i++] = 'o';
		}
		if (mods->flag[11] == 1)
			x = ouxx(mods, 8, 'a');
		else
			x = (mods->flag[10] == 'O') ? itoabase((unsigned long long)va_arg\
				(mods->vg, unsigned long), 8, 'a') : itoabase((unsigned \
					int)va_arg(mods->vg, unsigned int), 8, 'A');
		len = (unsigned long)ft_strlen(x);
		if (mods->flag[3] == 0)
			width_n_c(mods, len, 'a');
		while (*x) // && ((mods->preci)) && i++ <= mods->preci)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'a');
}

// hexidecimal 0x
void		printf_x(t_flag *mods)
{
		char	*x;
		unsigned long	len;
		unsigned long	i;

		i = 0;
		if (mods->flag[1] > 0)
		{
			mods->store->buf[mods->i++] = '0';
			mods->store->buf[mods->i++] = 'x';
		}
		if (mods->flag[11] == 1)
			x = ouxx(mods, 16, (mods->flag[10] == 'x' || mods->flag[10] == \
				'p') ? 'a' : 'A');
		else
			x = itoabase((unsigned long long)va_arg(mods->vg, unsigned long), \
				16, mods->flag[10] == 'x' || mods->flag[10] == 'p' ? 'a' : 'A');
		len = (unsigned long long)ft_strlen(x);
		if (mods->flag[3] == 0)
			width_n_c(mods, len, 'n');
		while (*x)// && ((mods->preci)) && i++ <= mods->preci)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'n');
}

