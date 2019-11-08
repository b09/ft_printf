/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:18:01 by bprado         #+#    #+#                */
/*   Updated: 2019/11/08 21:51:54 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void	print_d(t_pf_object *obj)
{
	int			base;

	base = 10;
	obj->val.lnglng = va_arg(obj->ap, int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		if (obj->flags & PLUS_F)
			print_sign(obj);
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		if (obj->flags & SIGNED_F)
			print_sign(obj);
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_sign(obj);
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	invalid_format(t_pf_object *obj)
{
	ft_putstr("Not a valid format\n");
}

void	print_char(t_pf_object *obj)
{
	if (obj->flags & MINUS_F)
	{
		print_character(va_arg(obj->ap, int), obj);
		print_padding(obj, 1, ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, 1, '0');
		print_character(va_arg(obj->ap, int), obj);
	}
	else
	{
		print_padding(obj, 1, ' ');
		print_character(va_arg(obj->ap, int), obj);
	}
}

void	print_str(t_pf_object *obj)
{
	char		*str;

	str = va_arg(obj->ap, char*);
	if (obj->flags & MINUS_F)
	{
		ft_putstr(str);
		print_padding(obj, ft_strlen(str), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, ft_strlen(str), '0');
		ft_putstr(str);
	}
	else
	{
		print_padding(obj, ft_strlen(str), ' ');
		ft_putstr(str);
	}
}

void	print_ptr(t_pf_object *obj)
{
	long long	pointer;
	int			base;

	base = 16;
	pointer = va_arg(obj->ap, void*);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		print_hash_flag(obj);
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	print_o(t_pf_object *obj)
{
	int			base;

	base = 8;
	obj->val.lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		if (obj->flags & HASH_F)
			print_hash_flag(obj);
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	print_u(t_pf_object *obj)
{
	int			base;

	base = 10;
	obj->val.lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	print_x(t_pf_object *obj)
{
	int			base;

	base = 16;
	obj->val.lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	if (obj->flags & MINUS_F)
	{
		if (obj->flags & HASH_F)
			print_hash_flag(obj);
		ft_putnbr_base(obj->val.lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->val.lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->val.lnglng, base);
	}
}

void	print_f(t_pf_object *obj)
{
	// int			base;
	// long long	ret;
	// long double	copy;

	// parse_length(obj, 0);
	// base = 16;
	// copy = va_arg(obj->ap, long double);
	// obj->val.lngdbl = copy;
	// ret = 0;

	// 0.000015468000

	// ret = copy;
	// while (copy - ret > 0)
	// {
	// 	copy = copy * 10;
	// 	ret = copy;
	// }


	// while (copy > 0 && copy < 10)
	// 	ret = copy * 10;



	// 	ret = 10 * copy
	



	// number = ddd * 100;
	// ddd *= 100;
	// ddd -= number;
	exit ;

}

void	print_percent(t_pf_object *obj)
{
	print_character('%', obj);
}



// code below is an implementation of printing doubles from the blog http://www.corsix.org/
void print(double n) {
  TValue t;
  t.n = n;
//   if ((t.u32.hi << 1) >= 0xffe00000) {
//     if (((t.u32.hi & 0x000fffff) | t.u32.lo) != 0) {
//       printf("NaN\n");
//     } else {
//       printf("Infinity\n");
//     }
//   } else {
	char buf[1154];
    uint32_t nd[128];
    int32_t ndlo = 0;
    int32_t ndhi = 0;
    int32_t e = (t.u32.hi >> 20) & 0x7ff;
    nd[0] = t.u32.hi & 0xfffff;
    if (e == 0) {
      e++;
    } else {
      nd[0] |= 0x100000;
    }
    e -= 1043;
    if (t.u32.lo) {
      e -= 32;
      nd[0] = (nd[0] << 3) | (t.u32.lo >> 29);
      ndhi = nd_mul2k(nd, ndhi, 29, t.u32.lo & 0x1fffffff);


	  		int32_t nd_mul2k(uint32_t* nd, int32_t ndhi, uint32_t k, uint32_t carry_in) {
			while (k >= 29) {
				for (uint32_t i = 0; i <= (uint32_t)ndhi; i++) {
				uint64_t val = ((uint64_t)nd[i] << 29) | carry_in;
				carry_in = (uint32_t)(val / 1000000000);
				nd[i] = (uint32_t)val - carry_in * 1000000000;
				}
				if (carry_in) {
				nd[++ndhi] = carry_in; carry_in = 0;
				}
				k -= 29;
			}
			if (k) {
				for (uint32_t i = 0; i <= (uint32_t)ndhi; i++) {
				uint64_t val = ((uint64_t)nd[i] << k) | carry_in;
				carry_in = (uint32_t)(val / 1000000000);
				nd[i] = (uint32_t)val - carry_in * 1000000000;
				}
				if (carry_in) nd[++ndhi] = carry_in;
			}
			return ndhi;
	}
    }
    if (e >= 0) {
      ndhi = nd_mul2k(nd, ndhi, (uint32_t)e, 0);
    } else {
      ndlo = nd_div2k(nd, ndlo, ndhi, (uint32_t)-e);
    }
    nd_print(buf, nd, ndlo, ndhi);


			void nd_print(char* p, uint32_t* nd, int32_t ndlo, int32_t ndhi) {
			int32_t i;
			for (i = ndhi; i >= 0; --i) {
				nasonov9(p, nd[i & 127]); p += 9;
			}
			*p++ = '.';
			for (; i >= ndlo; --i) {
				nasonov9(p, nd[i & 127]); p += 9;
			}
			*p = 0;
			}

    printf("%s\n", buf);
  }