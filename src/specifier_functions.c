/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:18:01 by bprado         #+#    #+#                */
/*   Updated: 2019/11/28 20:42:32 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(t_pf_object *obj)
{
	parse_length(obj);
	obj->i = length_of_number(obj);
	if (obj->flags & MINUS_F)
	{
		// 0x18 SPACE & PLUS & SIGNED
		obj->spc != 'c' ? print_sign(obj) : 0;
		print_padding(obj, obj->i, '0', 1);
		obj->spc != 'c' ? ft_putnbr_base2(obj->val.ll, get_base(obj->spc), obj) : print_character(obj->val.ll, obj);
		print_padding(obj, (obj->i > obj->prcs) ? obj->i : obj->prcs, ' ', 0);
	}
	else
	{
		// 0x208 SPACE & SIGNED
		// if ((obj->width <= obj->prcs && obj->width <= obj->i) || obj->flags & SPACE_F)
			((obj->flags & 0x208) && obj->val.llong >= 0) || (obj->val.llong < 0 && obj->flags & ZERO_F) ? print_sign(obj) : 0;

		if (obj->width > obj->prcs && obj->flags & PRECISN)// && !(obj->flags & ZERO_F))
			print_padding(	obj, 
							obj->i > obj->prcs ? obj->i : obj->prcs, 
							' ', 
							0);
		else
			print_padding(	obj, 
							obj->i > obj->prcs ? obj->i : obj->prcs, 
							obj->flags & ZERO_F ? '0' : ' ', 
							0);

		
		
		(obj->flags & SIGNED_F) && obj->val.llong < 0 && !(obj->flags & ZERO_F) ? print_sign(obj) : 0;
		print_padding(obj, obj->i, obj->spc != 'c' ? '0' : ' ', 1);
		obj->spc != 'c' ? ft_putnbr_base2(obj->val.ll, get_base(obj->spc), obj) : print_character(obj->val.ll, obj);
	}
}

// void	print_o(t_pf_object *obj)
// {
// 	if (obj->spc == 'p')
// 		obj->val.ptr = va_arg(obj->ap, void*);
// 	else
// 		parse_length(obj);
// 	// obj->i = get_base(obj->spc);
// 	// obj->i = obj->i % 8 && obj->i != 0 ? 2 - length_of_number(obj) : length_of_number(obj);
// 	if (obj->flags & MINUS_F)
// 	{
// 		(obj->flags & HASH_F && obj->spc != 'u') || obj->spc == 'p' ?
// 			print_hash_flag(obj) : 0;
// 		print_padding(obj, obj->i, '0', 1);
// 		ft_putnbr_base2(obj->val.ll, get_base(obj->spc), obj);
// 		print_padding(obj, (obj->i > obj->prcs) ? obj->i : obj->prcs, ' ', 0);
// 	}
// 	else
// 	{
// 		// (obj->flags & HASH_F) && obj->spc == 'x' || obj->spc == 'X' ? 

// 		// the order of the below func calls needs to be reexamined
// 		print_padding(obj,
// 			obj->i > obj->prcs ? obj->i : obj->prcs,
// 			obj->flags & ZERO_F ? '0' : ' ',
// 			1);
// 		if ((obj->flags & HASH_F && obj->spc != 'u') || obj->spc == 'p')
// 			print_hash_flag(obj);
// 		print_padding(obj, obj->i, '0', 0);
// 		ft_putnbr_base2(obj->val.ll, get_base(obj->spc), obj);
// 	}
// }

/*
	WIDTH
	Minimum number of characters to be printed. If the value to be printed is shorter 
	than this number, the result is padded with blank spaces. The value is not truncated 
	even if the result is larger.

	PRECISION
	For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of 
	digits to be written. If the value to be written is shorter than this number, the 
	result is padded with leading zeros. The value is not truncated even if the result 
	is longer. A precision of 0 means that no character is written for the value 0.

	print_padding(1) for precision
	print_padding(0) for width
 */
void	print_o(t_pf_object *obj)
{
	if (obj->spc == 'p')
		obj->val.ptr = va_arg(obj->ap, void*);
	else
		parse_length(obj);
	obj->i = length_of_number(obj);
	if (obj->flags & MINUS_F)
	{
		(obj->flags & HASH_F && obj->spc != 'u') || obj->spc == 'p' ?
			print_hash_flag(obj) : 0;
		print_padding(obj, obj->i, '0', 1);
		ft_putnbr_base2(obj->val.ll, get_base(obj->spc), obj);
		print_padding(obj, (obj->i > obj->prcs) ? obj->i : obj->prcs, ' ', 0);
	}
	else
	{
		// width must consider lengh of output, in order only print correct number of 
		// characters in padding
		if (((obj->flags & (HASH_F | ZERO_F)) == 0X3 && obj->spc != 'u') || obj->spc == 'p')
			print_hash_flag(obj);
		print_padding(obj,	obj->i > obj->prcs ? obj->i : obj->prcs,
							obj->flags & ZERO_F ? '0' : ' ',
							0);
		if ((obj->flags & HASH_F && !(obj->flags & ZERO_F) && obj->spc != 'u'))// || obj->spc == 'p')
			print_hash_flag(obj);
		print_padding(obj, obj->i, '0', 1);
		ft_putnbr_base2(obj->val.ll, get_base(obj->spc), obj);
	}
}

void	print_str(t_pf_object *obj)
{
	int			str_length;

	str_length = 0;
	if (obj->spc == 's')
	{
		obj->val.ptr = va_arg(obj->ap, char*);
		str_length = obj->prcs < (int)ft_strlen(obj->val.ptr) && obj->flags & PRECISN ?
										obj->prcs : ft_strlen(obj->val.ptr);
		obj->flags |= STRNG;
	}
	if (obj->flags & MINUS_F)
	{
		obj->spc == 's' ? print_string(obj) : print_character(obj->spc, obj);
		print_padding(obj, obj->spc == 's' ? str_length : 1, ' ', 0);
	}
	else
	{
		print_padding(obj, 
			obj->spc == 's' ? str_length : 1,
			(obj->flags & ZERO_F) ? '0' : ' ',
			0);
		obj->spc == 's' ? print_string(obj) : print_character(obj->spc, obj);
	}
}

void	print_f(t_pf_object *obj)
{
	int			base;
	long long	ret;
	long double	copy;

	parse_length(obj);
	base = 10;
	copy = (obj->flags & CAP_L_F) ? va_arg(obj->ap, long double) :
											va_arg(obj->ap, double);
	obj->val.lngdbl = copy;
	if (obj->prcs == 0)
		obj->prcs = 6;
	ret = (long long)copy;
	ft_putnbr_base2(ret, base, obj);
	copy = copy - ret;
	print_character('.', obj);
	while (obj->prcs--)
	{
		copy *= 10.0;
		ret = (long long)copy;
		ft_putnbr_base2(ret, base, obj);
		copy = copy - ret;
	}
}
