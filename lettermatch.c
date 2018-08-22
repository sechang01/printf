/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lettermatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:06:40 by sechang           #+#    #+#             */
/*   Updated: 2018/08/20 18:19:07 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		initzero(t_flag *mods)
{
	mods->width = 0;
	mods->preci = 0;
	mods->space = 0;
}

// c = iniitalize all to null;
// a = check first set (flags);
// b = check second set (modifiers);
t_flag chrfmt(t_flag *match, char c, char key)
{
//	10 chars 0 - 9
		int			i;

		if (key == 'c' && (i = 0)) // i = 0 is positive?
		{
			while (i <= 10)
				match->flag[i++] = '\0';
		}
		if (key == 'a')
		{
			match->flag[0] = (c == '%') ? match->flag[0] + 1 : match->flag[0];
			match->flag[1] = (c == '#') ? match->flag[1] + 1 : match->flag[1];
			match->flag[2] = (c == '0') ? match->flag[2] + 1 : match->flag[2];
			match->flag[3] = (c == '-') ? match->flag[3] + 1 : match->flag[3];
			match->flag[4] = (c == '+') ? match->flag[4] + 1 : match->flag[4];
			match->flag[5] = (c == ' ') ? match->flag[5] + 1 : match->flag[5]; //wat char?
		}
		else if (key == 'b')
		{
			match->flag[6] = (c == 'h') ? match->flag[6] + 1 : match->flag[6];
			match->flag[7] = (c == 'l') ? match->flag[7] + 1 : match->flag[7];
			match->flag[8] = (c == 'j') ? match->flag[8] + 1 : match->flag[8];
			match->flag[9] = (c == 'z') ? match->flag[9] + 1 : match->flag[9];
		}
		return (*match);//  ???
}

int		flag_found(char c)
{
	return (c == '%' || c == '#' || c == '0' || c == '-' || c == '+' || c == ' ');
}

int		len_found(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

int		fmt_found(char c)
{
	return (c == 's' || c == 'S' || c == 'p' || c == 'D' || c == 'i' \
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' \
			|| c == 'X' || c == 'c' || c == 'C');
}
/*
t_flag (t_flag *mtch, char c, char key)
{
//		10 - 22, 13 chars, + null;
		int			i;

		if (key == 'c' && (i = 10)) // i = 0 is positive?
		{
			while (i <= 23)
				mtch->flag[i++] = '\0';
		}
		if (key == 'a')
		{
			mtch->varg = (c == 's') ? va_arg(vg, char *) : g[10];
			mtch->flag[11] = (c == 'S') ? mtch->flag[11] + 1 : mtch->flag[11];
			mtch->flag[12] = (c == 'p') ? mtch->flag[12] + 1 : mtch->flag[12];
			mtch->flag[13] = (c == 'D') ? mtch->flag[13] + 1 : mtch->flag[13];
			mtch->flag[14] = (c == 'i') ? mtch->flag[14] + 1 : mtch->flag[14];
			mtch->flag[15] = (c == 'o') ? mtch->flag[15] + 1 : mtch->flag[15];
			mtch->flag[16] = (c == 'O') ? mtch->flag[16] + 1 : mtch->flag[16];
			mtch->flag[17] = (c == 'u') ? mtch->flag[17] + 1 : mtch->flag[17];
			mtch->flag[18] = (c == 'U') ? mtch->flag[18] + 1 : mtch->flag[18];
			mtch->flag[19] = (c == 'x') ? mtch->flag[19] + 1 : mtch->flag[19];
			mtch->flag[20] = (c == 'X') ? mtch->flag[20] + 1 : mtch->flag[20];
			mtch->flag[21] = (c == 'c') ? mtch->flag[21] + 1 : mtch->flag[21];
			mtch->flag[22] = (c == 'C') ? mtch->flag[22] + 1 : mtch->flag[22];
		}
		return (*mtch);
}
*/
