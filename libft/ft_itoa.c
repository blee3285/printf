/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:10:39 by blee              #+#    #+#             */
/*   Updated: 2017/06/05 17:32:44 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		neg;
	int		len;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = -n;
	len = ft_numlen(n, 10);
	if (n < 0)
		n = -n;
	if (!(str = ft_strnew(len + 1)))
		return (NULL);
	if (n == 0)
		str[0] = '0';
	len--;
	while (n > 0)
	{
		str[len] = (n % 10) + '0';
		len--;
		n /= 10;
	}
	if (neg)
		str[len] = '-';
	return (str);
}
