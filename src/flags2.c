/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:51:24 by blee              #+#    #+#             */
/*   Updated: 2017/07/28 18:39:54 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_alt_with_zero(char **str, int *formats)
{
	char	*temp;
	char	c;

	c = formats[8];
	temp = *str;
	if (c == 'x' || c == 'p')
		temp[1] = 'x';
	else if (c == 'X')
		temp[1] = 'X';
	if (c == 'o' || c == 'O')
		return (1);
	return (2);
}

int	add_alt_with_buffer(char **str, int *formats, int buffer)
{
	char	*temp;

	temp = *str;
	if (formats[8] == 'o' || formats[8] == 'O')
	{
		temp += buffer - 1;
		*temp = '0';
		return (1);
	}
	else if (find_match(formats[8], "xXp"))
	{
		temp += buffer - 2;
		temp[0] = '0';
		if (formats[8] == 'X')
			temp[1] = 'X';
		else
			temp[1] = 'x';
		return (2);
	}
	return (0);
}
