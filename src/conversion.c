/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:47 by blee              #+#    #+#             */
/*   Updated: 2017/06/27 19:05:59 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Need new functions
	if (c == 'S') wide char

	optional
	eE - floats in exponent notation
	fF - floats
	gG - double
	aA - double  in hex
	n - num of char into a int pointer?
*/

char	*type_to_str1(char c, void *ptr)
{
	char	*out;

	out = NULL;
	if (c == 's')
		out = ft_strdup((char *)ptr);
	else if (c == 'c' || c == 'C')
		out = one_char_str((int)ptr);
	else if (c == 'd' || c == 'D' || c == 'i')
		out = ft_itoa((int)ptr);
	else if (c == '%')
		out = one_char_str('%');
	return (out);
}

char	*type_to_str2(char c, void *ptr)
{
	char	*out;
	char	*temp;

	out = NULL;
	temp = NULL;
	if (c == 'o' || c == 'O')
		out = ft_itoa_base_un((unsigned int)ptr, 8, 0);
	else if (c == 'x')
		out = ft_itoa_base_un((unsigned int)ptr, 16, 0);
	else if (c == 'X')
		out = ft_itoa_base_un((unsigned int)ptr, 16, 1);
	else if (c == 'u' || c == 'U')
		out = ft_itoa_base_un((unsigned int)ptr, 10 ,0);
	else if (c == 'p')
	{
		temp = ft_itoa_base_un((long long)ptr, 16, 0);
		out = ft_strjoin("0x", temp);
		free(temp);
	}
	return (out);
}

char	*one_char_str(char c)
{
	char	*str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}

char	*conversion(int	*formats, va_list ap)
{
	char	*out;
	void	*ptr;

	out = NULL;
	ptr = va_arg(ap, void *);
	if (ptr == NULL && formats[8] == 's')
		return (ft_strdup("(null)"));
	if (find_match(formats[8], "scCdDi%"))
		out = type_to_str1(formats[8], ptr);
	else if (find_match(formats[8], "oOxXuUp"))
		out = type_to_str2(formats[8], ptr);
	return (out);
}
