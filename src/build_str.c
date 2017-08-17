/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:05:09 by blee              #+#    #+#             */
/*   Updated: 2017/08/16 14:06:12 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		numeric_flags(char **out, int **form, int *len, int neg)
{
	int		*temp;
	char	c;

	temp = *form;
	c = 0;
	if (temp[1])
		c = '+';
	else if (temp[2])
		c = ' ';
	if (temp[3] && temp[0] == 0 && !temp[6])
		zero_buffer(out, *len, neg);
	if ((temp[2] || temp[1]) && !neg && find_match(temp[8], "dDi"))
	{
		if (temp[3] && (*len < temp[9]))
			**out = c;
		else if (*len < temp[9])
			add_char_with_buffer(out, *len, c);
		else
		{
			add_char(out, *len, c);
			temp[9]++;
		}
		*len += 1;
	}
	return (0);
}

int		alt_flag(char **output, int **formats, int *len)
{
	int		buffer;
	char	*temp;
	int		*form;
	int		i;

	temp = *output;
	form = *formats;
	buffer = form[9] - *len;
	temp += buffer;
	if (*len == 1 && *temp == '0' && form[8] != 'p')
		return (0);
	if (form[3] && form[0] == 0)
		*len += add_alt_with_zero(output, form);
	else if ((buffer > 1) ||
			((buffer > *len) && (find_match(form[8], "oO"))))
		*len += add_alt_with_buffer(output, form, buffer);
	else
	{
		i = add_alt(output, form, buffer);
		*len += i;
		form[9] += i - buffer;
	}
	return (0);
}

int		apply_flags(char **output, int **formats, int *len)
{
	int		neg;
	int		*temp;

	neg = 0;
	temp = *formats;
	if (ft_atoi(*output) < 0 && find_match(temp[8], "dDi"))
		neg = 1;
	numeric_flags(output, formats, len, neg);
	if (temp[4] && find_match(temp[8], "oOxXp"))
		alt_flag(output, formats, len);
	if (temp[0] && (*len < temp[9]))
		shift_left(output, *len);
	return (0);
}

char	*build_str(int **formats, va_list ap)
{
	char	*output;
	int		len;
	int		*temp;

	output = NULL;
	temp = *formats;
	output = conversion(formats, ap);
	if (!temp[8] && temp[5])
		temp[5]--;
	len = temp[9];
	if (temp[6] || temp[6] == -1)
		temp[9] = precision(&output, formats, &len);
	if (formats[5])
		temp[9] = add_width(&output, formats, len);
	apply_flags(&output, formats, &len);
	return (output);
}
