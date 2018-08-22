/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numeric.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 18:02:51 by sechang           #+#    #+#             */
/*   Updated: 2018/08/21 19:13:01 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_d(t_flag *mods)
{
		char	*x;
		unsigned long	len;

		x = ft_itoa(va_arg(mods->vg, int));
		len = (unsigned long)ft_strlen(x);
//		len = (unsigned long)ft_get_intlen(x);
//		x = ft_itoa(x);
		while (*x)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
}
/*
void		printf_u(t_flag *mods)
{
		char	*x;
		unsigned long	len;

		x = ft_itoabase(va_arg(mods->vg, unsigned int), 10);
		len = (unsigned long)ft_strlen(x);
//		len = (unsigned long)ft_get_intlen(x);
//		x = ft_itoa(x);
		while (*x)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
}

void		printf_x(t_flag *mods)
{
		char	*x;
		unsigned long	len;

		x = ft_itoabase(va_arg(mods->vg, unsigned int), 8);
		len = (unsigned long)ft_strlen(x);
//		len = (unsigned long)ft_get_intlen(x);
//		x = ft_itoa(x);
		while (*x)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
}
*/