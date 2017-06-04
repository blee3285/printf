/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:47 by blee              #+#    #+#             */
/*   Updated: 2017/06/03 15:53:23 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*type_to_str(char c, va_list ap)
{
	char	*out;
	char	*temp;

	out = NULL;
	temp = NULL;
	if (c == 's')
		out = ft_strdup(va_arg(ap, char *));
	if (c == 'c' || c == 'C')
		out = one_char_str(va_arg(ap, int));
	if (c == 'd' || c == 'D' || c == 'i')
		out = ft_itoa(va_arg(ap, int));
	if (c == 'o' || c == 'O')
		out = ft_itoa_base(va_arg(ap, int), 8, 0);
	if (c == 'x')
		out = ft_itoa_base(va_arg(ap, int), 16, 0);
	if (c == 'X')
		out = ft_itoa_base(va_arg(ap, int), 16, 1);
	if (c == 'u' || c == 'U')
		out = ft_itoa_base(va_arg(ap, unsigned int), 10 ,0);
	if (c == 'p')
	{
		temp = ft_itoa_base(va_arg(ap, long long), 16, 0);
		out = ft_strjoin("0x", temp);
		free(temp);
	}
	if (c == '%')
		out = one_char_str('%');
	/* Need new functions
	if (c == 'S') wide char

	optional
	eE - floats in exponent notation
	fF - floats
	gG - double
	aA - double  in hex
	n - num of char into a int pointer?
	*/
	return (out);
}

char	*one_char_str(char c)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}
