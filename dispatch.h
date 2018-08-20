/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 12:55:47 by sechang           #+#    #+#             */
/*   Updated: 2018/08/19 19:34:30 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPATCH_H
# define DISPATCH_H

typedef struct		s_inpt
{
	void			*inpt;
}					t_inpt;


typedef struct		s_type
{
	char			fmt;
	void			(*f)(t_inpt *);
}					t_type;

static t_type	g_type[] = \
{
	{'c', &printf_c},
//	{'C', &printf_c},
//	{'s', &printf_s},
//	{'S', &printf_cap_s},

//	{'p', &printf_p},
//	{'d', &printf_i},
//	{'D', &printf_i_l},

//	{'i', &printf_i},
//	{'o', &printf_o},
//	{'O', &printf_o_l},

//	{'u', &printf_u},
//	{'U', &printf_u_l},
//	{'x', &printf_x},
//	{'X', &printf_x},

//	{'%', &printf_percent},
//	{0, 0}

//	{'n', &printf_n},
//	{'m', &printf_m},
};

#endif