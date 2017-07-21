/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 18:02:21 by blee              #+#    #+#             */
/*   Updated: 2017/07/21 14:10:55 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*wstr_to_str(wchar_t *wstr)
{
	char	*out;
	char	*temp;
	char	*next;

	//if (!wstr)
	//	return (ft_strdup("(null)"));
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
