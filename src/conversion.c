/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 12:14:47 by blee              #+#    #+#             */
/*   Updated: 2017/05/20 19:14:32 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr_u(n / 10);
		ft_putchar((n % 10) + '0');
	}
	else
		ft_putchar(n + '0');
}

int		check_type(char *str, va_list ap)
{
	if (*str == 's')
		ft_putstr(va_arg(ap, char *));
	if (*str == 'c' || *str == 'C')
		ft_putchar(va_arg(ap, int));
	if (*str == 'd' || *str == 'D' || *str == 'i')
		ft_putnbr(va_arg(ap, int));
	if (*str == 'o' || *str == 'O')
		ft_putstr(ft_itoa_base(va_arg(ap, int), 8, 0));
	if (*str == 'x')
		ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 0));
	if (*str == 'X')
		ft_putstr(ft_itoa_base(va_arg(ap, int), 16, 1));
	if (*str == 'u' || *str == 'U')
		ft_putnbr_u(va_arg(ap, unsigned int));
	if (*str == 'p')
	{
		ft_putstr("0x");
		ft_putstr(ft_itoa_base(va_arg(ap, long long), 16, 0));
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
	return (0);
}
