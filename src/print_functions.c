/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:07:25 by bprado         #+#    #+#                */
/*   Updated: 2019/11/05 15:47:20 by bprado        ########   odam.nl         */
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

void	print_padding(t_pf_object *obj, int length_of_output, char character)
{
	int		length_to_print;

	length_to_print = obj->width - length_of_output;
	if (obj->flags & PLUS_F && length_to_print > 0)
		--length_to_print;
	while (0 < length_to_print--)
		print_character(character, obj);
}

void	print_character(char c, t_pf_object *obj)
{
	obj->ret++;
	ft_putchar(c);
}
