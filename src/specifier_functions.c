/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:18:01 by bprado         #+#    #+#                */
/*   Updated: 2019/12/09 13:33:53 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	print_dioupxxc(t_pf_sect *s)
{
	int		i;

	i = ft_strchr_int("idc", s->spc);
	if (s->spc == 'p')
		s->val.ptr = va_arg(s->ap, void*);
	else
		parse_length(s);
	s->i = i > -1 ? length_of_number(s) : length_of_unsigned(s);
	if (s->flags & MINUS_F)
	{
		if (i > -1 || (s->flags & HASH_F && s->spc != 'u') || s->spc == 'p')
			i > -1 ? print_sign(s) : print_hash_flag(s);
		print_padding(s, s->i, '0', 1);
		if (s->spc != 'c')
			i > -1 ? ft_putnbr_signed(s->val.llong, get_base(s->spc), s) :
					ft_putnbr_unsigned(s->val.ll, get_base(s->spc), s);
		else if (s->spc == 'c')
			print_character(s->val.llong, s);
		print_padding(s, (s->i > s->prcs) ? s->i : s->prcs, ' ', 0);
	}
	else
		no_minus_flag(s);
}

void	print_str(t_pf_sect *s)
{
	int			str_length;

	str_length = 0;
	if (s->spc == 's')
	{
		s->val.ptr = va_arg(s->ap, char*);
		if (!s->val.ptr)
			s->val.ptr = "(null)";
		str_length = s->prcs < (int)ft_strlen(s->val.ptr) && s->flags & PRECISN ?
										s->prcs : ft_strlen(s->val.ptr);
		s->flags |= STRNG;
	}
	if (s->flags & MINUS_F)
	{
		s->spc == 's' ? print_string(s) : print_character(s->spc, s);
		print_padding(s, s->spc == 's' ? str_length : 1, ' ', 0);
	}
	else
	{
		print_padding(s, 
			s->spc == 's' ? str_length : 1,
			(s->flags & ZERO_F) ? '0' : ' ',
			0);
		s->spc == 's' ? print_string(s) : print_character(s->spc, s);
	}
}

void	print_f(t_pf_sect *s)
{
	long double	copy;

	// parse_length(s);
	copy = (s->flags & CAP_L_F) ? va_arg(s->ap, long double) : va_arg(s->ap, double);
	s->val.lngdbl = copy;
	s->prcs = !(s->flags & PRECISN) ? 6 : s->prcs;
	s->i = length_of_float(s);		// must implement correctly, ie. what is the length of a float
	if (s->flags & MINUS_F)
	{
		print_sign_float(s);
		putfloat(s, s->prcs + 1, 0);
		print_padding(s, (s->i > s->prcs) ? s->i : s->prcs, ' ', 0);
	}
	else
	{
		s->i >= s->width || s->prcs >= s->width || s->flags & ZERO_F ? print_sign_float(s) : 0;
		if (s->width > s->prcs && s->flags & PRECISN)
			print_padding(s, s->i > s->prcs ? s->i : s->prcs, ' ', 0);
		else
			print_padding(s, s->i, s->flags & ZERO_F ? '0' : ' ', 0);
		!(s->flags & ZERO_F) && s->i < s->width ? print_sign_float(s) : 0;
		if ((s->flags & ZERO_F) || s->width > s->i)
			print_padding(s, s->i, '0', 1);
		putfloat(s, s->prcs + 1, 0);
	}
}

void	no_minus_flag(t_pf_sect *s)
{
	int		i;

	i = ft_strchr_int("idc", s->spc);

	if (s->i >= s->width || s->prcs >= s->width ||
						(!(s->flags & PRECISN) && s->flags & ZERO_F)) 
		i > -1 ? print_sign(s) : print_hash_flag(s);
	if (s->width > s->prcs && s->flags & PRECISN)
		print_padding(s, s->i > s->prcs ? s->i : s->prcs, ' ', 0);
	else
		print_padding(s, s->i > s->prcs ? s->i : s->prcs,
										s->flags & ZERO_F ? '0' : ' ', 0);
	if (!(s->flags & PRTSIGN))
		i > -1 ? print_sign(s) : print_hash_flag(s);
	if ((s->flags & ZERO_F) || s->prcs >= s->i)
		print_padding(s, s->i, s->spc != 'c' ? '0' : ' ', 1);
	if (s->spc != 'c') 
		i > -1 ? ft_putnbr_signed(s->val.llong, get_base(s->spc), s) :
					ft_putnbr_unsigned(s->val.ll, get_base(s->spc), s);
	else if (s->spc == 'c')
		print_character(s->val.ll, s);
}
