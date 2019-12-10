/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 19:16:18 by bprado         #+#    #+#                */
/*   Updated: 2019/12/10 12:47:45 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_length(t_pf_sect *s)
{
	union_output i;

	i.ll = 0;
	if (ft_strchr("cdi", s->spc))
	{
		// specifier 'c' must be properly tested
		i.llong = s->flags & LL_F ? va_arg(s->ap, long long) : i.llong;
		i.llong = s->flags & L_F ? va_arg(s->ap, long) : i.llong;
		i.llong = (s->flags & 0x140) == 0 ? va_arg(s->ap, int) : i.llong;
		i.llong = s->flags & H_F ? (short)i.llong : i.llong;
		i.llong = s->flags & HH_F ? (char)i.llong : i.llong;
		s->val.llong = i.llong;
	}
	if (ft_strchr("ouxX", s->spc))
	{
		i.ll = s->flags & LL_F ? va_arg(s->ap, u_int64_t) : i.ll;
		i.ll = s->flags & L_F ? va_arg(s->ap, unsigned long) : i.ll;
		i.ll = (s->flags & 0x140) == 0 ? va_arg(s->ap, unsigned int) : i.ll;
		i.ll = s->flags & H_F ? (unsigned short)i.ll : i.ll;
		i.ll = s->flags & HH_F ? (unsigned char)i.ll : i.ll;
		s->val.ll = i.ll;
	}
}

void	parse_specifier(func_pointer arrpointer[128])
{
	int				i;

	i = 0;
	while (i < 128)
		arrpointer[i++] = print_str;
	arrpointer['s'] = print_str;
	arrpointer['c'] = print_dioupxxc;
	arrpointer['p'] = print_dioupxxc;
	arrpointer['d'] = print_dioupxxc;
	arrpointer['i'] = print_dioupxxc;
	arrpointer['o'] = print_dioupxxc;
	arrpointer['u'] = print_dioupxxc;
	arrpointer['x'] = print_dioupxxc;
	arrpointer['X'] = print_dioupxxc;
	arrpointer['f'] = print_f;
}

void	parse_flags(t_pf_sect *s)
{
	while (ft_strchr_int("#0- +", s->str[s->i_str]) != -1)
	{
		s->flags |= 1 << ft_strchr_int("#0- +", s->str[s->i_str]);
		++s->i_str;
	}
	s->flags ^= ((s->flags & 0x6) == 0x6) ? ZERO_F : 0;
	s->flags ^= ((s->flags & 0x18) == 0x18) ? SPACE_F : 0;
}

void	parse_width_precision(t_pf_sect *s)
{
	s->width = ft_atoi(&(s->str[s->i_str]));
	s->width = s->str[s->i_str] == '*' ? va_arg(s->ap, int) : s->width;
	s->flags |= s->width < 0 ? MINUS_F : 0;
	s->width = s->width < 0 ? -(s->width) : s->width;
	s->flags |= s->width ? WIDTH : 0;
	while (ft_isdigit(s->str[s->i_str]))
		++s->i_str;
	s->i_str += s->str[s->i_str] == '*' ? 1 : 0;
	if (s->str[s->i_str] == '.')
	{
		s->i_str++;
		s->flags |= PRECISN;
		s->prcs = ft_atoi(&(s->str[s->i_str]));
		s->prcs = s->str[s->i_str] == '*' ? va_arg(s->ap, int) : s->prcs;
		while (ft_isdigit(s->str[s->i_str]))
			++s->i_str;
		s->i_str += s->str[s->i_str] == '*' ? 1 : 0;
	}
}

void	parse_general(t_pf_sect *s)
{
	parse_flags(s);
	parse_width_precision(s);
	if (s->str[s->i_str] == 'l')
		s->flags |= (s->str[s->i_str + 1] == 'l') ? LL_F : L_F;
	if (s->str[s->i_str] == 'h')
		s->flags |= (s->str[s->i_str + 1] == 'h') ? HH_F : H_F;
	if (s->str[s->i_str] && s->str[s->i_str] == 'L')
		s->flags |= CAP_L_F;
	s->i_str += s->flags & 0x180 ? 2 : 0;
	s->i_str += s->flags & 0x460 ? 1 : 0;
	s->spc = s->str[s->i_str];
	if (s->spc == 'i' || s->spc == 'd')
		s->flags |= SIGNED_F;
}
