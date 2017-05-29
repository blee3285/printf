/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/25 12:10:52 by blee              #+#    #+#             */
/*   Updated: 2017/05/25 15:44:23 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	cut_str(char **str, int max)
{
	int	len;
	char	*temp;

	len = ft_strlen(*str);
	temp = *str;
	if (len > max)
	{
		temp += max;
		ft_strclr(temp);
	}
	return (0);
}
