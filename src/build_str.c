/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/02 14:05:09 by blee              #+#    #+#             */
/*   Updated: 2017/06/03 01:33:29 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*build_str(int	*formats, va_list ap)
{
	char	*output;

	output = type_to_str(formats[8], ap);
	if (formats[6])
		cut_str(&output, formats[6]);
	if (formats[5])
		add_width(&output, formats[5]);
	return (output);
}
