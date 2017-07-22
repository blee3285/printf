/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 14:26:03 by blee              #+#    #+#             */
/*   Updated: 2017/07/21 17:31:28 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		find_match(char c, char *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int		check_flags(char *str, int **formats)
{
	int		*temp;
	int		count;

	temp = *formats;
	count = 0;
	while (find_match(*str, "-+ 0#"))
	{
		if (*str == '-')
			temp[0] = *str;
		else if (*str == '+')
			temp[1] = *str;
		else if (*str == ' ')
			temp[2] = *str;
		else if (*str == '0')
			temp[3] = *str;
		else if (*str == '#')
			temp[4] = *str;
		str++;
		count++;
	}
	return (count);
}

int		check_width(char *str, int **formats, va_list ap)
{
	int		*temp;

	temp = *formats;
	if (ft_isdigit(*str))
	{
		temp[5] = ft_atoi(str);
		return (ft_numlen(temp[5], 10));
	}
	else if (*str == '*')
	{
		temp[5] = va_arg(ap, int);
		return (1);
	}
	return (0);
}

int		check_precision(char *str, int **formats, va_list ap)
{
	int		*temp;
	int		i;

	temp = *formats;
	i = 0;
	if (*str == '.')
	{
		str++;
		temp[6] = ft_atoi(str);
		if (*str == '*')
		{
			temp[6] = va_arg(ap, int);
			i++;
		}
		if (temp[6] == 0)
			temp[6] = -1;
		while (ft_isdigit(*str))
		{
			i++;
			str++;
		}
		return (i);
	}
	return (0);
}
