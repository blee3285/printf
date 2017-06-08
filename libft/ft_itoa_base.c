/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 17:06:49 by blee              #+#    #+#             */
/*   Updated: 2017/06/07 17:02:59 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*build_str(long long value, int base, int len, int cap)
{
	char	*num;
	char	*str;

	if (cap == 1)
		num = ft_strdup("0123456789ABCDEF");
	else
		num = ft_strdup("0123456789abcdef");
	str = ft_strnew(len + 1);
	str[len] = '\0';
	while (value && (len > -1))
	{
		len--;
		str[len] = num[value % base];
		value /= base;
	}
	if (len != 0)
		str[0] = '-';
	free(num);
	return (str);
}

char		*ft_itoa_base(long long value, int base, int cap)
{
	long long	num;
	char		*str;
	int			len;

	num = value;
	if (base != 10 && (value < 0))
		num *= -1;
	if (base < 2 || base > 16)
		return (ft_strdup("Error"));
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_numlen(num, base);
	if (num < 0)
		num *= -1;
	str = build_str(num, base, len, cap);
	return (str);
}

static char	*build_str_un(unsigned long long value, int base, int len, int cap)
{
	char	*num;
	char	*str;

	if (cap == 1)
		num = ft_strdup("0123456789ABCDEF");
	else
		num = ft_strdup("0123456789abcdef");
	str = ft_strnew(len + 1);
	str[len] = '\0';
	while (value > 0)
	{
		len--;
		str[len] = num[value % base];
		value /= base;
	}
	if (len != 0)
		str[0] = '-';
	free(num);
	return (str);
}

char		*ft_itoa_base_un(unsigned long long value, int base, int cap)
{
	unsigned long long	num;
	char				*str;
	int					len;

	num = value;
	if (base < 2 || base > 16)
		return (ft_strdup("Error"));
	if (num == 0)
		return (ft_strdup("0"));
	len = ft_numlen_un(num, base);
	str = build_str_un(num, base, len, cap);
	return (str);
}
