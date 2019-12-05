/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 21:04:47 by bprado         #+#    #+#                */
/*   Updated: 2019/12/06 00:06:05 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		length_of_float(t_pf_object *obj)
{
	int				counter;
	long double		original_float;

	// include decimal in length and a single character
	counter = 0;
	if (((obj->val.shdbl[4] & NZERO) == NZERO) && obj->val.llong == 0)
		counter = 2 + obj->prcs;
	counter = ((obj->val.shdbl[4] & NINF) == NINF) && obj->val.llong == 0 ? 4 : counter;
	counter = ((obj->val.shdbl[4] & INF) == INF) && obj->val.llong == 0 ? 3 : counter;
	counter = ((obj->val.shdbl[4] & INF) == INF) && obj->val.llong > 0 ? 3 : counter;
	if (counter)
		return (counter);
	counter = 2;
	original_float = obj->val.lngdbl;
	counter += obj->flags & PRECISN ? obj->prcs : 6;
	
	if (original_float < 0)
		original_float = -original_float;
	while (original_float > 9)
	{
		original_float /= 10;
		++counter;
	}
	counter += obj->val.lngdbl < 0 ? 1 : 0;
	return (counter);
}

// create function to print character strings -inf, inf, nan, -0
// function works
int		float_exception(t_pf_object *obj)
{
	char 		*str1;
	char 		*str2;
	char 		*str3;
	char 		*str4;

	str1 = "-0";
	str2 = "-inf";
	str3 = "inf";
	str4 = "nan";

	if ((obj->val.shdbl[4] & NZERO) == NZERO && obj->val.llong == 0)
		obj->val.ptr = str1; 	// 	-0 negative zero
	else if ((obj->val.shdbl[4] & NINF) == NINF && obj->val.llong == 0)
		obj->val.ptr = str2;
	else if ((obj->val.shdbl[4] & INF) == INF && obj->val.llong == 0)
		obj->val.ptr = str3;
	else if ((obj->val.shdbl[4] & INF) == INF && obj->val.llong > 0)
		obj->val.ptr = str4;
	else
		return (0);
	print_string(obj);
	return (1);
}

void	putfloat(t_pf_object *obj)
{
	u_int64_t		ret;
	u_int64_t		ret2;
	long double		copy;
	int				i;
	int				zeroes;

	i = obj->prcs <= 20 ? obj->prcs : 20;
	if (float_exception(obj))
		return ;
	copy = obj->val.lngdbl < 0 ? -obj->val.lngdbl : obj->val.lngdbl;
	ret = (u_int64_t)copy;
	copy = copy - ret;
	ret2 = 0;
	zeroes = 0;
	while (i + 1)
	{
		copy *= 10.0;
		ret2 = (ret2 * 10) + copy;
		if (!ret2)
			++zeroes;
		copy = copy - (((u_int64_t)copy % 10));
		--i;
	}
	ret2 += (ret2 % 10) > 4 ? 10 : 0;
	ret2 /= 10;
	i = obj->prcs <= 20 ? obj->prcs : 20;
	(ret2 >= (u_int64_t)ft_pow(10, i)) ? ft_putnbr_unsigned(ret + 1, get_base(obj->spc), obj) : ft_putnbr_unsigned(ret, get_base(obj->spc), obj);
	if (obj->prcs)
	{
		print_character('.', obj);
		while (zeroes && obj->prcs)
		{
			print_character('0', obj);
			--zeroes;
			--obj->prcs;
		}
		ret2 ? ft_putnbr_unsigned(ret2, get_base(obj->spc), obj) : 0;
	}

	// unsinged long long can handle 18 * 10^19 digits. if the final digit needs to be rounded
	// and it has an upward cascade effect on the previous digits (.12399999 becomes .124000)
	// i cannot directly print the digits. an uns long long can hold 
}