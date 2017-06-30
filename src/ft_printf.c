/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:17 by blee              #+#    #+#             */
/*   Updated: 2017/06/29 17:49:43 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(int **formats, va_list ap)
{
	char	*output;
	int		len;

	output = build_str(*formats, ap);
	len = ft_strlen(output);
	ft_putstr(output);
	ft_bzero(*formats, 36);
	free(output);
	return (len);
}

int		*ft_intarray(int size)
{
	int		*array;

	array = (int *)malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	ft_bzero(array, (size * 4));
	return (array);
}

int		valid_format(char *str, int **formats)
{
	int len;
	int	*temp;

	len = 0;
	temp = *formats;
	if (*str == '%')
	{
		len += format_checker(str + 1, formats);
		if (temp[8])
			return (len);
	}
	return (0);
}

int		check_format(char *str, va_list ap)
{
	int		len;
	int		*formats;
	int		i;

	i = 0;
	formats = ft_intarray(9);
	while (*str)
	{
		if ((len = valid_format(str, &formats)))
		{
			str += len;
			i += print_string(&formats, ap);
		}
		else
		{
			ft_putchar(*str);
			i++;
		}
		str++;
	}
	free(formats);
	return (i);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;

	va_start(ap, str);
	if (!str)
	{
		str = (va_arg(ap, char *));
		ft_putstr(str);
		return (ft_strlen(str));
	}
	i = check_format((char *)str, ap);
	va_end(ap);

	return (i);
}
