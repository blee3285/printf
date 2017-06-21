/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 12:10:52 by blee              #+#    #+#             */
/*   Updated: 2017/06/20 19:44:57 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		cut_str(char **str, int max, int len)
{
	char	*temp;

	temp = *str;
	if (len > max)
	{
		temp += max;
		ft_strclr(temp);
		return (max);
	}
	return (len);
}

int		precision_num(char **str, int *formats, int *len)
{
	char	*new;
	char	*temp;
	int		buff;

	if (**str == '-')
		formats[6]++;
	buff = formats[6] - *len;
	if (formats[6] <= *len)
		return (*len);
	new = ft_strnew(formats[6] + 1);
	temp = new;
	ft_memset(temp, '0', buff);
	temp += buff;
	ft_strcpy(temp, *str);
	if (**str == '-')
	{
		*new = '-';
		*temp = '0';
	}
	free(*str);
	*str = new;
	return (formats[6]);
}

int		precision(char **str, int *formats, int *len)
{
	if (find_match(formats[8], "sS"))
		*len = cut_str(str, formats[6], *len);
	else if (find_match(formats[8], "dDiuUoOxX"))
		*len = precision_num(str, formats, len);
	return (0);
}
