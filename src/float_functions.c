/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 21:04:47 by bprado         #+#    #+#                */
/*   Updated: 2019/12/09 12:30:17 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length_of_float(t_pf_sect *s)
{
	int				counter;
	long double		original_float;

	// include decimal in length and a single character
	counter = 0;
	if (((s->val.shdbl[4] & NZERO) == NZERO) && s->val.llong == 0)
		counter = 2 + s->prcs;
	counter = ((s->val.shdbl[4] & NINF) == NINF) && s->val.llong == 0 ? 4 : counter;
	counter = ((s->val.shdbl[4] & INF) == INF) && s->val.llong == 0 ? 3 : counter;
	counter = ((s->val.shdbl[4] & INF) == INF) && s->val.llong > 0 ? 3 : counter;
	if (counter)
		return (counter);
	counter = 2;
	original_float = s->val.lngdbl;
	counter += s->flags & PRECISN ? s->prcs : 6;
	counter = s->flags & PRECISN && !s->prcs ? 1 : counter;
	if (original_float < 0)
		original_float = -original_float;
	while (original_float > 9)
	{
		original_float /= 10;
		++counter;
	}
	counter += s->val.lngdbl < 0 ? 1 : 0;
	counter += s->flags & (HASH_F | PLUS_F | SPACE_F) ? 1 : 0;
	return (counter);
}

// create function to print character strings -inf, inf, nan, -0
// function works
int		float_exception(t_pf_sect *s)
{
	char 		*str1;
	char 		*str2;
	char 		*str3;
	char 		*str4;

	str1 = "-0";
	str2 = "-inf";
	str3 = "inf";
	str4 = "nan";

	if ((s->val.shdbl[4] & NZERO) == NZERO && s->val.llong == 0)
		s->val.ptr = str1; 	// 	-0 negative zero
	else if ((s->val.shdbl[4] & NINF) == NINF && s->val.llong == 0)
		s->val.ptr = str2;
	else if ((s->val.shdbl[4] & INF) == INF && s->val.llong == 0)
		s->val.ptr = str3;
	else if ((s->val.shdbl[4] & INF) == INF && s->val.llong > 0)
		s->val.ptr = str4;
	else
		return (0);
	print_string(s);
	return (1);
}

/*
	character array
	assign front part of float to array
	add decimal point
	interate though number
 */

// 	// unsinged long long can handle 18 * 10^19 digits. if the final digit needs to be rounded
// 	// and it has an upward cascade effect on the previous digits (.12399999 becomes .124000)
// 	// i cannot directly print the digits. an uns long long can hold 
// }

static void		round_float(char *str, int i)
{
	str[i] = 0;
	i--;
	if (str[i] != '9' && str[i] != '.')
		++str[i];
	else 																			// else the character is 9 or '.'
	{
		while (i > -1 && (str[i] == '9' || str[i] == '.')) 							// while must convert 9's to 0's , jump over '.',  stop when not 9 AND increase THAT character by one
		{
			str[i] = (str[i] != '.') ? '0' : '.';
			i--;
			if (str[i] != '9' && str[i] != '.')
			{
				++str[i];
				break ;
			}
			else if (str[i] == '.')
			{
				--i;
				if (str[i] != '9')
				{
					++str[i];
					break ;
				}
			}

		}

	}
}

static char		*string_for_float(t_pf_sect *s, char flip, char *decimalstr)
{
	char			*entire_float;
	char			*num_no_dec;
	long double		copy;
	int				i;

	if (flip)
	{
		i = s->prcs + 3 ; 													// including null character and decimal character, and first character of decimal
		decimalstr = ft_memalloc(i);
		ft_memset(decimalstr, 'a', i - 1); 										// to use string function must populate malloced content with non NULL chars
		decimalstr[0] = '.';
		copy = s->val.lngdbl < 0 ? -s->val.lngdbl : s->val.lngdbl;
		num_no_dec = ft_itoa_unsigned(copy, 0);
		entire_float = ft_strjoin(num_no_dec, decimalstr); 						// strjoin will not work on null characters
		ft_memdel((void*)&num_no_dec);
	}
	else
		entire_float = ft_strjoin("1", decimalstr);
	ft_memdel((void*)&decimalstr);
	return (entire_float);
}

void	putfloat(t_pf_sect *s, int i, int str_i)							// i is precision plus one
{
	long double		copy;
	int				k;
	int				j;

	if (float_exception(s))
		return ;
	copy = s->val.lngdbl < 0 ? -s->val.lngdbl : s->val.lngdbl;
	s->temp = string_for_float(s, 1, s->temp2);
	j = s->temp[0]; 														// capture first character of string to compare later if it was zero
	str_i = ft_strchr_int(s->temp, 'a'); 										// index of string past decimal
	k = str_i;																	// index of string past decimal for later use
	while (i) 																	// assign character of long double to string
	{
		copy *= 10.0;
		s->temp[str_i] = ((int64_t)copy % 10) + '0';
		--i;
		++str_i;
	}
	--str_i;

	if ((s->temp[str_i] - '0') % 10 > 4)										// check if character, which is one character beyond precision, will cause next character to go up
		round_float(s->temp, str_i);
	else
		s->temp[str_i] = 0;
	if (s->temp[0] == '0' && j != '0') 									// if rounding causes all zeroes, new string must be made with '1' at beginning
		s->val.ptr = string_for_float(s, 0, s->temp);
	else
		s->val.ptr = s->temp;
	((char*)s->val.ptr)[k + (s->prcs ? s->prcs + 1 : -1)] = 0;
	print_string(s);
	if (s->flags & HASH_F && s->prcs == 0)
		print_character('.', s);
	ft_memdel((void*)&s->temp2);
}

		