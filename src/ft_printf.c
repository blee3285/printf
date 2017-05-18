/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:17 by blee              #+#    #+#             */
/*   Updated: 2017/05/17 20:34:24 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			ft_putstr(va_arg(ap, char*));
			str++;
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);

	return (0);
}
