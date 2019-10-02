/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:27 by bprado         #+#    #+#                */
/*   Updated: 2019/10/02 18:59:21 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF

# define FT_PRINTF

// %[flags][width][precision][length][specifier]
// width - takes the form of a nonnegative decimal integer.
// precision takes the form of a period (.) followed by an optional decimal integer; if only the period is specified, the precision is taken as zero.


# include <stdio.h> //for testing printf
# include <stdarg.h>
# include "libft/includes/libft.h"

# define HASH_FLAG 			1 << 0
# define ZERO_FLAG 			1 << 1
# define MINUS_FLAG 		1 << 2
# define SPACE_FLAG 		1 << 3
# define PLUS_FLAG 			1 << 4
# define H_FLAG 			1 << 5
# define L_FLAG 			1 << 6
# define HH_FLAG 			1 << 7
# define LL_FLAG 			1 << 8


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
}				t_pf_object;

typedef void (*pointer_to_functions)(int);

int				ft_printf(const char * restrict format, ...);

#endif