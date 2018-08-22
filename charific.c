/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charific.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:38:34 by sechang           #+#    #+#             */
/*   Updated: 2018/08/20 22:00:53 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_c(t_flag *mods)
{
			char 	x;
			unsigned long		len;
			
			printf("Entering printf.c\n");
			width_a_b(mods, 1, 'a');
			x = va_arg(mods->vg, int);
			mods->store->buf[mods->i] = x;
//			if (mods->width > 1)
//				mods->pbuf = x;
				
//			left aligned or right aligned?
//			print width of ( ) - 1. 
//			print char

//			move pointer width spaces
//			return ;
}
void		printf_s(t_flag *mods)
{
		char			*x;
		unsigned long	len;

		printf("Entering printf.s\n");

		len = ft_strlen(x);
		width_a_b(mods, len, 'a'); //flag[ - ]
		x = va_arg(mods->vg, char *);
		while (*x)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}

}
