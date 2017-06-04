/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:05:09 by blee              #+#    #+#             */
/*   Updated: 2017/06/03 19:21:25 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		apply_flags(char **output, int *formats, int len)
{
	if (formats[3] && find_match(formats[8], "dDi"))
		zero_buffer(output, len);
	if (formats[2] && formats[3] && find_match(foramts[8], "dDi"))
		**output = ' ';
	if (formats[1] && formats[3] && find_match(formats[8], "dDi"))
		**output = '+';
	if (formats[0])
	{
		if (formats[1] || formats[2])
			len++;
		shift_left(output, len);
	}
	return (0);
}

char	*build_str(int	*formats, va_list ap)
{
	char	*output;
	int		len;

	output = type_to_str(formats[8], ap);
	len = ft_strlen(output);
	if (formats[6])
	{
		cut_str(&output, formats[6]);
		len = ft_strlen(output);
	}
	if (formats[5])
		add_width(&output, formats[5]);
	return (output);
}
