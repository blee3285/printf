/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:10:39 by blee              #+#    #+#             */
/*   Updated: 2017/07/06 14:30:26 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_width(char **str, int min, int len)
{
	char	*new_size;
	char	*temp;

	new_size = NULL;
	if (min <= len)
		return (1);
	new_size = ft_strnew(min);
	temp = new_size;
	len = min - len;
	while (len)
	{
		*temp = ' ';
		len--;
		temp++;
	}
	ft_strcpy(temp, *str);
	free(*str);
	*str = new_size;
	return (1);
}
