/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/24 16:49:13 by blee              #+#    #+#             */
/*   Updated: 2017/07/24 19:24:23 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wstrclr(wchar_t *wstr)
{
	if (!wstr)
		return (-1);
	while (*wstr)
	{
		*wstr = 0;
		wstr++;
	}
	return (0);
}

wchar_t	*wstrnew(size_t size)
{
	wchar_t	*new;
	size_t	i;

	new = NULL;
	if (size <= 0)
		return (NULL);
	i = sizeof(wchar_t) * (size + 1);
	new = (wchar_t *)malloc(i);
	ft_bzero(new, i);
	return (new);
}

wchar_t	*wstrcpy(wchar_t *dst, wchar_t *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
