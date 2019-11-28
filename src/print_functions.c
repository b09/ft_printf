/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:07:25 by bprado         #+#    #+#                */
/*   Updated: 2019/11/28 22:11:41 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sign(t_pf_object *obj)
{
	if (((obj->flags & PLUS_F || obj->flags & SIGNED_F) && !(obj->flags & SPACE_F)) || obj->val.llong < 0)
	{
		if ((long long)obj->val.ll >= 0 && obj->flags & PLUS_F)
			print_character('+', obj);
		else if ((long long)obj->val.ll < 0)
			print_character('-', obj);
	}
	else if (obj->flags & SPACE_F && obj->spc != 'c')
		print_character(' ', obj);
}

void	print_hash_flag(t_pf_object *obj)
{
	if (obj->spc == 'o')
		print_character('0', obj);
	if (obj->val.ll != 0)
	{
		if (obj->spc == 'x' || obj->spc == 'p')
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
}













void	print_padding(t_pf_object *obj, int length, char character, char flip)
{
	int		padding_to_print;

	padding_to_print = 0;
	if (flip)
	{		
		padding_to_print = obj->prcs - length;
		// if ((obj->flags & PLUS_F && obj->flags & SIGNED_F) || (obj->flags & SIGNED_F && obj->val.llong < 0))
		if (obj->flags & SIGNED_F && obj->val.llong < 0)
			++padding_to_print;
		padding_to_print = obj->spc == 'c' && obj->val.ll == 0 ? 0 : padding_to_print;
	}
	else
	{
		padding_to_print = obj->width - length;

		if (obj->flags & SIGNED_F && character == ' ' && !(obj->flags & MINUS_F) && (obj->flags & PLUS_F || obj->flags & SPACE_F || obj->val.llong < 0))
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
	// if (c != 0)
	// {
		obj->ret++;
		ft_putchar(c);
	// }
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


