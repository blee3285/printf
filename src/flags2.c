/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 15:51:24 by blee              #+#    #+#             */
/*   Updated: 2017/06/12 18:34:40 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	add_alt_with_zero(char **str, char c)
{
	char	*temp;

	temp = *str;
	if (c == 'x')
		temp[1] = 'x';
	else if (c == 'X')
		temp[1] = 'X';
	return (0);
}

int	add_alt_with_buffer(char **str, int len, int *formats)
{
	char	*temp;
	int		buffer;

	buffer = formats[5] - len;
	temp = *str;
	if (formats[8] == 'o' || formats[8] == 'O')
	{
		temp += buffer - 1;
		*temp = '0';
	}
	else if (formats[8] == 'x' || formats[8] == 'X')
	{
		temp += buffer - 2;
		temp[0] = '0';
		temp[1] = formats[8];
	}
	return (0);
}
