/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:13:58 by blee              #+#    #+#             */
/*   Updated: 2017/05/30 00:16:39 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		check_format(char *str, va_list ap);
int		format_checker(char *str);
char	*type_to_str(char *str, va_list ap);
char	*one_char_str(char c);
int		add_width(char **str, int min);
int		cut_str(char **str, int max);
int		shift_left(char **str, int len);
int		add_char(char **str, int len, char c);
int		add_char_with_buffer(char **str, int len, char c);
int		zero_buffer(char **str, int len);
#endif
