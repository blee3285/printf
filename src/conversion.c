/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:47 by blee              #+#    #+#             */
/*   Updated: 2017/08/16 14:25:05 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	else if (c == 'd' || c == 'i')
		out = ft_itoa_base((int)ptr, 10, 0);
	else if (c == 'D')
		out = ft_itoa_base((long long)ptr, 10, 0);
	else if (c == '%')
		out = one_char_str('%');
	return (out);
}

char	*type_to_str2(char c, void *ptr)
{
	char	*out;

	out = NULL;
	if (c == 'o')
		out = ft_itoa_base_un((unsigned int)ptr, 8, 0);
	if (c == 'O')
		out = ft_itoa_base_un((unsigned long)ptr, 8, 0);
	else if (c == 'x')
		out = ft_itoa_base_un((unsigned int)ptr, 16, 0);
	else if (c == 'X')
		out = ft_itoa_base_un((unsigned int)ptr, 16, 1);
	else if (c == 'u')
		out = ft_itoa_base_un((unsigned int)ptr, 10, 0);
	else if (c == 'U')
		out = ft_itoa_base_un((unsigned long long)ptr, 10, 0);
	else if (c == 'p')
		out = ft_itoa_base_un((long long)ptr, 16, 0);
	return (out);
}

char	*one_char_str(char c)
{
	char	*str;

	str = ft_strnew(1);
	if (c == 0)
		str[0] = 127;
	else
		str[0] = c;
	return (str);
}

void	*get_ptr(int *formats, va_list ap)
{
	void	*ptr;

	if (formats[8] == '%')
		ptr = NULL;
	else
		ptr = va_arg(ap, void *);
	return (ptr);
}

char	*conversion(int **formats, va_list ap)
{
	char	*out;
	void	*ptr;
	int		*temp;

	temp = *formats;
	out = NULL;
	ptr = get_ptr(temp, ap);
	if (temp[8] == 'p')
		temp[4] = '#';
	if (ptr == NULL && (temp[8] == 's' || temp[8] == 'S'))
		out = ft_strdup("(null)");
	else if (temp[7] && find_match(temp[8], "dDioOxXuUcs"))
		out = lengths_to_str(formats, ptr);
	else if (find_match(temp[8], "sScCdDi%"))
		out = type_to_str1(temp[8], ptr);
	else if (find_match(temp[8], "oOxXuUp"))
		out = type_to_str2(temp[8], ptr);
	if (out == NULL)
		out = ft_strdup("");
	temp[9] = ft_strlen(out);
	if ((temp[8] == 'C') && ptr == NULL)
		temp[5]--;
	return (out);
}
