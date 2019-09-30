/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:27 by bprado         #+#    #+#                */
/*   Updated: 2019/09/30 19:19:34 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF

# define FT_PRINTF

// %[flags][width][precision][length][specifier]
// width - takes the form of a nonnegative decimal integer.
// precision takes the form of a period (.) followed by an optional decimal integer; if only the period is specified, the precision is taken as zero.


# include <stdio.h> //for testing printf
# include <stdarg.h> // for multi-parameters in ft_printf
# include "libft/includes/libft.h"

# define HASH_FLAG 			1 << 0;
# define ZERO_FLAG 			1 << 1;
# define MINUS_FLAG 		1 << 2;
# define SPACE_FLAG 		1 << 3;
# define PLUS_FLAG 			1 << 4;
# define H_FLAG 			1 << 5;
# define HH_FLAG 			1 << 6;
# define L_FLAG 			1 << 7;
# define LL_FLAG 			1 << 8;






/*
	will reimpliment s_flags as single int member is s_pf_object using bitwise operators
 */
typedef struct s_flags
{
	char		h;
	char		hh;
	char		l;
	char		ll;
	char		hash;
	char		zero;
	char		minus;
	char		plus;
	char		space;
	
}				t_flags;

typedef struct	s_pf_object
{
	const char*	str;
	short		flags;
	char		output[20];
	int			i_str;
	int			width;
	int			precision;
	char		sharp;
	char		zero;
	char		minus;
	char		space;
	char		plus;
	int			length;
	va_list		ap;
	// t_flags		flags;

}				t_pf_object;

int				ft_printf(const char * restrict format, ...);

	// create bitmask containing all possible flags: ' ', -, +, 0, #
	// the flags will only transform the data, by themselves they do nothing
	// the field width takes the form of a nonnegative decimal integer.
	// F_HASH
	// F_ZERO 
	// F_MINUS
	// F_PLUS
	// F_SPACE
	// LL_LENGTH
	// L_LENGTH
	// H_LENTH
	// HH_LENTH

#endif