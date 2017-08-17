/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formats3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 17:59:32 by blee              #+#    #+#             */
/*   Updated: 2017/08/16 17:35:04 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_length(char *str, int **formats)
{
	int		*temp;

	temp = *formats;
	if (ft_strncmp(str, "hh", 2) == 0)
	{
		temp[7] = 1;
		return (2);
	}
	else if (ft_strncmp(str, "ll", 2) == 0)
	{
		temp[7] = 2;
		return (2);
	}
	else if (find_match(*str, "hljz"))
	{
		temp[7] = *str;
		return (1);
	}
	return (0);
}

int		check_type(char *str, int **formats)
{
	int		*temp;

	temp = *formats;
	if (find_match(*str, "sSpdDioOuUxXcC%"))
	{
		temp[8] = *str;
		return (1);
	}
	return (0);
}

char	g_col[20][3][11] = {
	{"{eoc}", "\x1B[0m", "A"},
	{"{bold}", "\x1B[1m", "B"},
	{"{_}", "\x1B[4m", "?"},
	{"{black}", "\x1B[30m", "C"},
	{"{red}", "\x1B[31m", "A"},
	{"{green}", "\x1B[32m", "C"},
	{"{yellow}", "\x1B[33m", "D"},
	{"{blue}", "\x1B[34m", "B"},
	{"{magenta}", "\x1B[35m", "E"},
	{"{cyan}", "\x1B[36m", "B"},
	{"{white}", "\x1B[37m", "C"},
	{"{blackb}", "\x1B[40m", "D"},
	{"{redb}", "\x1B[41m", "B"},
	{"{greenb}", "\x1B[42m", "D"},
	{"{yellowb}", "\x1B[43m", "E"},
	{"{blueb}", "\x1B[44m", "C"},
	{"{magentab}", "\x1B[45m", "F"},
	{"{cyanb}", "\x1B[46m", "C"},
	{"{whiteb}", "\x1B[47m", "D"},
	{"{noc}", "\x1B[0", "A"}};

int		check_color(char *str)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (ft_strncmp(str, g_col[i][0], g_col[i][2][0] - 60) == 0)
		{
			ft_putstr(g_col[i][1]);
			return (g_col[i][2][0] - 61);
		}
		i++;
	}
	return (0);
}
