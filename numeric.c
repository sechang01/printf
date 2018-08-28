/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:02:51 by sechang           #+#    #+#             */
/*   Updated: 2018/08/27 21:05:14 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_d(t_flag *mods)
{
		char	*x;
		unsigned long long		len;
		unsigned long long		i;

		i = 0;
		x = (mods->flag[10] == 'D') ? ft_itoa(va_arg(mods->vg, unsigned int)) : \
			numx(mods); //ft_itoa(va_arg(mods->vg, int));
		len = (unsigned long long)ft_strlen(x);
		if (mods->flag[3] == 0)
			width_n_c(mods, len, 'n');
		if (mods->flag[4] > 0) // only for signed #
			mods->store->buf[mods->i++] = '+';
		if (mods->flag[5] > 0 && mods->flag[4] == 0) // only for signed #
			mods->store->buf[mods->i++] = ' ';
		while (*x) // && (mods->preci != 0) && i++ <= mods->preci)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'n');
}