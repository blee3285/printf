/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:05:09 by blee              #+#    #+#             */
/*   Updated: 2017/06/17 22:39:06 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numeric_flags(char **output, int *formats, int *len, int neg)
{
	int		total_len;
	char	c;

	c = 0;
	if (formats[1] && find_match(formats[8], "dDiu"))
		c = '+';
	else if (formats[2] && find_match(formats[8], "dDiu"))
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

int		alt_flag(char **output, int *formats, int len)
{
	if (formats[3] && ((formats[5] - len) > 1))
		add_alt_with_zero(output, formats[8]);
	else if (((formats[5] - len) > 1) ||
			((formats[5] > len) && (find_match(formats[8], "oO"))))
		add_alt_with_buffer(output, len, formats);
	else
		add_alt(output, formats[8]);
	return (0);
}

int		apply_flags(char **output, int *formats, int *len)
{
	int		neg;
	int		buffer;

	neg = 0;
	buffer = ft_strlen(*output) - *len;
	if (find_match(formats[8], "dDioOxXu"))
	{
		if (ft_atoi(*output) < 0)
			neg = 1;
		numeric_flags(output, formats, len, neg);
	}
	if (formats[4] && find_match(formats[8], "oOxX") && )
	{
		alt_flag(output, formats, *len);
	}
	if (formats[0] && ((size_t)*len < ft_strlen(*output)))
		shift_left(output, *len);
	return (0);
}

char	*build_str(int	*formats, va_list ap)
{
	char	*output;
	int		len;

	output = NULL;
	if (formats[7])
		output = lengths_to_str(formats, ap);
	else
		output = type_to_str(formats[8], ap);
	len = ft_strlen(output);
	if (formats[6] && find_match(formats[8], "sS"))
	{
		cut_str(&output, formats[6]);
		len = ft_strlen(output);
	}
	if (formats[5])
		add_width(&output, formats[5]);
	apply_flags(&output, formats, &len);
	return (output);
}
