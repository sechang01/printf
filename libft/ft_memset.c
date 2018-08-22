/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 17:37:53 by sechang           #+#    #+#             */
/*   Updated: 2018/08/20 17:34:03 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptrb;
	size_t	counter;

	ptrb = b;
	counter = 0;
	while (counter < len)
		*(ptrb + counter++) = (unsigned char)c;
	return (b);
}
