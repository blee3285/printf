/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:17 by blee              #+#    #+#             */
/*   Updated: 2017/05/19 12:23:27 by blee             ###   ########.fr       */
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
		}
		else
			ft_putchar(*str);
		str++;
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	va_end(ap);

	return (0);
}
