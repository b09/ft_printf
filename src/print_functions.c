/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:07:25 by bprado         #+#    #+#                */
/*   Updated: 2019/11/19 19:18:21 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_sign(t_pf_object *obj)
{
	if ((long long)obj->val.lnglng >= 0 && obj->flags & PLUS_F)
		print_character('+', obj);
	else if ((long long)obj->val.lnglng < 0)
		print_character('-', obj);
}

void	print_space_flag(t_pf_object *obj)
{
	if (obj->flags & SPACE_F)
		print_character(' ', obj);
}

void	print_hash_flag(t_pf_object *obj)
{
	if (obj->specifier == 'o')
		print_character('0', obj);
	else if (obj->specifier == 'x' || obj->specifier == 'p')
	{
		print_character('0', obj);
		print_character('x', obj);
	}
	else if (obj->specifier == 'X')
	{
		print_character('0', obj);
		print_character('X', obj);
	}
	else if (obj->specifier == 'f')
		print_character('.', obj);
}

void	print_padding(t_pf_object *obj, int length, char character, char flip)
{
	int		padding_to_print;

	if (flip)
		padding_to_print = obj->precision - length;
	else
	{
		padding_to_print = obj->width - length;
		if (obj->flags & PLUS_F && padding_to_print > 0)
			--padding_to_print;
	}
	while (padding_to_print > 0)
	{
		print_character(character, obj);
		padding_to_print--;
	}
}

void	print_character(char c, t_pf_object *obj)
{
	obj->ret++;
	ft_putchar(c);
}

void	print_string(t_pf_object *obj)
{
	if (obj->flags & PRECISN)
	{
		// width includes all content
		while (*(char*)obj->val.ptr && obj->precision-- > 0)
			print_character(*(char*)obj->val.ptr++, obj);
	}
	else
	{
		while (*(char*)obj->val.ptr)
			print_character(*(char*)obj->val.ptr++, obj);
	}
	
}

void	ft_putnbr_base2(long long n, int base, t_pf_object *obj)
{
	char			a;
	long long		i;

	if (n < 0)
		n = -n;
	i = n;
	if (i > (base - 1))
	{
		ft_putnbr_base2(i / base, base, obj);
		ft_putnbr_base2(i % base, base, obj);
	}
	if (i <= (base - 1) && i < 10)
	{
		a = '0' + i;
		print_character(a, obj);
	}
	else if (i > 9 && i < 16 && base > 10)
	{
		a = 'a' + i - 10;
		print_character(a, obj);
	}
}