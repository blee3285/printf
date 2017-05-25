/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:10:39 by blee              #+#    #+#             */
/*   Updated: 2017/05/24 18:31:58 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_width(char **str, int min)
{
	char	*new_size;
	char	*temp;
	int		len;

	new_size = NULL;
	len = ft_strlen(*str);
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
