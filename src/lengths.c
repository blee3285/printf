/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lengths.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:28:36 by blee              #+#    #+#             */
/*   Updated: 2017/06/07 19:26:42 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* 1 = h, 2 = hh, 3 = l, 4 = ll, 5 = j, 6 = z */

char	*lengths(int *formats, va_list ap)
{
	char	*out;
	char	*temp;

	out = NULL;
	temp = NULL;
	if (find_match(formats[8], "dDi"))
	{
		if (formats[7] == 1)
		if (formats[7] == 2)
		if (foramts[7] == 3)
		if (formats[7] == 4)
		if (formats[7] == 5)
		if (formats[7] == 6)
	}
}
