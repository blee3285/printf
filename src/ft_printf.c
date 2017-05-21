/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:17 by blee              #+#    #+#             */
/*   Updated: 2017/05/20 16:48:58 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_format(char *str, va_list ap)
{
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			format_checker(str, ap);
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
