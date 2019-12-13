/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   number_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 21:07:04 by bprado         #+#    #+#                */
/*   Updated: 2019/12/12 23:24:11 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			get_base(char format_spc)
{
	char			base;

	base = 0;
	base = format_spc == 'd' ? 10 : base;
	base = format_spc == 'b' ? 2 : base;
	base = format_spc == 'i' ? 10 : base;
	base = format_spc == 'f' ? 10 : base;
	base = format_spc == 'x' ? 16 : base;
	base = format_spc == 'X' ? 16 : base;
	base = format_spc == 'o' ? 8 : base;
	base = format_spc == 'u' ? 10 : base;
	base = format_spc == 'p' ? 16 : base;
	return (base);
}

int				length_of_number(t_pf_sect *s)
{
	long long		original_int;
	int				counter;
	char			base;

	base = get_base(s->spc);
	counter = 1;
	original_int = s->v.llong;
	if (original_int < 0)
		original_int = -original_int;
	while ((base > 0) && original_int > (base - 1))
	{
		original_int /= base;
		++counter;
	}
	if ((s->fl & SIGNED_F) && s->v.llong < 0)
		counter++;
	counter = (!s->v.llong && s->fl & PRECISN && !s->prcs) ? 0 : counter;
	return (counter);
}

int				length_of_unsigned(t_pf_sect *s)
{
	u_int64_t		original_int;
	int				counter;
	u_int8_t		base;

	base = get_base(s->spc);
	counter = 1;
	original_int = s->v.ll;
	while ((base > 0) && original_int > (base - 1))
	{
		original_int /= base;
		++counter;
	}
	if ((s->fl & HASH) && s->spc != 'o' && s->v.ll != 0)
		counter += 2;
	else if (s->spc == 'p')
		counter += 2;
	counter = (!s->v.ll && s->fl & PRECISN && !s->prcs) ? 0 : counter;
	if (s->fl & HASH && s->spc == 'o' && s->v.ll != 0)
		counter += 1;
	else if (s->fl & HASH && s->spc == 'o' && s->v.ll == 0)
		counter = 1;
	return (counter);
}

static void		putnbr_signed_exception(t_pf_sect *s)
{
	char			*stupidasslongnumber;

	stupidasslongnumber = "9223372036854775808";
	if (s->v.llong == -9223372036854775807 - 1)
	{
		s->v.ptr = stupidasslongnumber;
		print_string(s);
		return ;
	}
}

void			ft_putnbr_signed(long long n, int base, t_pf_sect *s)
{
	char			a;
	int64_t			i;

	a = 0;
	if ((s->v.llong == 0 && ((s->fl & PRECISN && s->prcs == 0) ||
	s->spc == 'c')) || (s->v.llong == -9223372036854775807 - 1))
		return (putnbr_signed_exception(s));
	if (n < 0)
		n = -n;
	i = n;
	if (i > (base - 1))
	{
		ft_putnbr_signed(i / base, base, s);
		ft_putnbr_signed(i % base, base, s);
	}
	if (i <= (base - 1) && i < 10)
	{
		a = '0' + i;
		print_character(a, s);
	}
	else if (i > 9 && i < 16 && base > 10)
	{
		a = s->spc != 'X' ? 'a' + i - 10 : 'A' + i - 10;
		print_character(a, s);
	}
}

void			ft_putnbr_unsigned(u_int64_t i, int base, t_pf_sect *s)
{
	u_int8_t		a;

	a = 0;
	if ((s->v.ll == 0 && (s->fl & PRECISN) && s->prcs == 0 &&
	s->spc != 'o') || (s->v.ll == 0 && (s->fl & PRECISN) &&
	s->prcs == 0 && s->spc == 'o' && !(s->fl & HASH)))
		return ;
	if (i > ((unsigned)base - 1))
	{
		ft_putnbr_unsigned(i / base, base, s);
		ft_putnbr_unsigned(i % base, base, s);
	}
	if (i <= ((unsigned)base - 1) && i < 10)
	{
		a = '0' + i;
		print_character(a, s);
	}
	else if (i > 9 && i < 16 && base > 10)
	{
		a = s->spc != 'X' ? 'a' + i - 10 : 'A' + i - 10;
		print_character(a, s);
	}
}
