/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:07:25 by bprado         #+#    #+#                */
/*   Updated: 2019/11/20 21:39:45 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_sign(t_pf_object *obj)
{
	if (obj->flags & PLUS_F || obj->flags & SIGNED_F)
	{
		if ((long long)obj->val.ll >= 0 && obj->flags & PLUS_F)
			print_character('+', obj);
		else if ((long long)obj->val.ll < 0)
			print_character('-', obj);
	}
	else if (obj->flags & SPACE_F)
		print_character(' ', obj);
}

void	print_hash_flag(t_pf_object *obj)
{
	if (obj->spc == 'o')
		print_character('0', obj);
	else if (obj->spc == 'x' || obj->spc == 'p')
	{
		print_character('0', obj);
		print_character('x', obj);
	}
	else if (obj->spc == 'X')
	{
		print_character('0', obj);
		print_character('X', obj);
	}
	else if (obj->spc == 'f')
		print_character('.', obj);
}

void	print_padding(t_pf_object *obj, int length, char character, char flip)
{
	int		padding_to_print;

	if (flip)
		padding_to_print = obj->prcs - length;
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
		while (*(char*)obj->val.ptr && obj->prcs-- > 0)
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
