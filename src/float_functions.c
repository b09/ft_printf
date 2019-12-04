/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 21:04:47 by bprado         #+#    #+#                */
/*   Updated: 2019/12/04 21:05:30 by bprado        ########   odam.nl         */
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
	long double		copy;
	char			*strfloat;
	int				i;

	i = 0;
	strfloat = ft_memalloc(length_of_float(obj) + 1);
	if (float_exception(obj))
	{
		free(strfloat);
		return ;
	}
	copy = 	obj->val.lngdbl;
	ret = (obj->val.shdbl[4] & NZERO) ? -(u_int64_t)copy : (u_int64_t)copy;
	ft_putnbr_signed((ret / 10), get_base(obj->spc), obj); // have print
	copy = copy - (ret / 10);
	print_character('.', obj);
	while (obj->prcs-- + 1 > 19)
	{
		copy *= 10.0;
		ret = (u_int64_t)copy;
		ft_putnbr_signed(ret, get_base(obj->spc), obj);
		copy = copy - ret;
	}
	// if (obj->prcs <= 19)
	// 	ret = (u_int64_t)(copy * ft_pow(10.0, (float)obj->prcs + 1));
	ft_putnbr_unsigned(ret, get_base(obj->spc), obj);		// WORKING ON THIS RIGHT NOW

	// unsinged long long can handle 18 * 10^19 digits. if the final digit needs to be rounded
	// and it has an upward cascade effect on the previous digits (.12399999 becomes .124000)
	// i cannot directly print the digits. an uns long long can hold 
}