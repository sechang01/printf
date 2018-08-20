/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lettermatch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/18 18:06:40 by sechang           #+#    #+#             */
/*   Updated: 2018/08/19 17:28:08 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// c = iniitalize all to null;
// a = check first set (flags);
// b = check second set (modifiers);
t_flag 	flagnlen(t_flag *match, char c, char key)
{
//		t_flags 	match;
		int			i;

		if (key == 'c' && (i = 0)) // i = 0 is positive?
		{
			while (i < 9)
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
