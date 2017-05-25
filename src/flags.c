/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:45:25 by blee              #+#    #+#             */
/*   Updated: 2017/05/24 18:59:29 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flag_id(char **str, char flag)
{
	char	*valid;

	if (flag == '-')
	{
		//shift str to left;
	}
	if (flag == '+')
	{
		//add '+' if positive number
	}
	if (flag == ' ')
	{
		//add ' ' if positive number
	}
	if (flag == '0')
	{
		//replace prepending ' ' with  '0'
	}
}
