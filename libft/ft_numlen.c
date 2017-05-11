/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:18:32 by blee              #+#    #+#             */
/*   Updated: 2017/05/10 17:34:56 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(long long num, int base)
{
	int count;

	count = 0;
	if (num <= 0)
	{
		count++;
		num = -num;
	}
	while (num > 0)
	{
		num /= base;
		count++;
	}
	return (count);
}
