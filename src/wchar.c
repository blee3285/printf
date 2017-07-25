/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 15:23:28 by blee              #+#    #+#             */
/*   Updated: 2017/07/24 18:03:44 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*one_byte_str(wchar_t wc)
{
	char	*str;

	str = ft_strnew(1);
	*str = (unsigned char)wc;
	return (str);
}

char	*two_byte_str(wchar_t wc)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = (unsigned char)(wc >> 6);
	str[0] += 0xC0;
	str[1] = (unsigned char)(wc & 0x3F);
	str[1] += 0x80;
	return (str);
}

char	*three_byte_str(wchar_t wc)
{
	char	*str;

	str = ft_strnew(3);
	str[0] = (unsigned char)(wc >> 12);
	str[0] += 0xE0;
	str[1] = (unsigned char)(wc >> 6);
	str[1] = (str[1] & 0x3F) + 0x80;
	str[2] = (unsigned char)(wc & 0x3F);
	str[2] += 0x80;
	return (str);
}

char	*four_byte_str(wchar_t wc)
{
	char	*str;

	str = ft_strnew(4);
	str[0] = (unsigned char)(wc >> 18);
	str[0] += 0xF0;
	str[1] = (unsigned char)(wc >> 12);
	str[1] = (str[1] & 0x3F) + 0x80;
	str[2] = (unsigned char)(wc >> 6);
	str[2] = (str[2] & 0x3F) + 0x80;
	str[3] = (unsigned char)(wc & 0x3F);
	str[3] += 0x80;
	return (str);
}

char	*wchar_to_str(wchar_t wc)
{
	char	*out;

	if (!wc)
		return (ft_strdup(""));
	out = NULL;
	if ((wc <= 0x7F) || (MB_CUR_MAX == 1 && wc < 0xFF))
		out = one_byte_str(wc);
	else if (wc <= 0x7FF)
		out = two_byte_str(wc);
	else if (wc <= 0xFFFF)
		out = three_byte_str(wc);
	else if (wc <= 0x10FFFF)
		out = four_byte_str(wc);
	return (out);
}
