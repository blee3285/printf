/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:17 by blee              #+#    #+#             */
/*   Updated: 2017/05/31 18:31:10 by blee             ###   ########.fr       */
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
	formats = (int*)malloc(sizeof(int) * 9);
	ft_bzero(formats, 36);
	formats[9] = -1;
	output = NULL;
	while (*str)
	{
		if (*str == '%' && (len = format_checker(str + 1, &formats)))
		{
			str += len;
			while (i < 9)
			{
				ft_putnbr(formats[i]);
				ft_putchar(' ');
				i++;
			}
			if (formats[8])
			{
				output = type_to_str(one_char_str(formats[8]), ap);
				ft_putstr(output);
			}
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
