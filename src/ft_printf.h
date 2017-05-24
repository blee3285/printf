/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:13:58 by blee              #+#    #+#             */
/*   Updated: 2017/05/23 18:47:45 by blee             ###   ########.fr       */
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

#endif
