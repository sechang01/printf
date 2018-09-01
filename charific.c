/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charific.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:38:34 by sechang           #+#    #+#             */
/*   Updated: 2018/08/31 21:10:48 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_c(t_flag *mods)
{
			unsigned char 	x;             // 4 bytes for unicode

//			printf("Entering printf.c\n");
//			width_n_c(mods, 1, 'a');
			if (mods->flag[10] != '%')
				x = (unsigned char)(va_arg(mods->vg, int));
			else
			{
//				initzero(mods);
				mods->preci = 0;
				//chrfmt(mods, 0, 'c');
				x = '%';
			}
			if (!x)
			{
				mods->preci = 1;
			}
			if (mods->flag[3] == 0)
			{
				width_n_c(mods, 1, 'n');
			}
			mods->store->buf[mods->i++] = x;
			if (mods->flag[3] > 0)
				width_n_c(mods, 1, 'n');

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
//		printf("Entering printf.s\n");
//		printf("matchflag3 = %d", mods->flag[3]);
		tmp = va_arg(mods->vg, char *);
		if (!tmp)
		{
			ft_strcpy(&(mods->store->buf[mods->i]), "(null)");
			mods->i = mods->i + 6;
			return ;
		}
//		printf("~~~~~~~ tmp = %s\n", tmp);
		if ((unsigned long)ft_strlen(tmp) == 0)
			len = 0;
		else
	//		len = (unsigned long)ft_strlen(tmp); 
			len = (mods->flag[0] > 0 && mods->preci < (unsigned long)\
				ft_strlen(tmp)) ? mods->preci : (unsigned long)ft_strlen(tmp);
		x = ft_strsub((char const*) tmp, 0, (size_t)len);
//		printf("~~~~~~~ X = %s\n", tmp);
//		printf("%lu\n", len);
		if (mods->flag[3] == 0)
			width_n_c(mods, len, 'c');
//		if (mods->preci > 0)
//			x[mods->preci + 1] = '\0';
		while (*x)
		{
			mods->store->buf[mods->i++] = *x++;
		}
		if (mods->flag[3] > 0)
			width_n_c(mods, len, 'c');
//		printf("printout:%s\n", mods->store->buf);
}

void		printf_big_s(t_flag *mods)
{
			wchar_t 	*x;             // 4 bytes for unicode
//			int		*i;

//			printf("Entering printf.c\n");
			width_n_c(mods, 1, 'n');

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
