/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:47 by blee              #+#    #+#             */
/*   Updated: 2017/05/20 17:06:11 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_type(char *str, va_list ap)
{
	char	*test;

	test = va_arg(ap, char *);
	if (*str == 's')
		ft_putstr(test);
	if (*str == 'c' || *str == 'C')
		ft_putstr("|Found Char|");
	if (*str == 'd' || *str == 'D' || *str == 'i')
		ft_putstr("|Found Int|");
	/* Need new functions
	if (*str == 'o' || *str == 'O') octal
	if (*str == 'x' || *str == 'X')  hex low/upcase
	if (*str == 'u' || *str == 'U') unsigned int
	if (*str == 'p') pointer
	if (*str == 'S') wide char

	optional
	eE - floats in exponent notation
	fF - floats
	gG - double
	aA - double  in hex
	n - num of char into a int pointer?
	*/
	return (0);
}
