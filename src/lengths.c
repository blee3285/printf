/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:28:36 by blee              #+#    #+#             */
/*   Updated: 2017/06/08 18:35:33 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 1 = hh, 2 = ll */

char	*int_types(int *formats, va_list ap)
{
	char	*out;

	out = NULL;
	if (formats[7] == 'h')
		out = ft_itoa_base((short)va_arg(ap, int), 10, 0);
	else if (formats[7] == 1)
		out = ft_itoa_base((signed char)va_arg(ap, int), 10, 0);
	else if (formats[7] == 'l')
		out = ft_itoa_base(va_arg(ap, long), 10, 0);
	else if (formats[7] == 2)
		out = ft_itoa_base(va_arg(ap, long long), 10, 0);
	else if (formats[7] == 'j')
		out = ft_itoa_base(va_arg(ap, intmax_t), 10, 0);
	else if (formats[7] == 'z')
		out = ft_itoa_base(va_arg(ap, long), 10, 0);
	return (out);
}

int		set_sizes(int *formats, int *size, int *x)
{
	if (formats[8] == 'X')
		*x = 1;
	if (formats[8] == 'o' || formats[8] == 'O')
		*size = 8;
	else if (formats[8] == 'u')
		*size = 10;
	return (0);
}

char	*octal_hex_types(int *formats, va_list ap)
{
	char	*out;
	int		size;
	int		x;
	
	x = 0;
	size = 16;
	out = NULL;
	set_sizes(formats, &size, &x);
	if (formats[7] == 'h')
		out = ft_itoa_base_un((unsigned short)va_arg(ap, int), size, x);
	else if (formats[7] == 1)
		out = ft_itoa_base_un((unsigned char)va_arg(ap, int), size, x);
	else if (formats[7] == 'l')
		out = ft_itoa_base_un(va_arg(ap, unsigned long), size, x);
	else if (formats[7] == 2)
		out = ft_itoa_base_un(va_arg(ap, unsigned long long), size, x);
	else if (formats[7] == 'j')
		out = ft_itoa_base_un(va_arg(ap, uintmax_t), size, x);
	else if (formats[7] == 'z')
		out = ft_itoa_base_un(va_arg(ap, size_t), size, x);
	return (out);
}

char	*lengths_to_str(int *formats, va_list ap)
{
	char	*out;

	out = NULL;
	if (find_match(formats[8], "dDi"))
		out = int_types(formats, ap);
	else if (find_match(formats[8], "oOxXu"))
		out = octal_hex_types(formats, ap);
	return (out);
}
