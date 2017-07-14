/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:05:09 by blee              #+#    #+#             */
/*   Updated: 2017/07/13 18:28:17 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numeric_flags(char **out, int *form, int *len, int neg)
{
	int		total_len;
	char	c;

	c = 0;
	if (form[1] && find_match(form[8], "dDi"))
		c = '+';
	else if (form[2] && find_match(form[8], "dDi"))
		c = ' ';
	total_len = ft_strlen(*out);
	if (form[3] && form[0] == 0 && (*len > form[6]))
		zero_buffer(out, *len, neg);
	if ((form[2] || form[1]) && !neg &&
			find_match(form[8], "dDi"))
	{
		if (form[3] && (*len < total_len))
			**out = c;
		else if (*len < total_len)
			add_char_with_buffer(out, *len, c);
		else
			add_char(out, *len, c);
		*len += 1;
	}
	return (0);
}

int		alt_flag(char **output, int *formats, int *len)
{
	int		buffer;
	char	*temp;

	temp = *output;
	buffer = ft_strlen(*output) - *len;
	temp += buffer;
	if (*len == 1 && *temp == '0')
		return (0);
	if (formats[3] && formats[0] == 0)
		*len += add_alt_with_zero(output, formats);
	else if ((buffer > 1) ||
			((buffer > *len) && (find_match(formats[8], "oO"))))
		*len += add_alt_with_buffer(output, formats, buffer);
	else
		*len += add_alt(output, formats[8], buffer);
	return (0);
}

int		apply_flags(char **output, int *formats, int *len)
{
	int		neg;

	neg = 0;
	if (find_match(formats[8], "dDioOxXuU"))
	{
		if (ft_atoi(*output) < 0 && find_match(formats[8], "dDi"))
			neg = 1;
		numeric_flags(output, formats, len, neg);
	}
	if (formats[4] && find_match(formats[8], "oOxX"))
		alt_flag(output, formats, len);
	if (formats[0] && ((size_t)*len < ft_strlen(*output)))
		shift_left(output, *len);
	return (0);
}

char	*build_str(int *formats, va_list ap)
{
	char	*output;
	int		len;

	output = NULL;
	if (formats[7])
		output = lengths_to_str(formats, ap);
	else
		output = conversion(&formats, ap);
	if (!output)
		return (ft_strdup("(NULL)"));
	len = ft_strlen(output);
	if (formats[9])
		len = 1;
	if (formats[6] || formats[6] == -1)
		precision(&output, formats, &len);
	if (formats[5])
		add_width(&output, formats[5], len);
	apply_flags(&output, formats, &len);
	return (output);
}
