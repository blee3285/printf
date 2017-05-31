/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:19:11 by blee              #+#    #+#             */
/*   Updated: 2017/05/30 18:36:36 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (c);
	return (0);
}

int		check_precision(char *str)
{
	if (*str == '.' && (ft_isdigit(str[1]) || *str == '*'))
		return (1);
	return (0);
}

int		check_length(char *str)
{
	if (ft_strncmp(str, "hh", 2) == 0)
		return (1);
	else if (ft_strncmp(str, "ll", 2) == 0)
		return (2);
	else if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		return (*str);
	return (0);
}

int		check_type(char c)
{
	int		i;
	char	*valid;

	i = 0;
	valid = ft_strdup("sSpdDioOuUxXcC");
	while (valid[i])
	{
		if (valid[i] == c)
		{
			free(valid);
			return (c);
		}
		i++;
	}
	free(valid);
	return (0);
}

int		format_checker(char *str, int **formats)
{
	int		total;
	int		len;
	int		*temp;

	temp = *formats;
	total = 0;
	if ((len = check_flag(*str)))
	{
		temp[0] = len;
		total += 1;
		str++;
	}
	if (((len = ft_isdigit(*str))))
	{
		temp[1] = len;
		while (ft_isdigit(*str))
		{
			total++;
			str++;
		}
	}
	if (((len = check_precision(str))))
	{
		temp[2] = len;
		total += 1;
		str++;
		while (ft_isdigit(*str))
		{
			total++;
			str++;
		}
	}
	if ((len = check_length(str)))
	{
		temp[3] = len;
		total += 1;
		str += 1;
		if (len == 2 || len == 1)
		{
			total += 1;
			str += 1;
		}
	}
	if ((len = check_type(*str)))
	{
		temp[4] = len;
		total += 1;
		str++;
	}
	if (len == 0)
		return (0);
	return (total);
}
