/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:47 by blee              #+#    #+#             */
/*   Updated: 2017/05/20 19:59:58 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check_type(char *str, va_list ap)
{
	char	*out;
	char	*temp;

	out = NULL;
	temp = NULL;
	if (*str == 's')
		out = ft_strdup(va_arg(ap, char *));
	if (*str == 'c' || *str == 'C')
	{
		out = ft_strnew(1);
		*out = va_arg(ap, int);
	}
	if (*str == 'd' || *str == 'D' || *str == 'i')
		out = ft_itoa(va_arg(ap, int));
	if (*str == 'o' || *str == 'O')
		out = ft_itoa_base(va_arg(ap, int), 8, 0);
	if (*str == 'x')
		out = ft_itoa_base(va_arg(ap, int), 16, 0);
	if (*str == 'X')
		out = ft_itoa_base(va_arg(ap, int), 16, 1);
	if (*str == 'u' || *str == 'U')
		out = ft_itoa_base(va_arg(ap, unsigned int), 10 ,0);
	if (*str == 'p')
	{
		temp = ft_itoa_base(va_arg(ap, long long), 16, 0);
		out = ft_strjoin("0x", temp);
		free(temp);
	}
	/* Need new functions
	if (*str == 'S') wide char

	optional
	eE - floats in exponent notation
	fF - floats
	gG - double
	aA - double  in hex
	n - num of char into a int pointer?
	*/
	return (out);
}
