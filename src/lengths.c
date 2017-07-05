/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:28:36 by blee              #+#    #+#             */
/*   Updated: 2017/06/30 18:02:23 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 1 = hh, 2 = ll */

char	*int_types(int *formats, void *ptr)
{
	char	*out;

	out = NULL;
	if (formats[7] == 'h')
		out = ft_itoa_base((short)ptr, 10, 0);
	else if (formats[7] == 1)
		out = ft_itoa_base((signed char)ptr, 10, 0);
	else if (formats[7] == 'l')
		out = ft_itoa_base((long)ptr, 10, 0);
	else if (formats[7] == 2)
		out = ft_itoa_base((long long)ptr, 10, 0);
	else if (formats[7] == 'j')
		out = ft_itoa_base((intmax_t)ptr, 10, 0);
	else if (formats[7] == 'z')
		out = ft_itoa_base((long)ptr, 10, 0);
	return (out);
}

int		set_sizes(int *formats, int *size, int *x)
{
	if (formats[8] == 'X')
		*x = 1;
	if (formats[8] == 'o' || formats[8] == 'O')
		*size = 8;
	else if (formats[8] == 'u' || formats[8] == 'U')
		*size = 10;
	return (0);
}

char	*octal_hex_types(int *formats, void *ptr)
{
	char	*out;
	int		size;
	int		x;
	
	x = 0;
	size = 16;
	out = NULL;
	set_sizes(formats, &size, &x);
	if (formats[7] == 'h' && formats[8] == 'U')
		out = ft_itoa_base_un((unsigned long)ptr, size, x);
	else if (formats[7] == 'h')
		out = ft_itoa_base_un((unsigned short)ptr, size, x);
	else if (formats[7] == 1)
		out = ft_itoa_base_un((unsigned char)ptr, size, x);
	else if (formats[7] == 'l')
		out = ft_itoa_base_un((unsigned long)ptr, size, x);
	else if (formats[7] == 2)
		out = ft_itoa_base_un((unsigned long long)ptr, size, x);
	else if (formats[7] == 'j')
		out = ft_itoa_base_un((uintmax_t)ptr, size, x);
	else if (formats[7] == 'z')
		out = ft_itoa_base_un((size_t)ptr, size, x);
	return (out);
}

char	*lengths_to_str(int *formats, va_list ap)
{
	char	*out;
	void	*ptr;

	out = NULL;
	ptr = va_arg(ap, void *);
	if (find_match(formats[8], "dDi"))
		out = int_types(formats, ptr);
	else if (find_match(formats[8], "oOxXuU"))
		out = octal_hex_types(formats, ptr);
	return (out);
}
