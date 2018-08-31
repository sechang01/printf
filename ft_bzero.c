/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 13:23:53 by sechang           #+#    #+#             */
/*   Updated: 2018/08/28 20:26:58 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptrs;
	size_t	counter;

	ptrs = s;
	counter = 0;
	while (counter < n)
		*(ptrs + counter++) = 0;
}
