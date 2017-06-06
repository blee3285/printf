/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:45:25 by blee              #+#    #+#             */
/*   Updated: 2017/06/05 16:51:47 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	shift_left(char **str, int len)
{
	char	*temp;
	int	buffer;

	buffer = ft_strlen(*str) - len;
	temp = *str + buffer;
	ft_strncpy(*str, temp, len);
	temp = *str + len;
	ft_memset(temp, ' ', buffer);
	return (0);
}

int	add_char(char **str, int len, char c)
{
	char	*new;

	new = ft_strnew(len + 1);
	new[0] = c;
	ft_strcpy(&new[1], *str);
	free(*str);
	*str = new;
	return (0);
}

int	add_char_with_buffer(char **str, int len, char c)
{
	char	*temp;
	int	buffer;

	buffer = ft_strlen(*str) - len;
	temp = *str;
	temp += buffer - 1;
	*temp = c;
	return (0);
}

int	zero_buffer(char **str, int len, int neg){
	int	buffer;

	if (neg)
		len--;
	buffer = ft_strlen(*str) - len;
	ft_memset(*str, '0', buffer);
	if (neg)
		**str = '-';
	return (0);
}
