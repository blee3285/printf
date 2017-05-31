/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:17 by blee              #+#    #+#             */
/*   Updated: 2017/05/30 17:20:08 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_format(char *str, va_list ap)
{
	int		len;
	int		*formats;
	char	*output;
	int		i;

	len = 0;
	i = 0;
	formats = (int*)malloc(sizeof(int) * 6);
	formats[5] = -1;
	output = NULL;
	while (*str)
	{
		if (*str == '%' && (len = format_checker(str + 1, &formats)))
		{
			str += len;
			while (i < 5)
			{
				ft_putnbr(formats[i]);
				ft_putchar(' ');
				i++;
			}
			output = type_to_str("s", ap);
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
