/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:07:25 by bprado         #+#    #+#                */
/*   Updated: 2019/12/11 21:44:54 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			print_sign(t_pf_sect *s)
{
	if (s->spc != 'c')
	{
		if (((s->fl & PLUS || s->fl & SIGNED_F) &&
					!(s->fl & SPACE)) || s->v.llong < 0)
		{
			if ((long long)s->v.ll >= 0 && s->fl & PLUS)
				print_character('+', s);
			else if ((long long)s->v.ll < 0)
				print_character('-', s);
		}
		else if (s->fl & SPACE)
			print_character(' ', s);
		s->fl |= PRTSIGN;
	}
}

void			sign_float(t_pf_sect *s)
{
	if (((s->fl & PLUS) && !(s->fl & SPACE)) || s->v.lngd < 0)
	{
		if (s->v.lngd >= 0 && s->fl & PLUS)
			print_character('+', s);
		else if (s->v.lngd < 0)
			print_character('-', s);
	}
	else if (s->fl & SPACE)
		print_character(' ', s);
}

void			print_hash_flag(t_pf_sect *s)
{
	if ((s->v.ll != 0 && s->fl & HASH) || s->spc == 'p')
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
	s->fl |= PRTSIGN;
}

static void		print_padding2(t_pf_sect *s, int padd, char character)
{
	if (s->v.ll != 0)
	{
		padd += s->spc == 'p' && character == ' ' && s->prcs >= s->i ? -2 : 0;
		padd += s->spc == 'p' && character == '0' && s->prcs >= s->i ? 2 : 0;
		padd += s->spc == 'x' && character == ' ' && (s->fl & HASH) &&
													s->prcs >= s->i ? -2 : 0;
		padd += s->spc == 'x' && character == '0' && (s->fl & HASH) &&
													s->prcs >= s->i ? 2 : 0;
		padd += s->spc == 'X' && character == ' ' && (s->fl & HASH) &&
													s->prcs >= s->i ? -2 : 0;
		padd += s->spc == 'X' && character == '0' && (s->fl & HASH) &&
													s->prcs >= s->i ? 2 : 0;
	}
	while (padd > 0)
	{
		print_character(character, s);
		padd--;
	}
}

void			print_padding(t_pf_sect *s, int length, char chr, char flip)
{
	int		padd;

	padd = 0;
	if (flip)
	{
		padd = s->prcs - length;
		if (s->fl & SIGNED_F && s->v.llong < 0)
			++padd;
		padd = s->spc == 'c' && s->v.ll == 0 ? 0 : padd;
	}
	else
	{
		padd = s->width - length;
		if ((s->fl & SIGNED_F && chr == ' ') && ((s->v.llong >= 0 &&
					s->fl & 0x18) || (s->v.llong < 0 && s->prcs >= s->i)))
			--padd;
		else if (s->fl & SIGNED_F && chr == '0' &&
		(s->fl & (PLUS | SPACE)) && s->v.llong >= 0)
			--padd;
	}
	print_padding2(s, padd, chr);
}

void			print_string(t_pf_sect *s)
{
	char	*str;

	str = "(null)";
	if (s->spc == 's' && s->v.ptr == 0)
	{
		while (*str)
			print_character(*str++, s);
		return ;
	}
	if (s->spc == 's' && s->fl & PRECISN)
	{
		while (*(char*)s->v.ptr && s->prcs-- > 0)
			print_character(*(char*)s->v.ptr++, s);
	}
	else if (s->spc == 's')
	{
		while (*(char*)s->v.ptr)
			print_character(*(char*)s->v.ptr++, s);
	}
	else
	{
		while (*(char*)s->v.ptr)
			print_character(*(char*)s->v.ptr++, s);
	}
}
