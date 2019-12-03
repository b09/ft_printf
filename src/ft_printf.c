/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/12/03 22:33:33 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	get_base(char format_spc)
{
	char			base;

	base = 0;
	base = format_spc == 'd' ? 10 : base;
	base = format_spc == 'i' ? 10 : base;
	base = format_spc == 'f' ? 10 : base;
	base = format_spc == 'x' ? 16 : base;
	base = format_spc == 'X' ? 16 : base;
	base = format_spc == 'o' ? 8 : base;
	base = format_spc == 'u' ? 10 : base;
	base = format_spc == 'p' ? 16 : base;
	return (base);
}

int		length_of_number(t_pf_object *obj)
{
	long long		original_int;
	int				counter;
	char			base;

	base = get_base(obj->spc);
	counter = 1;
	original_int = obj->val.llong;
	if (original_int < 0)
		original_int = -original_int;
	while ((base > 0) && original_int > (base - 1))
	{
		original_int /= base;
		++counter;
	}

	if ((obj->flags & SIGNED_F) && obj->val.llong < 0)// && (!obj->width || (obj->width && obj->flags & ZERO_F)))
		counter++;

	counter = (!obj->val.llong && obj->flags & PRECISN && !obj->prcs) ? 0 : counter;	// check this statment

	return (counter);
}

int		length_of_unsigned(t_pf_object *obj)
{
	unsigned long long		original_int;
	int						counter;
	unsigned char			base;

	base = get_base(obj->spc);
	counter = 1;
	original_int = obj->val.ll;
	while ((base > 0) && original_int > (base - 1))
	{
		original_int /= base;
		++counter;
	}
	if (obj->flags & HASH_F && obj->spc == 'o' && obj->val.ll != 0)
		counter += 1;
	else if ((obj->flags & HASH_F) && obj->spc != 'o' && obj->val.ll != 0)
		counter += 2; // check this statement
	else if (obj->spc == 'p')
		counter += 2;

	counter = (!obj->val.ll && obj->flags & PRECISN && !obj->prcs) ? 0 : counter;	// check this statement

	return (counter);
}

void	ft_putnbr_signed(long long n, int base, t_pf_object *obj)
{
	char				a;
	long long			i;

	a = 0;
	if (obj->val.ll == 0 && ((obj->flags & PRECISN && obj->prcs == 0) || obj->spc == 'c')) // check this
		return ;
	if (n < 0)
		n = -n;
	i = n;
	if (i > (base - 1))
	{
		ft_putnbr_signed(i / base, base, obj);
		ft_putnbr_signed(i % base, base, obj);
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

void	ft_putnbr_unsigned(unsigned long long i, int base, t_pf_object *obj)
{
	unsigned char			a;
	// unsigned long long		i;

	a = 0;
	if (obj->val.ll == 0 && obj->flags & PRECISN && obj->prcs == 0) // check this
		return ;
	// i = n;
	if (i > ((unsigned)base - 1))
	{
		ft_putnbr_unsigned(i / base, base, obj);
		ft_putnbr_unsigned(i % base, base, obj);
	}
	if (i <= ((unsigned)base - 1) && i < 10)
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











int		length_of_float(t_pf_object *obj)
{
	int				counter;
	long double		original_float;

	// include decimal in length and a single character
	counter = 0;
	if (((obj->val.shdbl[4] & NZERO) == NZERO) && obj->val.llong == 0)
		counter = 2 + obj->prcs;
	counter = ((obj->val.shdbl[4] & NINF) == NINF) && obj->val.llong == 0 ? 4 : counter;
	counter = ((obj->val.shdbl[4] & INF) == INF) && obj->val.llong == 0 ? 3 : counter;
	counter = ((obj->val.shdbl[4] & INF) == INF) && obj->val.llong > 0 ? 3 : counter;
	if (counter)
		return (counter);
	counter = 2;
	original_float = obj->val.lngdbl;
	counter += obj->flags & PRECISN ? obj->prcs : 6;
	
	if (original_float < 0)
		original_float = -original_float;
	while (original_float > 9)
	{
		original_float /= 10;
		++counter;
	}
	counter += obj->val.lngdbl < 0 ? 1 : 0;
	return (counter);
}

// create function to print character strings -inf, inf, nan, -0
// function works
int		float_exception(t_pf_object *obj)
{
	char 		*str1;
	char 		*str2;
	char 		*str3;
	char 		*str4;

	str1 = "-0";
	str2 = "-inf";
	str3 = "inf";
	str4 = "nan";

	if ((obj->val.shdbl[4] & NZERO) == NZERO && obj->val.llong == 0)
		obj->val.ptr = str1; 	// 	-0 negative zero
	else if ((obj->val.shdbl[4] & NINF) == NINF && obj->val.llong == 0)
		obj->val.ptr = str2;
	else if ((obj->val.shdbl[4] & INF) == INF && obj->val.llong == 0)
		obj->val.ptr = str3;
	else if ((obj->val.shdbl[4] & INF) == INF && obj->val.llong > 0)
		obj->val.ptr = str4;
	else
		return (0);
	print_string(obj);
	return (1);
}

void	putfloat(t_pf_object *obj)
{
	long long	ret;
	long double	copy;

	// check if float is at limits (inf, -inf), if so, return
	// do negative floats work?
	// should I send to putnbr_unsigned() instead of putnbr_signed()?
	if (float_exception(obj))
		return ;
	copy = 0;
	copy = 	obj->val.lngdbl;
	ret = (long long)copy;
	ft_putnbr_signed(ret, get_base(obj->spc), obj);
	copy = copy - ret;
	print_character('.', obj);
	// check if previous to last digit would increase last digit by one
	// 10.96 -> 109.6 ->
	if (copy * (prcs + 1) * 10 )
	while (obj->prcs-- + 1)
	{
		copy *= 10.0;
		ret = (long long)copy;
		ft_putnbr_signed(ret, get_base(obj->spc), obj);
		copy = copy - ret;
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
			clean_struct(&obj);
			parse_general(&obj);
			parse_specifier(&obj);
			// parse_specifier will increase i_str;
		}
	// "%%" will print_character thru print_str
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
}
