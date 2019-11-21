/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:18:01 by bprado         #+#    #+#                */
/*   Updated: 2019/11/21 20:53:44 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_d(t_pf_object *obj)
{
	obj->val.ll = va_arg(obj->ap, int);
	parse_length(obj, 0);
	obj->i = length_of_number(obj);
	if (obj->flags & MINUS_F)
	{
		(obj->flags & PLUS_F || obj->flags & SPACE_F) && obj->spc != 'c' ?
			print_sign(obj) : 0;
		print_padding(obj, obj->i, '0', 1);
		obj->spc != 'c' ?
			ft_putnbr_base2(obj->val.ll, get_base(obj->spc), obj) :
			print_character(obj->val.ll, obj);
		print_padding(obj, (obj->i > obj->prcs) ? obj->i : obj->prcs, ' ', 0);
	}
	else
	{
		(obj->flags & SIGNED_F || obj->flags & SPACE_F) ? print_sign(obj) : 0;
		print_padding(obj,
			obj->i > obj->prcs ? obj->i : obj->prcs,
			obj->flags & ZERO_F ? '0' : ' ',
			0);
		print_padding(obj, obj->i, '0', 1);
		obj->spc != 'c' ?
			ft_putnbr_base2(obj->val.ll, get_base(obj->spc), obj) :
			print_character(obj->val.ll, obj);
	}
}

void	print_o(t_pf_object *obj)
{
	if (obj->spc != 'p')
		obj->val.ll = va_arg(obj->ap, unsigned int);
	else
		obj->val.ptr = va_arg(obj->ap, void*);
	obj->spc != 'p' ? parse_length(obj, 0) : 0;
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
		if ((obj->flags & HASH_F && obj->spc != 'u') || obj->spc == 'p')
			print_hash_flag(obj);
		print_padding(obj,
			obj->i > obj->prcs ? obj->i : obj->prcs,
			obj->flags & ZERO_F ? '0' : ' ',
			0);
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
		print_padding(obj, str_length, ' ', 0);
	}
	else
	{
		print_padding(obj, str_length, (obj->flags & ZERO_F) ? '0' : ' ', 0);
		obj->spc == 's' ? print_string(obj) : print_character(obj->spc, obj);
	}
}

void	print_f(t_pf_object *obj)
{
	int			base;
	long long	ret;
	long double	copy;

	parse_length(obj, 0);
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
