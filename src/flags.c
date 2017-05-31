/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:45:25 by blee              #+#    #+#             */
/*   Updated: 2017/05/30 13:51:00 by blee             ###   ########.fr       */
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
	char	*new;
	char	*temp;
	int	buffer;

	buffer = ft_strlen(*str) - len;
	new = ft_strnew(buffer + len + 1);
	temp = new;
	ft_strncpy(temp, *str, buffer);
	temp += buffer;
	*temp = c;
	temp++;
	ft_strcpy(temp, (*str + buffer));
	free(*str);
	*str = new;
	return (0);
}

int	zero_buffer(char **str, int len)
{
	int	buffer;

	buffer = ft_strlen(*str) - len;
	ft_memset(*str, '0', buffer);
	return (0);
}

int		flag_id(char **str, int len, char flag)
{
	if (flag == '-')
		shift_left(str, len);
	if (flag == '+')
		add_char_with_buffer(str, len, '+');
	if (flag == ' ')
		add_char_with_buffer(str, len, ' ');
	if (flag == '0')
		zero_buffer(str, len);
	return (0);
}

