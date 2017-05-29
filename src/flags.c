/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:45:25 by blee              #+#    #+#             */
/*   Updated: 2017/05/29 00:32:44 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	shift_left(char **str)
{
	char	*temp;
	int	i;

	temp = *str;
	i = 0;
	if (*temp == ' ')
	{
		while (*temp == ' ')
			temp++;
		while (temp[i])
		{
			*str[i] = temp[i];
			i++;
		}
		while (*str[i])
		{
			*str[i] == ' ';
			i++;
		}
	}
	return (0);
}

int		flag_id(char **str, int len, char flag)
{
	char	*valid;

	if (flag == '-')
	{
		//shift str to left;
	}
	if (flag == '+')
	{
		//add '+' if positive number
	}
	if (flag == ' ')
	{
		//add ' ' if positive number
	}
	if (flag == '0')
	{
		//replace prepending ' ' with  '0'
	}
}
