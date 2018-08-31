/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sechang <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 20:07:35 by sechang           #+#    #+#             */
/*   Updated: 2018/08/28 21:48:51 by sechang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		n_cpy;
	size_t	len;

	if (n == -2147483648)
		return (ft_strcpy((char *)malloc(sizeof(char) * 11), "-2147483648"));
	i = 0;
	n_cpy = n;
	len = ft_get_intlen(n);
	if (n < 0)
	{
		n_cpy = -n;
		len++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = '\0';
	str[--len] = n_cpy % 10 + '0';
	while (n_cpy /= 10)
		str[--len] = n_cpy % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
