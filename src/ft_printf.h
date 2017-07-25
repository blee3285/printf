/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 14:13:58 by blee              #+#    #+#             */
/*   Updated: 2017/07/24 18:57:10 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int				ft_printf(const char *str, ...);

int				check_format(char *str, va_list ap);
int				format_checker(char *str, int **formats, va_list ap);
int				find_match(char c, char *str);
int				check_flags(char *str, int **formats);
int				check_width(char *str, int **formats, va_list ap);
int				check_precision(char *str, int **formats, va_list ap);
int				check_length(char *str, int **formats);
int				check_type(char *str, int **formats);

char			*build_str(int **formats, va_list ap);
int				apply_flags(char **output, int **formats, int *len);
int				numeric_flags(char **out, int **form, int *len, int neg);

char			*type_to_str1(char c, void *ptr);
char			*type_to_str2(char c, void *ptr);
char			*conversion(int **formats, va_list ap);
char			*one_char_str(char c);

char			*lengths_to_str(int **formats, void *ptr);

int				add_width(char **str, int **formats, int len);

int				cut_str(char **str, int max, int len);
int				precision_num(char **str, int **formats, int *len);
int				precision(char **str, int **formats, int *len);
int				cut_wstr(wchar_t **wstr, int max, int len);

int				shift_left(char **str, int len);
int				add_char(char **str, int len, char c);
int				add_char_with_buffer(char **str, int len, char c);
int				zero_buffer(char **str, int len, int neg);
int				add_alt(char **str, int *form, int buffer);
int				add_alt_with_zero(char **str, int *formats);
int				add_alt_with_buffer(char **str, int *formats, int buffer);

char			*wchar_to_str(wchar_t wc);
char			*wstr_to_str(wchar_t *wstr);
int				wide_str_check(int *form);
wchar_t			*wchar_to_wstr(wchar_t wc);
wchar_t			*wstr_dup(wchar_t *wstr);
char			*wstr_manager(int **formats, va_list ap);
int				wstrclr(wchar_t *wstr);

#endif
