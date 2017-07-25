/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wstr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 18:02:21 by blee              #+#    #+#             */
/*   Updated: 2017/07/24 19:29:30 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		wide_str_check(int	*form)
{
	if (form[8] == 'C' || form[8] == 'S' || 
		(form[7] == 'l' && (form[8] == 'c' || form[8] == 's')))
		return (1);
	return (0);
}

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

wchar_t	*wchar_to_wstr(wchar_t wc)
{
	wchar_t	*out;

	out = (wchar_t *)malloc(sizeof(wchar_t) * 2);
	out[0] = wc;
	out[1] = 0;
	return (out);
}

wchar_t	*wstr_dup(wchar_t *wstr)
{
	int		i;
	wchar_t	*out;

	i = 0;
	out = NULL;
	while(wstr[i])
		i++;
	out = (wchar_t)malloc(sizeof(wchar_t) * (i + 1));
	i = 0;
	while (wstr[i])
	{
		out[i] = wstr[i];
		i++;
	}
	out[i] = 0;
	return (out);
}

char	*wstr_manager(int **formats, va_list ap)
{
	wchar_t	*wstr;
	int		*temp;
	char	*out;
	int		len;

	temp = *formats;
	if (temp[8] == 'c' || temp[8] == 'C')
		wstr = wchar_to_wstr(va_arg(ap, wchar_t));
	else
		wstr = wstr_dup(va_arg(ap, wchar_t *));


