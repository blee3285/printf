/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:59:32 by blee              #+#    #+#             */
/*   Updated: 2017/06/07 14:18:05 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_length(char *str, int **formats)
{
	int		*temp;

	temp = *formats;
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		temp[7] = 1;
		return (2);
	}
	else if (ft_strncmp(str, "ll", 2) == 0)
	{
		temp[7] = 2;
		return (2);
	}
	else if (find_match(*str, "hljz"))
	{
		temp[7] = *str;
		return (1);
	}
	return (0);
}

int		check_type(char *str, int **formats)
{
	int		*temp;

	temp = *formats;
	if (find_match(*str, "sSpdDioOuUxXcC%"))
	{
		temp[8] = *str;
		return (1);
	}
	return (0);
}
