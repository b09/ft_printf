/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 19:16:18 by bprado         #+#    #+#                */
/*   Updated: 2019/11/22 18:05:12 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
void	parse_length(t_pf_object *obj, char flip)
{
	// if (flip)
	// {
	// 	if (obj->str[obj->i_str] == 'l')
	// 		obj->flags |= (obj->str[obj->i_str + 1] == 'l') ? LL_F : L_F;
	// 	if (obj->str[obj->i_str] == 'l')
	// 		obj->i_str += (obj->str[obj->i_str + 1] == 'l') ? 2 : 1;
	// 	if (obj->str[obj->i_str] == 'h')
	// 		obj->flags |= (obj->str[obj->i_str + 1] == 'h') ? HH_F : H_F;
	// 	if (obj->str[obj->i_str] == 'h')
	// 		obj->i_str += (obj->str[obj->i_str + 1] == 'h') ? 2 : 1;
	// 	if (obj->str[obj->i_str] && obj->str[obj->i_str] == 'L')
	// 		obj->flags |= CAP_L_F;
	// }
	else if (obj->flags & 0x1E0)
	{
		obj->val.ll = obj->flags & H_F ? va_arg(obj->ap, short) : 0;
		obj->val.ll = obj->flags & HH_F ? va_arg(obj->ap, char) : 0;
		obj->val.ll = obj->flags & L_F ? (long)obj->val.ll : 0;
		obj->val.ll = obj->flags & LL_F ? (long long)obj->val.ll : 0;
		if (obj->flags & CAP_L_F)
			obj->val.lngdbl = (long double)obj->val.ll;
	}
}
		d, i			o, u, x, X
	hh	signed char		unsigned char
	h	short int		unsigned short int
	l	long int		unsigned long int
	ll	long long int	unsigned long long int
 */

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
	if (obj->flags & ZERO_F && obj->flags & MINUS_F)
		obj->flags ^= ZERO_F;
	if (obj->flags & SPACE_F && obj->flags & PLUS_F)
		obj->flags ^= SPACE_F;
	obj->width = ft_atoi(&(obj->str[obj->i_str]));
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
	parse_specifier(obj);
}
