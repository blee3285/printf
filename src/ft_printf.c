/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:21:17 by blee              #+#    #+#             */
/*   Updated: 2017/07/28 20:04:33 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_string(int **formats, va_list ap)
{
	char	*output;
	int		len;
	int		*temp;

	temp = *formats;
	output = build_str(formats, ap);
	len = temp[9];
	ft_putstr(output);
	ft_bzero(*formats, 40);
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

int		valid_format(char *str, int **formats, va_list ap)
{
	int len;
	int	*temp;

	len = 0;
	temp = *formats;
	if (*str == '%')
	{
		len += format_checker(str + 1, formats, ap);
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
	formats = ft_intarray(10);
	while (*str)
	{
		if ((len = valid_format(str, &formats, ap)))
		{
			str += len;
			i += print_string(&formats, ap);
		}
		else if (*str != '%')
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
