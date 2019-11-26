/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/11/26 22:17:31 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_base(char format_spc)
{
	char			base;

	base = 0;
	base = format_spc == 'd' ? 10 : base;
	base = format_spc == 'i' ? 10 : base;
	base = format_spc == 'x' ? 16 : base;
	base = format_spc == 'X' ? 16 : base;
	base = format_spc == 'o' ? 8 : base;
	base = format_spc == 'u' ? 10 : base;
	base = format_spc == 'p' ? 16 : base;
	return (base);
}
// this fuction will not work for unsigned long long variables
int		length_of_number(t_pf_object *obj)
{
	long long		original_int;
	int				counter;
	char			base;

	base = get_base(obj->spc);
	counter = 1;
	original_int = obj->val.ll;
	if (original_int < 0)
		original_int = -original_int;
	while ((base > 0) && original_int > (base - 1))
	{
		original_int /= base;
		++counter;
	}
	counter += (obj->flags & HASH_F) ? 1 : 0;
	counter += (obj->flags & HASH_F && (obj->spc == 'x' || obj->spc == 'X')) ? 1 : 0;
	if (obj->spc == 'p')
		counter += 2;
	return (counter);
}

void	ft_putnbr_base2(long long n, int base, t_pf_object *obj)
{
	char			a;
	long long		i;

	if (n < 0)
		n = -n;
	i = n;
	if (i > (base - 1))
	{
		ft_putnbr_base2(i / base, base, obj);
		ft_putnbr_base2(i % base, base, obj);
	}
	if (i <= (base - 1) && i < 10)
	{
		a = '0' + i;
		print_character(a, obj);
	}
	else if (i > 9 && i < 16 && base > 10)
	{
		a = obj->spc != 'X' ? 'a' + i - 10 : 'A' + i - 10;
		print_character(a, obj);
	}
}

int		ft_printf(const char* restrict format, ...)
{
	t_pf_object		obj;

	ft_bzero(&obj, sizeof(obj));
	obj.str = format;
	va_start(obj.ap, format);
	while (obj.str[obj.i_str] != 0)
	{
		if (obj.str[obj.i_str] == '%' && obj.str[obj.i_str + 1] == 0)
			break ;
		if (obj.str[obj.i_str] == '%')
		{
			++obj.i_str;
			parse_general(&obj);
			parse_specifier(&obj);
			// parse_specifier will increase i_str;
		}
	// "%%" will print_character thru print_str
		if (obj.str[obj.i_str] != 0)
			print_character(obj.str[obj.i_str], &obj);
		obj.i_str += obj.str[obj.i_str] ? 1 : 0;
	}
	va_end(obj.ap);
	return (obj.ret);
}
