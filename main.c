/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:31:18 by blee              #+#    #+#             */
/*   Updated: 2017/08/16 17:37:01 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int		main(void)
{
	unsigned char	ptr;
	int		i;
	int		j;
	unsigned char	c;
	wchar_t wc;
	char	*str;
	wchar_t	wstr[] = L"漢字";

	ptr = 'a';
	i = 0;
	j = 0;
	c = 0;
	wc = L'𐍈';
	str = NULL;
	setlocale(LC_ALL, "");
	/*
	printf(RED "red\n" RESET);
	printf(GRN "green\n" RESET);
	printf(YEL "yellow\n" RESET);
	printf(BLU "blue\n" RESET);
	printf(MAG "magenta\n" RESET);
	printf(CYN "cyan\n" RESET);
	printf(WHT "white\n" RESET);
	printf("This is " RED "red" RESET " and this is " BLU "blue" RESET "\n");
	printf("AAA \x1B[31mBBB \x1B[32mCCC\x1B[0m\n");
	printf("Le fichier\x1B[36m%s\x1B[0m contient : \x1B[31m%s\x1B[0m", "BBB", "AAA");
	*/


//	i = printf("|%c%c|\n", '0', '9');
//	j = ft_printf("|%c%c|\n", '0', '9');
	//char	*str = "hellodf";

	//i = printf("printf:    |%&&jhdfhs|\n", 10, 23);
	//j = ft_printf("ft_printf: |%&&jhdfhs|\n", 10, 23);
	//i = printf("%d\n", printf("%hhljtz 4.8%04\n", 1));
	//j = ft_printf("%d\n", ft_printf("%hhljtz 4.8%04\n", 1));
	//i = printf("printf:    |%05=acs%05=|\n", 555);
	//j = ft_printf("ft_printf: |%05=acs%05=|\n", 555);
	//printf("printf: |hello%.3llld|\n", SHRT_MAX);
	//ft_printf("printf: |hello%.3llld|\n", SHRT_MAX);
	//printf("printf: |%jdgb|\n", 525);
	//ft_printf("printf: |%jdgb|\n", 525);
	//printf("printf: |%-+8.9d|%ld|%-+8.9hhhhd|\n", 2345, LONG_MIN, 2345);
	//ft_printf("printf: |%-+8.9d|%ld|%-+8.9hhhhd|\n", 2345, LONG_MIN, 2345);
	//printf("|%-06%-05=%-5#d|\n", 555);
	//ft_printf("|%-06%-05=%-5#d|\n", 555);
	//printf("|%s%9.5S%ls|\n", "hello", L"漢字", L"漢字");
	//ft_printf("|%s%9.5S%ls|\n", "hello", L"漢字", L"漢字");
	//printf("|%c%C%lc|\n", 'h', L'漢', L'漢');
	//ft_printf("|%c%C%lc|\n", 'h', L'漢', L'漢');
	//printf("printf: |%#1.5x|\n", LONG_MAX);
	//ft_printf("printf: |%#1.5x|\n", LONG_MAX);
	//printf("printf: |%#lo|%#ho|%#hho|\n", LONG_MAX, LONG_MAX, LONG_MAX);
	//ft_printf("printf: |%#lo|%#ho|%#hho|\n", LONG_MAX, LONG_MAX, LONG_MAX);
	//printf("printf: |%#1.5x|\n", LONG_MIN);
	//ft_printf("printf: |%#1.5x|\n", LONG_MIN);
	//printf("printf: |%#1.5u|\n", LONG_MIN);
	//ft_printf("printf: |%#1.5u|\n", LONG_MIN);
	//printf("printf: |%#1.5U|\n", LONG_MAX);
	//ft_printf("printf: |%#1.5U|\n", LONG_MAX);
	//printf("printf: |%#l1.5x|\n", "");
	//ft_printf("printf: |%#l1.5x|\n", "");
	//printf("printf: |%#1.5p|\n", "");
	//ft_printf("printf: |%#1.5p|\n", "");
	//printf("%-#8.X\n", 42);
	//ft_printf("%-#8.X\n", 42);
	//printf("%#6o\n", 2500);
	//ft_printf("%#6o\n", 2500);
	//printf("%#08X\n", 42);
	//ft_printf("%#08X\n", 42);
	//printf("@moulitest: %5.x %5.0x|\n", 0, 0);
	//ft_printf("@moulitest: %5.x %5.0x|\n", 0, 0);
	//printf("%05.2s is a string\n", "");
	//ft_printf("%05.2s is a string\n", "");
	//printf("%lu\n", "-42");
	//ft_printf("%lu\n", "-42");
	//printf("%10s is a string\n", "");
	//ft_printf("%10s is a string\n", "");
	//printf("%zu, %zu\n", 0, ULLONG_MAX);
	//ft_printf("%zu, %zu\n", 0, ULLONG_MAX);
	//printf("|%s%9.5S%ls|\n", NULL, NULL, L"漢字");
	//ft_printf("|%s%9.5S%ls|\n", NULL, NULL, L"漢字");
	//printf("%.u, %.0u\n", 0, 0);
	//ft_printf("%.u, %.0u\n", 0, 0);
	//printf("{%-5p}\n", 0);
	//ft_printf("{%-5p}\n", 0);
	//printf("%p\n", 0);
	//ft_printf("%p\n", 0);
	//printf("% p|%+p\n", 42, 42);
	//ft_printf("% p|%+p\n", 42, 42);
	//printf("%.p, %.0p\n", 0, 0);
	//ft_printf("%.p, %.0p\n", 0, 0);
	//printf("{% 03d}\n", 0);
	//ft_printf("{% 03d}\n", 0);
	//printf("{%#6.3x}\n", 1);
	//ft_printf("{%#6.3x}\n", 1);
	//printf("%|#1.5x|\n", NULL);
	//ft_printf("%|#1.5x|\n", NULL);
	//printf("|%C|\n", L'�');
	//ft_printf("|%C|\n", L'�');
	//printf("% ");
	//ft_printf("% ");
	//printf("{%.*d}\n", -5, 42);
	//ft_printf("{%.*d}\n", -5, 42);
	//printf("{%*3d}\n", 0, 0);
	//ft_printf("{%*3d}\n", 0, 0);
	//printf("{%3*d}\n", 0, 0);
	//ft_printf("{%3*d}\n", 0, 0);
	//printf("{%.*s}\n", -5, "42");
	//ft_printf("{%.*s}\n", -5, "42");
	//printf("{%#x}\n", 42544554);
	//ft_printf("{%#x}\n", 42544554);
	// printf("%-+ 5.9f|\n", 1.2234454556);
	// ft_printf("%f ", );
	
	//ft_putstr("\x1B[35m");
	//ft_putstr("\x1B[1m");

	i = printf("a|%C|\n", 0);
	j = ft_printf("{cyan}{blueb}b|%C|{eoc}\n", 0);
	printf("printf: %d\n", i);
	printf("ft_printf: %d\n", j);

	return (0);
}
