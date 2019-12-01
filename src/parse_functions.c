/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 19:16:18 by bprado         #+#    #+#                */
/*   Updated: 2019/12/01 16:53:43 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_length(t_pf_object *obj)
{
	union_output i;

	i.ll = 0;
	if (ft_strchr("cdi", obj->spc))
	{
		// specifier 'c' must be properly tested
		i.ll = obj->flags & LL_F ? va_arg(obj->ap, long long) : i.ll;
		i.ll = obj->flags & L_F ? va_arg(obj->ap, long) : i.ll;
		i.ll = (obj->flags & 0x140) == 0 ? va_arg(obj->ap, int) : i.ll;
		i.ll = obj->flags & H_F ? (short)i.ll : i.ll;
		i.ll = obj->flags & HH_F ? (char)i.ll : i.ll;
	}
	if (ft_strchr("ouxX", obj->spc))
	{
		i.ll = obj->flags & LL_F ? va_arg(obj->ap, unsigned long long) : i.ll;
		i.ll = obj->flags & L_F ? va_arg(obj->ap, unsigned long) : i.ll;
		i.ll = (obj->flags & 0x140) == 0 ? va_arg(obj->ap, unsigned int) : i.ll;
		i.ll = obj->flags & H_F ? (unsigned short)i.ll : i.ll;
		i.ll = obj->flags & HH_F ? (unsigned char)i.ll : i.ll;
	}
	obj->val.ll = i.ll;
	if (obj->spc == 'f')
		obj->val.lngdbl = va_arg(obj->ap, long double);
	if (obj->flags & CAP_L_F && obj->spc == 'f')
		obj->val.lngdbl = (float)obj->val.lngdbl;
}

void	parse_specifier(t_pf_object *obj)
{
	int				i;
	func_pointer	arrpointer[128];

	i = 0;
	while (i < 128)
		arrpointer[i++] = print_str;
	arrpointer['c'] = print_d;
	arrpointer['s'] = print_str;
	arrpointer['p'] = print_o;
	arrpointer['d'] = print_d;
	arrpointer['i'] = print_d;
	arrpointer['o'] = print_o;
	arrpointer['u'] = print_o;
	arrpointer['x'] = print_o;
	arrpointer['X'] = print_o;
	arrpointer['f'] = print_f;
	obj->spc = obj->str[obj->i_str];
	if (obj->spc == 'd' || obj->spc == 'i')
		obj->flags |= SIGNED_F;
	arrpointer[(int)obj->spc](obj);
	obj->i_str++;
}

void	parse_general(t_pf_object *obj)
{
	while (ft_strchr_int("#0- +", obj->str[obj->i_str]) != -1)
		obj->flags |= 1 << ft_strchr_int("#0- +", obj->str[obj->i_str++]);
	obj->flags ^= ((obj->flags & 0x6) == 0x6) ? ZERO_F : 0;
	obj->flags ^= ((obj->flags & 0x18) == 0x18) ? SPACE_F : 0;
	obj->width = ft_atoi(&(obj->str[obj->i_str]));
	obj->flags |= obj->width ? WIDTH : 0;
	while (ft_isdigit(obj->str[obj->i_str]))
		++obj->i_str;
	if (obj->str[obj->i_str] == '.')
	{
		obj->i_str++;
		obj->flags |= PRECISN;
		obj->prcs = ft_atoi(&(obj->str[obj->i_str]));
		while (ft_isdigit(obj->str[obj->i_str]))
			++obj->i_str;
	}
	if (obj->str[obj->i_str] == 'l')
		obj->flags |= (obj->str[obj->i_str + 1] == 'l') ? LL_F : L_F;
	if (obj->str[obj->i_str] == 'h')
		obj->flags |= (obj->str[obj->i_str + 1] == 'h') ? HH_F : H_F;
	if (obj->str[obj->i_str] && obj->str[obj->i_str] == 'L')
		obj->flags |= CAP_L_F;
	obj->i_str += obj->flags & 0x180 ? 2 : 0;
	obj->i_str += obj->flags & 0x460 ? 1 : 0;
}
