/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:27 by bprado         #+#    #+#                */
/*   Updated: 2019/10/28 12:42:57 by bprado        ########   odam.nl         */
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

# define HASH_F 		1 << 0
# define ZERO_F 		1 << 1
# define MINUS_F 		1 << 2
# define SPACE_F 		1 << 3
# define PLUS_F 		1 << 4
# define H_F 			1 << 5
# define L_F 			1 << 6
# define HH_F 			1 << 7
# define LL_F 			1 << 8
# define SIGNED_F		1 << 9


typedef union	u_union_output
{
	unsigned long long	u_lnglng;
	double				u_double;
	void*				u_pointer;
		
}				union_output;

typedef struct	s_pf_object
{
	const char*			str;
	short				flags;
	char				buffer[32];
	int					ibuff;
	union_output		u_output;
	int					i_str;
	int					width;
	int					precision;
	int					length;
	va_list				ap;
}				t_pf_object;

typedef void (*pointer_to_functions)(int);

int				ft_printf(const char * restrict format, ...);

#endif