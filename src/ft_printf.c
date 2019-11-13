/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/11/13 22:28:46 by bprado        ########   odam.nl         */
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
int		length_of_number(t_pf_object *obj, char base)
{
	long long		original_int;
	long long		holder;
	int				counter;

	counter = 1;
	original_int = obj->val.lnglng;
	if (original_int < 0)
		original_int = -original_int;
	while (original_int > (base - 1))
	{
		original_int /= base;
		++counter;
	}
	return (counter);
}

void	parse_specifier(t_pf_object *obj)
{
	int				i;
	func_pointer	arrPointer[128];

	i = 0;
	while (i < 128)
		arrPointer[i++] = invalid_format;
	arrPointer['c'] = print_char;
	arrPointer['s'] = print_str;
	arrPointer['p'] = print_ptr;
	arrPointer['d'] = print_d;
	arrPointer['i'] = print_d;
	arrPointer['o'] = print_o;
	arrPointer['u'] = print_u;
	arrPointer['x'] = print_x;
	arrPointer['X'] = print_x;
	arrPointer['f'] = print_f;
	arrPointer['%'] = print_percent;
	i = obj->str[obj->i_str++];
	if (i == 'd' || i == 'i')
		obj->flags |= SIGNED_F;
	arrPointer[i](obj);
}

void	parse_general(t_pf_object *obj)
{
	parse_flags(obj);
	parse_width_precision(obj);
	parse_length(obj, 1);
	parse_specifier(obj);
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
			print_character(obj.str[obj.i_str++], &obj);
	}
	va_end(obj.ap);
	return (obj.ret);
}


