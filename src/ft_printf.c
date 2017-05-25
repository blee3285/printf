/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:17 by blee              #+#    #+#             */
/*   Updated: 2017/05/24 15:18:20 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_format(char *str, va_list ap)
{
	int		len;
	char	*output;

	len = 0;
	output = NULL;
	while (*str)
	{
		if (*str == '%' && (len = format_checker(str + 1)))
		{
			str += len;
			output = type_to_str((str), ap);
			ft_putstr(output);
		}
		else
			ft_putchar(*str);
		str++;
	}
	return (0);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	check_format((char *)str, ap);
	va_end(ap);

	return (0);
}
