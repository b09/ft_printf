/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/12/04 21:15:45 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// add this to library
long double		ft_pow(float a, float b)
{
	float 	c;

	c = a;
	while (b > 0)
	{
		a *= c;
		--b;
	}
	return (a);
}

	// "%%" will print_character thru print_str
	// parse_specifier will increase i_str;
int		ft_printf(const char* restrict format, ...)
{
	t_pf_object		obj;
	func_pointer	arrpointer[128];

	ft_bzero(&obj, sizeof(obj));
	obj.str = format;
	va_start(obj.ap, format);
	parse_specifier(arrpointer);
	while (obj.str[obj.i_str] != 0)
	{
		if (obj.str[obj.i_str] == '%' && obj.str[obj.i_str + 1] == 0)
			break ;
		if (obj.str[obj.i_str] == '%')
		{
			++obj.i_str;
			parse_general(&obj);
			arrpointer[(int)obj.spc](&obj);
			clean_struct(&obj);
		}
		if (obj.str[obj.i_str] != 0 && obj.str[obj.i_str] != '%')
			print_character(obj.str[obj.i_str], &obj);
		obj.i_str += obj.str[obj.i_str] && obj.str[obj.i_str] != '%' ? 1 : 0;
	}
	va_end(obj.ap);
	return (obj.ret);
}

void	clean_struct(t_pf_object *obj)
{
	obj->flags = 0;
	obj->spc = 0;
	obj->i = 0;
	obj->val.ll = 0;
	obj->width = 0;
	obj->prcs = 0;
	++obj.i_str;
}

void	print_character(char c, t_pf_object *obj)
{
	// if (c != 0)
	// {
		obj->ret++;
		ft_putchar(c);
	// }
}