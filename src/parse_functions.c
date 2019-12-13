/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 19:16:18 by bprado         #+#    #+#                */
/*   Updated: 2019/12/13 21:05:08 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			parse_length(t_pf_sect *s)
{
	union_output i;

	i.ll = 0;
	if (ft_strchr("cdi", s->spc))
	{
		i.llong = s->fl & LL_F ? va_arg(s->ap, long long) : i.llong;
		i.llong = s->fl & L_F ? va_arg(s->ap, long) : i.llong;
		i.llong = (s->fl & 0x140) == 0 ? va_arg(s->ap, int) : i.llong;
		i.llong = s->fl & H_F ? (short)i.llong : i.llong;
		i.llong = s->fl & HH_F ? (char)i.llong : i.llong;
		s->v.llong = i.llong;
	}
	if (ft_strchr("bouxX", s->spc))
	{
		i.ll = s->fl & LL_F ? va_arg(s->ap, u_int64_t) : i.ll;
		i.ll = s->fl & L_F ? va_arg(s->ap, unsigned long) : i.ll;
		i.ll = (s->fl & 0x140) == 0 ? va_arg(s->ap, unsigned int) : i.ll;
		i.ll = s->fl & H_F ? (unsigned short)i.ll : i.ll;
		i.ll = s->fl & HH_F ? (unsigned char)i.ll : i.ll;
		s->v.ll = i.ll;
	}
}

void			parse_specifier(func_pointer arrpointer[128])
{
	int				i;

	i = 0;
	while (i < 128)
	{
		arrpointer[i] = print_str;
		++i;
	}
	arrpointer['s'] = print_str;
	arrpointer['c'] = print_dioupxxc;
	arrpointer['b'] = print_dioupxxc;
	arrpointer['p'] = print_dioupxxc;
	arrpointer['d'] = print_dioupxxc;
	arrpointer['i'] = print_dioupxxc;
	arrpointer['o'] = print_dioupxxc;
	arrpointer['u'] = print_dioupxxc;
	arrpointer['x'] = print_dioupxxc;
	arrpointer['X'] = print_dioupxxc;
	arrpointer['n'] = print_n;
	arrpointer['f'] = print_f;
}

static void		parse_flags(t_pf_sect *s)
{
	while (ft_strchr_int("#0- +", s->str[s->i_str]) != -1)
	{
		s->fl |= 1 << ft_strchr_int("#0- +", s->str[s->i_str]);
		++s->i_str;
	}
	s->fl ^= ((s->fl & 0x6) == 0x6) ? ZERO_F : 0;
	s->fl ^= ((s->fl & 0x18) == 0x18) ? SPACE : 0;
}

static void		parse_width_precision(t_pf_sect *s)
{
	s->width = ft_atoi(&(s->str[s->i_str]));
	s->width = s->str[s->i_str] == '*' ? va_arg(s->ap, int) : s->width;
	s->fl |= s->width < 0 ? MINUS_F : 0;
	s->width = s->width < 0 ? -(s->width) : s->width;
	s->fl |= s->width ? WIDTH : 0;
	while (ft_isdigit(s->str[s->i_str]))
		++s->i_str;
	s->i_str += s->str[s->i_str] == '*' ? 1 : 0;
	if (s->str[s->i_str] == '.')
	{
		s->i_str++;
		s->fl |= PRECISN;
		s->prcs = ft_atoi(&(s->str[s->i_str]));
		s->prcs = s->str[s->i_str] == '*' ? va_arg(s->ap, int) : s->prcs;
		while (ft_isdigit(s->str[s->i_str]))
			++s->i_str;
		s->i_str += s->str[s->i_str] == '*' ? 1 : 0;
	}
}

void			parse_general(t_pf_sect *s)
{
	parse_flags(s);
	parse_width_precision(s);
	if (s->str[s->i_str] == 'l')
		s->fl |= (s->str[s->i_str + 1] == 'l') ? LL_F : L_F;
	if (s->str[s->i_str] == 'h')
		s->fl |= (s->str[s->i_str + 1] == 'h') ? HH_F : H_F;
	if (s->str[s->i_str] && s->str[s->i_str] == 'L')
		s->fl |= CAP_L_F;
	s->i_str += s->fl & 0x180 ? 2 : 0;
	s->i_str += s->fl & 0x460 ? 1 : 0;
	s->spc = s->str[s->i_str];
	if (s->spc == 'i' || s->spc == 'd')
		s->fl |= SIGNED_F;
}
