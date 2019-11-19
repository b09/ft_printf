/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:18:01 by bprado         #+#    #+#                */
/*   Updated: 2019/11/19 22:22:41 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

/*
	prcs overides width. if both are given and are equal, prcs prevails.
	that said, width with '-' will need to consider prcs. "%-+7.5" >> "+00100 "
 */
void	print_d(t_pf_object *obj)
{
	obj->val.lnglng = va_arg(obj->ap, int);
	parse_length(obj, 0);
	obj->i = length_of_number(obj);
	if (obj->flags & MINUS_F)
	{
		(obj->flags & PLUS_F || obj->flags & SPACE_F) ? print_sign(obj) : 0;
		print_padding(obj, obj->i, '0', 1);
		ft_putnbr_base2(obj->val.lnglng, 10, obj);
		obj->i = (obj->i > obj->prcs) ? obj->i : obj->prcs;
		print_padding(obj, obj->i, ' ', 0);
	}
	else if (obj->flags & ZERO_F)
	{
		(obj->flags & SIGNED_F || obj->flags & SPACE_F) ? print_sign(obj) : 0;
		print_padding(obj, (obj->i > obj->prcs) ? obj->i : obj->prcs, '0', 0);
		print_padding(obj, obj->i, '0', 1);
		ft_putnbr_base2(obj->val.lnglng, 10, obj);
	}
	else
	{
		print_sign(obj);
		print_padding(obj, (obj->i > obj->prcs) ? obj->i : obj->prcs, ' ', 0);
		print_padding(obj, obj->i, '0', 1);
		ft_putnbr_base2(obj->val.lnglng, 10, obj);
	}
}

void	invalid_format(t_pf_object *obj)
{
	ft_putstr("Not a valid format\n");
}

void	print_char(t_pf_object *obj)
{
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		print_character(va_arg(obj->ap, int), obj);
		print_padding(obj, 1, ' ', 0);
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, 1, '0', 0);
		print_character(va_arg(obj->ap, int), obj);
	}
	else
	{
		print_padding(obj, 1, ' ', 0);
		print_character(va_arg(obj->ap, int), obj);
	}
}

void	print_str(t_pf_object *obj)
{
	int			str_length;

	obj->val.ptr = va_arg(obj->ap, char*);
	str_length = obj->prcs < ft_strlen(obj->val.ptr) && obj->flags & PRECISN ?
									obj->prcs : ft_strlen(obj->val.ptr);
	obj->flags |= STRNG;
	if (obj->flags & MINUS_F)
	{
		print_string(obj);
		print_padding(obj, str_length, ' ', 0);
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, str_length, '0', 0);
		print_string(obj);
	}
	else
	{
		print_padding(obj, str_length, ' ', 0);
		print_string(obj);
	}
}

void	print_ptr(t_pf_object *obj)
{
	long long	pointer;
	int			base;

	base = 16;
	obj->val.ptr = va_arg(obj->ap, void*);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		print_hash_flag(obj);
		ft_putnbr_base2(obj->val.lnglng, base, obj);
		print_padding(obj, length_of_number(obj), ' ', 0);
	}
	else if (obj->flags & ZERO_F)
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj), '0', 0);
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
	else
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj), ' ', 0);
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
}

void	print_o(t_pf_object *obj)
{
	int			base;

	obj->val.lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		(obj->flags & HASH_F) ? print_hash_flag(obj) : 0;
		ft_putnbr_base2(obj->val.lnglng, 8, obj);
		print_padding(obj, length_of_number(obj), ' ', 0);
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj), '0', 0);
		ft_putnbr_base2(obj->val.lnglng, 8, obj);
	}
	else
	{
		print_padding(obj, length_of_number(obj), ' ', 0);
		ft_putnbr_base2(obj->val.lnglng, 8, obj);
	}
}

void	print_u(t_pf_object *obj)
{
	int			base;

	base = 10;
	obj->val.lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		ft_putnbr_base2(obj->val.lnglng, base, obj);
		print_padding(obj, length_of_number(obj), ' ', 0);
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj), '0', 0);
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
	else
	{
		print_padding(obj, length_of_number(obj), ' ', 0);
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
}

void	print_x(t_pf_object *obj)
{
	int			base;

	base = 16;
	obj->val.lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		if (obj->flags & HASH_F)
			print_hash_flag(obj);
		ft_putnbr_base2(obj->val.lnglng, base, obj);
		print_padding(obj, length_of_number(obj), ' ', 0);
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj), '0', 0);
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
	else
	{
		print_padding(obj, length_of_number(obj), ' ', 0);
		ft_putnbr_base2(obj->val.lnglng, base, obj);
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

void	print_percent(t_pf_object *obj)
{
	print_character('%', obj);
}
