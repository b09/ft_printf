/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:07:25 by bprado         #+#    #+#                */
/*   Updated: 2019/12/10 23:12:39 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sign(t_pf_sect *s)
{
	if (s->spc != 'c')
	{
		if (((s->flags & PLUS_F || s->flags & SIGNED_F) &&
					!(s->flags & SPACE_F)) || s->val.llong < 0)
		{
			if ((long long)s->val.ll >= 0 && s->flags & PLUS_F)
				print_character('+', s);
			else if ((long long)s->val.ll < 0)
				print_character('-', s);
		}
		else if (s->flags & SPACE_F)
			print_character(' ', s);
		s->flags |= PRTSIGN;
	}
}

void	print_sign_float(t_pf_sect *s)
{
	if (((s->flags & PLUS_F) && !(s->flags & SPACE_F)) || s->val.lngdbl < 0)
	{
		if (s->val.lngdbl >= 0 && s->flags & PLUS_F)
			print_character('+', s);
		else if (s->val.lngdbl < 0)
			print_character('-', s);
	}
	else if (s->flags & SPACE_F)
		print_character(' ', s);
}

void	print_hash_flag(t_pf_sect *s)
{
	// pointers do print 0x0 for 0 conversions
	// if PRTSIGN used here, make sure pointers don't cause that to be turned on
	// if (s->val.ll != 0 && (s->flags & HASH_F || s->spc == 'p'))
	if ((s->val.ll != 0 && s->flags & HASH_F) || s->spc == 'p')
	{
		if (s->spc == 'x' || s->spc == 'p')
		{
			print_character('0', s);
			print_character('x', s);
		}
		else if (s->spc == 'X')
		{
			print_character('0', s);
			print_character('X', s);
		}
		else if (s->spc == 'o')
			print_character('0', s);
	}
	s->flags |= PRTSIGN;
}

static void		print_padding2(t_pf_sect *s, int padd, char character)
{
	if (s->val.ll != 0)
	{
		padd += s->spc == 'p' && character == ' ' && s->prcs >= s->i ? -2 : 0;
		padd += s->spc == 'p' && character == '0' && s->prcs >= s->i ? 2 : 0;

		padd += s->spc == 'x' && character == ' ' && (s->flags & HASH_F) && s->prcs >= s->i ? -2 : 0;
		padd += s->spc == 'x' && character == '0' && (s->flags & HASH_F) && s->prcs >= s->i ? 2 : 0;
		
		padd += s->spc == 'X' && character == ' ' && (s->flags & HASH_F) && s->prcs >= s->i ? -2 : 0;
		padd += s->spc == 'X' && character == '0' && (s->flags & HASH_F) && s->prcs >= s->i ? 2 : 0;
	}
	while (padd > 0)
	{
		print_character(character, s);
		padd--;
	}
}

void	print_padding(t_pf_sect *s, int length, char character, char flip)
{
	int		padd;

	padd = 0;
	if (flip)
	{		
		padd = s->prcs - length;
		if (s->flags & SIGNED_F && s->val.llong < 0)
			++padd;
		padd = s->spc == 'c' && s->val.ll == 0 ? 0 : padd;
	}
	else
	{
		padd = s->width - length;
		if ((s->flags & SIGNED_F && character == ' ') && ((s->val.llong >= 0 &&
					s->flags & 0x18) || (s->val.llong < 0 && s->prcs >= s->i)))
			--padd;
		else if (s->flags & SIGNED_F && character == '0' &&
		(s->flags & (PLUS_F | SPACE_F)) && s->val.llong >= 0)
			--padd;
	}
	print_padding2(s, padd, character);
}

void	print_string(t_pf_sect *s)
{
	char 		*str;

	str = "(null)";
	if (s->spc == 's')
	{
		if (s->val.ptr == 0)
		{
			while (*str)
				print_character(*str++, s);
			return ;
		}
		if (s->flags & PRECISN)
		{
			while (*(char*)s->val.ptr && s->prcs-- > 0)
				print_character(*(char*)s->val.ptr++, s);
		}
		else
		{
			while (*(char*)s->val.ptr)
				print_character(*(char*)s->val.ptr++, s);
		}
	}
	else
	{
		while (*(char*)s->val.ptr)
			print_character(*(char*)s->val.ptr++, s);
	}
	
}


