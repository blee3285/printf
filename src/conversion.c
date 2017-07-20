/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:47 by blee              #+#    #+#             */
/*   Updated: 2017/07/19 19:58:44 by blee             ###   ########.fr       */
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
	if (c == 'S')
		out = wstr_to_str((wchar_t *)ptr);
	else if (c == 'c')
		out = one_char_str((int)ptr);
	else if (c == 'C')
		out = wchar_to_str((wchar_t)ptr);
	else if (c == 'd' || c == 'D' || c == 'i')
		out = ft_itoa_base((int)ptr, 10, 0);
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
	else if (c == 'u')
		out = ft_itoa_base_un((unsigned int)ptr, 10, 0);
	else if (c == 'U')
		out = ft_itoa_base_un((unsigned long)ptr, 10, 0);
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

char	*conversion(int **formats, va_list ap)
{
	char	*out;
	void	*ptr;
	int		*temp;

	temp = *formats;
	out = NULL;
	ptr = va_arg(ap, void *);
	if (ptr == NULL && temp[8] == 's')
		out = ft_strdup("(null)");
	else if (temp[7])
		out = lengths_to_str(formats, ptr);
	else if (find_match(temp[8], "sScCdDi%"))
		out = type_to_str1(temp[8], ptr);
	else if (find_match(temp[8], "oOxXuUp"))
		out = type_to_str2(temp[8], ptr);
	temp[9] = ft_strlen(out);
	if (temp[8] == 'c' && ptr == NULL)
		temp[9]++;
	if (temp[8] == 'C')
		temp[9] = 1;
	return (out);
}
