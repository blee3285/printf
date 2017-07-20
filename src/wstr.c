/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 18:02:21 by blee              #+#    #+#             */
/*   Updated: 2017/07/19 17:51:03 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*wstr_to_str(wchar_t *wstr)
{
	char	*out;
	char	*temp;
	char	*next;

	out = ft_strnew(1);
	temp = NULL;
	next = NULL;
	while (*wstr)
	{
		next = wchar_to_str(*wstr);
		temp = out;
		out = ft_strjoin(out, next);
		free(temp);
		free(next);
		wstr++;
	}
	return (out);
}
