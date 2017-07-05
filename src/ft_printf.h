/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:13:58 by blee              #+#    #+#             */
/*   Updated: 2017/07/03 18:49:06 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int						ft_printf(const char *str, ...);

/* format checking */

int						check_format(char *str, va_list ap);
int						format_checker(char *str, int **formats);
int						find_match(char c, char *str);
int						check_flags(char *str, int **formats);
int						check_width(char *str, int **formats);
int						check_precision(char *str, int **formats);
int						check_length(char *str, int **formats);
int						check_type(char *str, int **formats);

/* build str */

char					*build_str(int *formats, va_list ap);
int						apply_flags(char **output, int *formats, int *len);
int						numeric_flags(char **output, int *formats, int *len, int neg);

/* conversion */

char					*type_to_str1(char c, void *ptr);
char					*type_to_str2(char c, void *ptr);
char					*conversion(int **formats, va_list ap);
char					*one_char_str(char c);

/* lengths */

char					*lengths_to_str(int *formats, va_list ap);

/* width */

int						add_width(char **str, int min);

/* precision */

int						cut_str(char **str, int max, int len);
int						precision_num(char **str, int *formats, int *len);
int						precision(char **str, int *formats, int *len);

/* flags */

int						shift_left(char **str, int len);
int						add_char(char **str, int len, char c);
int						add_char_with_buffer(char **str, int len, char c);
int						zero_buffer(char **str, int len, int neg);
int						add_alt(char **str, char c, int buffer);
int						add_alt_with_zero(char **str, int *formats);
int						add_alt_with_buffer(char **str, int *formats, int buffer);

#endif
