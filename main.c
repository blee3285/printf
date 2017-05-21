/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blee <blee@student.42.us.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 20:31:18 by blee              #+#    #+#             */
/*   Updated: 2017/05/20 19:13:29 by blee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

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
	char ptr;

	ptr = 'a';
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

	ft_printf("STR: %s\nCHAR: %c\nINT: %d\nOCTAL: %o\nhex: %x\n", "Hello World!", 'Z', 255, 255, 255);
	ft_printf("HEX: %X\nUNSIGNED INT: %u\n", 255, 2148000000);
	ft_printf("POINTER: %p\n", &ptr);
	return (0);
}
