/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:47 by blee              #+#    #+#             */
/*   Updated: 2017/05/20 00:30:20 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printd.h"

int		check_conversion(char *str, va_list ap)
{
	if (*str == 's')
		ft_putstr(va_arg(ap, char *));
	if (*str == 'c' || *str = 'C')
		ft_putchar(va_arg(ap, char));
	if (*str == 'd' || *str == 'D' || *str == 'i')
		ft_putnbr(va_arg(ap, int));
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
}
