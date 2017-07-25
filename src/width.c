/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 18:10:39 by blee              #+#    #+#             */
/*   Updated: 2017/07/24 19:27:30 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_width(char **str, int **formats, int len)
{
	char	*new_size;
	char	*temp;
	int		*form;

	form = *formats;
	new_size = NULL;
	if (form[5] <= len)
		return (len);
	new_size = ft_strnew(form[5]);
	temp = new_size;
	len = form[5] - len;
	while (len)
	{
		*temp = ' ';
		len--;
		temp++;
	}
	ft_strcpy(temp, *str);
	free(*str);
	*str = new_size;
	return (form[5]);
}

int		add_width_wstr(wchar_t **wstr, int **formats, int len)
{
	wchar_t		*new_size;
	wchar_t		*temp;
	int			*form;

	form = *formats;
	new_size = NULL;
	if (form[5] <= len)
		return (len);
	new_size = wstrnew(form[5]);
	temp = new_size;
	while (len)
	{
		*temp = L' ';
		len--;
		temp++;
	}
	wstrcpy(temp, *wstr);
	free(*wstr);
	*wstr = new_size;
	return (form[5]);
}
