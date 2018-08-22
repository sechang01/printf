/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:55:47 by sechang           #+#    #+#             */
/*   Updated: 2018/08/21 18:38:43 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

typedef struct		s_type
{
	char			fmt;
	void			(*f)(t_flag *x);
}					t_type;

static t_type	g_type[] = \
{
	{'c', &printf_c},
//	{'C', &printf_c},
	{'s', &printf_s},
//	{'S', &printf_cap_s},

//	{'p', &printf_p},
	{'d', &printf_d},
//	{'D', &printf_i_l},

	{'i', &printf_d},
//	{'o', &printf_o},
//	{'O', &printf_o_l},

	{'u', &printf_u},
//	{'U', &printf_u_l},
	{'x', &printf_x},
//	{'X', &printf_x},

//	{'%', &printf_percent},
//	{0, 0}

//	{'n', &printf_n},
//	{'m', &printf_m},
};

#endif