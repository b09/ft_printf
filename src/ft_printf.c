/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/11/19 21:46:44 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"
// %[flags]     [width]             [precision]             [length]    [specifier]
// %[#,0,-, ,+] [1,2,3,4,5,6,7,8,9] [.,0,1,2,3,4,5,6,7,8,9] [h,hh,l,ll] [c,s,p,d,i,o,u,x,X,f,%]
char	get_base(char format_specifier)
{
	char			base;

	base = 0;
	base = format_specifier == 'd' ? 10 : base;
	base = format_specifier == 'i' ? 10 : base;
	base = format_specifier == 'x' ? 16 : base;
	base = format_specifier == 'X' ? 16 : base;
	base = format_specifier == 'o' ? 8 : base;
	base = format_specifier == 'u' ? 10 : base;
	base = format_specifier == 'p' ? 16 : base;
	return (base);
}
// this fuction will not work for unsigned long long variables
int		length_of_number(t_pf_object *obj)
{
	long long		original_int;
	long long		holder;
	int				counter;
	char			base;

	base = get_base(obj->specifier);
	counter = 1;
	original_int = obj->val.lnglng;
	if (original_int < 0)
		original_int = -original_int;
	while (original_int > (base - 1))
	{
		original_int /= base;
		++counter;
	}
	counter += (obj->flags & HASH_F) ? 1 : 0;
	counter += (obj->flags & HASH_F && (obj->specifier == 'x' 
				|| obj->specifier == 'p' || obj->specifier == 'X')) ? 1 : 0;
	return (counter);
}

int		ft_printf(const char* restrict format, ...)
{
	t_pf_object		obj;

	ft_bzero(&obj, sizeof(obj));
	obj.str = format;
	va_start(obj.ap, format);
	while (obj.str[obj.i_str] != 0)
	{
		if (obj.str[obj.i_str] == '%')
		{
			++obj.i_str;
			parse_general(&obj);
		}
		if (ft_strlen(obj.str) > obj.i_str)
		{
			obj.i_str++;
			print_character(obj.str[obj.i_str], &obj);
		}
	}
	va_end(obj.ap);
	return (obj.ret);
}
