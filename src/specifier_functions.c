/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:18:01 by bprado         #+#    #+#                */
/*   Updated: 2019/11/05 19:58:00 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_d(t_pf_object *obj)
{
	int			base;

	base = 10;
	obj->val.lnglng = va_arg(obj->ap, int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		if (obj->flags & PLUS_F)
			print_sign(obj);
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		if (obj->flags & SIGNED_F)
			print_sign(obj);
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_sign(obj);
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	invalid_format(t_pf_object *obj)
{
	ft_putstr("Not a valid format\n");
}

void	print_char(t_pf_object *obj)
{
	if (obj->flags & MINUS_F)
	{
		print_character(va_arg(obj->ap, int), obj);
		print_padding(obj, 1, ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, 1, '0');
		print_character(va_arg(obj->ap, int), obj);
	}
	else
	{
		print_padding(obj, 1, ' ');
		print_character(va_arg(obj->ap, int), obj);
	}
}

void	print_str(t_pf_object *obj)
{
	char		*str;

	str = va_arg(obj->ap, char*);
	if (obj->flags & MINUS_F)
	{
		ft_putstr(str);
		print_padding(obj, ft_strlen(str), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, ft_strlen(str), '0');
		ft_putstr(str);
	}
	else
	{
		print_padding(obj, ft_strlen(str), ' ');
		ft_putstr(str);
	}
}

void	print_ptr(t_pf_object *obj)
{
	long long	pointer;
	int			base;

	base = 16;
	pointer = va_arg(obj->ap, void*);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		print_hash_flag(obj);
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	print_o(t_pf_object *obj)
{
	int			base;

	base = 8;
	obj->val.lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		if (obj->flags & HASH_F)
			print_hash_flag(obj);
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
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
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
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
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	print_f(t_pf_object *obj)
{
		int			base;

	base = 16;
	obj->val.lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		if (obj->flags & HASH_F)
			print_hash_flag(obj);
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	print_percent(t_pf_object *obj)
{
	print_character('%', obj);
}
