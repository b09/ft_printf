/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/03 19:16:18 by bprado         #+#    #+#                */
/*   Updated: 2019/11/14 18:26:41 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	parse_flags(t_pf_object *obj)
{
	while (ft_strchr_int("#0- +", obj->str[obj->i_str]) != -1)
		obj->flags |= 1 << ft_strchr_int("#0- +", obj->str[obj->i_str++]);


		
	if (obj->flags & ZERO_F && obj->flags & MINUS_F)
		obj->flags ^= ZERO_F;
	if (obj->flags & SPACE_F && obj->flags & PLUS_F)
		obj->flags ^= SPACE_F;
}

void	parse_width_precision(t_pf_object *obj)
{
	obj->width = ft_atoi(&(obj->str[obj->i_str]));
	while (ft_isdigit(obj->str[obj->i_str]))
		++obj->i_str;
	if (obj->str[obj->i_str] == '.')
	{
		obj->i_str++;
		obj->flags |= PRECISN;
		obj->precision = ft_atoi(&(obj->str[obj->i_str]));
		obj->precision = obj->precision > 0 ? obj->precision : -1;
		while (ft_isdigit(obj->str[obj->i_str]))
			++obj->i_str;
	}
}

void	parse_length(t_pf_object *obj, char flip)
{
	if (flip)
	{
		if (obj->str[obj->i_str] == 'l')
		{
			obj->flags |= (obj->str[obj->i_str + 1] == 'l') ? LL_F : L_F;
			obj->i_str += (obj->str[obj->i_str + 1] == 'l') ? 2 : 1;
		}
		if (obj->str[obj->i_str] == 'h')
		{
			obj->flags |= (obj->str[obj->i_str + 1] == 'h') ? HH_F : H_F;
			obj->i_str += (obj->str[obj->i_str + 1] == 'h') ? 2 : 1;
		}
		if (obj->str[obj->i_str] == 'L')
		{
			obj->flags |= CAP_L_F;
			obj->i_str++;
		}
	}
	else
	{
		obj->val.lnglng = obj->flags & H_F ? (short)obj->val.lnglng : obj->val.lnglng;
		obj->val.lnglng = obj->flags & HH_F ? (unsigned char)obj->val.lnglng : obj->val.lnglng;
		obj->val.lnglng = obj->flags & L_F ? (long)obj->val.lnglng : obj->val.lnglng;
		obj->val.lnglng = obj->flags & LL_F ? (long long)obj->val.lnglng : obj->val.lnglng;
		if (obj->flags & CAP_L_F)
			obj->val.lngdbl = (long double)obj->val.lnglng;
	}
}
