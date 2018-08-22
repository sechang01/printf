/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octdechex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 19:07:47 by sechang           #+#    #+#             */
/*   Updated: 2018/08/21 19:21:02 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// decimal
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

// octali 0o
void		printf_o(t_flag *mods)
{
		char	*x;
		unsigned long	len;

		mods->store->buf[mods->i++] = '0';
		mods->store->buf[mods->i++] = 'o';
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

// hexidecimal 0x
void		printf_x(t_flag *mods)
{
		char	*x;
		unsigned long	len;

		mods->store->buf[mods->i++] = '0';
		mods->store->buf[mods->i++] = 'x';
		x = ft_itoabase(va_arg(mods->vg, unsigned int), 16);
		len = (unsigned long)ft_strlen(x);
//		len = (unsigned long)ft_get_intlen(x);
//		x = ft_itoa(x);
		while (*x)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
}		