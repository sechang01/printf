/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charific.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:38:34 by sechang           #+#    #+#             */
/*   Updated: 2018/08/27 23:53:52 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_c(t_flag *mods)
{
			unsigned char 	x;             // 4 bytes for unicode

//			printf("Entering printf.c\n");
			width_n_c(mods, 1, 'a');

			x = (unsigned char)(va_arg(mods->vg, int));
//			if (mods->flag[10] == 'S')
//				mods->store->buf[mods->i++] = x;

			mods->store->buf[mods->i++] = x;
//			printf("printout:%s\n", mods->store->buf);
}

void		printf_s(t_flag *mods)
{
		char			*x;
		char			*tmp;
		unsigned long	len;
		unsigned long	i;

		i = 0;
		x = NULL;
		printf("Entering printf.s\n");
//		printf("matchflag3 = %d", mods->flag[3]);
		tmp = va_arg(mods->vg, char *);
//		printf("~~~~~~~ tmp = %s\n", tmp);
		len = ((unsigned long)ft_strlen(tmp) > mods->preci) ? mods->preci : \
			  ft_strlen(tmp);
//		printf("--- len = %ld\n", len);
		x = ft_strsub((char const*) tmp, 0, (size_t)len);
//		printf("~~~~~~~ X = %s\n", tmp);
		if (mods->flag[3] == 0)
			width_n_c(mods, len, 'n');
//		if (mods->flag[4] > 0) // only for signed #
//			mods->store->buf[mods->i++] = '+';
//		if (mods->flag[5] > 0 && mods->flag[4] == 0) // only for signed #
//			mods->store->buf[mods->i++] = ' ';
		while (*x)// && i++ < mods->preci) //&& ((mods->preci)) && i++ <= mods->preci)
		{
			mods->store->buf[mods->i++] = *x;
			x++;
		}
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'n');
//		printf("printout:%s\n", mods->store->buf);
}

void		printf_big_s(t_flag *mods)
{
			wchar_t 	*x;             // 4 bytes for unicode
//			int		*i;

//			printf("Entering printf.c\n");
			width_n_c(mods, 1, 'a');

			x = (va_arg(mods->vg, wchar_t *));
			
//			if (mods->flag[10] == 'C')
//				mods->store->buf[mods->i++] = x;
			while (*x)
			{
				mods->store->buf[mods->i++] = *x;
				x++;
			}
//			mods->store->buf[mods->i++] = *x;
//			printf("printout:%s\n", mods->store->buf);
}
