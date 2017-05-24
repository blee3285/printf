/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:19:11 by blee              #+#    #+#             */
/*   Updated: 2017/05/23 19:00:23 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

int		check_precision(char *str)
{
	if (*str == '.' && ft_isdigit(str[1]))
		return (1);
	return (0);
}

int		check_length(char *str)
{
	if (ft_strncmp(str, "hh", 2) == 0 || ft_strncmp(str, "ll", 2) == 0)
		return (2);
	else if (*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		return (1);
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
			return (1);
		}
		i++;
	}
	free(valid);
	return (0);
}

int		format_checker(char *str)
{
	//char	*output;
	int		total;
	int		len;

	//output = NULL;
	total = 0;
	if ((len = check_flag(*str)))
	{
		total += len;
		ft_putstr("Found Flag: ");
		ft_putchar(*str);
		ft_putchar('\n');
		str++;
	}
	if ((len = ft_isdigit(*str)))
	{
		ft_putstr("Found Width: ");
		ft_putnbr(ft_atoi(str));
		ft_putchar('\n');
		while (ft_isdigit(*str))
		{
			total++;
			str++;
		}
	}
	if ((len = check_precision(str)))
	{
		total += len;
		ft_putstr("Found Precision: ");
		ft_putchar('.');
		str++;
		ft_putnbr(ft_atoi(str));
		ft_putchar('\n');
		while (ft_isdigit(*str))
		{
			total++;
			str++;
		}
	}
	if ((len = check_length(str)))
	{
		total += len;
		ft_putstr("Found Length: ");
		while (len)
		{
			ft_putchar(*str);
			str++;
			len--;
		}
		ft_putchar('\n');
	}
	if ((len = check_type(*str)))
	{
		total += len;
		ft_putstr("Found Type: ");
		ft_putchar(*str);
		str++;
	}
	//output = type_to_str(str, ap);
	//ft_putstr(output);
	return (total);
}
