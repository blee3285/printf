/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:05:09 by blee              #+#    #+#             */
/*   Updated: 2017/06/05 16:16:43 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numeric_flags(char **output, int *formats, int *len, int neg)
{
	int		total_len;
	char	c;

	c = 0;
	if (formats[1])
		c = '+';
	else if (formats[2])
		c = ' ';
	total_len = ft_strlen(*output);
	if (formats[3] && formats[0] == 0)
		zero_buffer(output, *len, neg);
	if ((formats[2] || formats[1]) && (neg == 0))
	{
		if (formats[3] && (*len < total_len))
			**output = c;
		else if (*len < total_len)
			add_char_with_buffer(output, *len, c);
		else
			add_char(output, *len, c);
		*len += 1;
	}
	return (0);
}

int		apply_flags(char **output, int *formats, int *len)
{
	int		neg;

	neg = 0;
	if (find_match(formats[8], "dDi"))
	{
		if (ft_atoi(*output) < 0)
			neg = 1;
		numeric_flags(output, formats, len, neg);
	}
	if (formats[0] && ((size_t)*len < ft_strlen(*output)))
		shift_left(output, *len);
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
	apply_flags(&output, formats, &len);
	return (output);
}
