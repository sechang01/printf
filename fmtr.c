/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmtr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 17:39:49 by sechang           #+#    #+#             */
/*   Updated: 2018/08/21 19:07:05 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// flags
int		fmtr(t_flag *mods)
{
//	(mods->flag[3] > 0) ? 1 : 1 ;
//	mods->width;
	return 0; 
}


int		width_a_b(t_flag *mods, unsigned long len, char key)
{
	printf("Entered W_a_b\n");
	printf("Width= %lu\n", mods->width);
	printf("Preci= %lu\n", mods->preci);
	mods->space = ' ';
	//a for left aligned
	//b for right aligned
	while (mods->width > len++)
		mods->store->buf[mods->i++] = mods->space;
	return 0;
}
