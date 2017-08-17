/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:19:11 by blee              #+#    #+#             */
/*   Updated: 2017/08/16 14:05:55 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check1(char *str, int **formats, va_list ap)
{
	int		total;
	int		len;

	total = 0;
	if ((len = check_flags(str, formats)))
	{
		total += len;
		str += len;
	}
	if ((len = check_width(str, formats, ap)))
	{
		total += len;
		str += len;
	}
	if ((len = check_precision(str, formats, ap)))
		total += len + 1;
	else if (*str == '.')
		total++;
	return (total);
}

int		check2(char *str, int **formats)
{
	int		total;
	int		len;

	total = 0;
	if ((len = check_length(str, formats)))
	{
		total += len;
		str += len;
	}
	if ((len = check_type(str, formats)))
		total += len;
	return (total);
}

int		format_checker(char *str, int **formats, va_list ap)
{
	int		total;
	int		len;
	int		*temp;
	int		i;

	i = 0;
	total = 0;
	temp = *formats;
	len = check1(str, formats, ap);
	total += len;
	str += len;
	len = check2(str, formats);
	total += len;
	str += len;
	return (total);
}
