/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:29 by bprado         #+#    #+#                */
/*   Updated: 2019/09/27 14:46:07 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	ft_printf("beans");
	return (0);
}

/*

SPECIFIERS LISTED:	c, s, p, d, i, o, u, x, X, f, %

FLAGS: 				hh, h, l, ll, #, 0, -, +, *, ' '(space)

	
	%[width].[precision]

WIDTH:
	converted characters < field width ? padded with spaces on right or left if specified
 
PRECISION:
	min number of digits to appear for d, i, o, u, x, and X conversions
	min number of digits to appear after the radix character for f conversions
	max number of characters to be printed from a string for s conversions.

SPECIAL CASES:
	
*/

// NATURAL FORMAT SPECIFIERS
// printf("%c");
// printf("%s");
// printf("%p");
// printf("%d");
// printf("%i");
// printf("%o");
// printf("%u");
// printf("%x");
// printf("%X");
// printf("%f");
// printf("%%");


// // LENGTH MODIFIERS hh, h, l, ll
// 	// %d
// printf("%hhd");
// printf("%hd");
// printf("%ld");
// printf("%lld");

// 	// %i
// printf("%hhi");
// printf("%hi");
// printf("%li");
// printf("%lli");

// 	// %o
// printf("%hho");
// printf("%ho");
// printf("%lo");
// printf("%llo");

// 	// %u
// printf("%hhu");
// printf("%hu");
// printf("%lu");
// printf("%llu");

// 	// %x
// printf("%hhx");
// printf("%hx");
// printf("%lx");
// printf("%llx");

// 	// %X
// printf("%hhX");
// printf("%hX");
// printf("%lX");
// printf("%llX");


// // FORMAT SPECIFIERS WITH FIELD WIDTH
// printf("%3c");
// printf("%3s");
// printf("%3p");


// // FORMAT SPECIFIERS WITH PRECISION
// printf("%.3c");
// printf("%.3s");
// printf("%.3p");

// // FORMATE SPECIFIERS WITH FLAGS
// printf("%0c");
// printf("%3s");
// printf("%3p");


test all examples of printf with flags

use strchr to find %
write to screen everything before %