/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   specifier_functions.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:18:01 by bprado         #+#    #+#                */
/*   Updated: 2019/11/14 20:00:24 by bprado        ########   odam.nl         */
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
		ft_putnbr_base2(obj->val.lnglng, base, obj);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		if (obj->flags & SIGNED_F)
			print_sign(obj);
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
	else
	{
		print_sign(obj);
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
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

	obj->val.ptr = va_arg(obj->ap, char*);
	str = obj->val.ptr;
	obj->flags |= STRNG;
	if (obj->flags & MINUS_F)
	{
		print_string(obj);
		print_padding(obj, ft_strlen(str), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, ft_strlen(str), '0');
		// ft_putstr(str);
		print_string(obj);
	}
	else
	{
		print_padding(obj, ft_strlen(str), ' ');
		// ft_putstr(str);
		print_string(obj);
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
		ft_putnbr_base2(obj->val.lnglng, base, obj);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
	else
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
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
		ft_putnbr_base2(obj->val.lnglng, base, obj);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
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
		ft_putnbr_base2(obj->val.lnglng, base, obj);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
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
		ft_putnbr_base2(obj->val.lnglng, base, obj);
		print_padding(obj, length_of_number(obj, base), ' ');
	}
	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base2(obj->val.lnglng, base, obj);
	}
}

void	print_f(t_pf_object *obj)
{
	int		base;
	long	ret;
	double	copy;

	parse_length(obj, 0);
	base = 10;
	copy = va_arg(obj->ap, double);
	obj->val.lngdbl = copy;
	ret = 0;
	if (obj->precision == 0)
		obj->precision = 6;
	ret = (long)copy;
	ft_putnbr_base2(ret, base, obj);
	copy = copy - ret;
	print_character('.', obj);
	while (obj->precision--)
	{
		copy *= 10.0;
		ret = (long)copy;
		printf("ret:%d\n", ret);
		// ft_putnbr_base2(ret, base, obj);
		copy = copy - ret;
	}
}
// 0.234
// 2.34
void	print_percent(t_pf_object *obj)
{
	print_character('%', obj);
}



// // code below is an implementation of printing doubles from the blog http://www.corsix.org/

// // typedef union {
// //   double n;
// //   uint64_t u64;
// //   struct {
// //     uint32_t lo;
// //     uint32_t hi;
// //   } u32;
// // } TValue;

// void print(double n) {
//   TValue t;
//   t.n = n;
// //   if ((t.u32.hi << 1) >= 0xffe00000) {	
// //     if (((t.u32.hi & 0x000fffff) | t.u32.lo) != 0) {
// //       printf("NaN\n");
// //     } else {
// //       printf("Infinity\n");
// //     }
// //   } else {
// 	char buf[1154];
//     uint32_t nd[128];
//     int32_t ndlo = 0;
//     int32_t ndhi = 0;
//     int32_t e = (t.u32.hi >> 20) & 0x7ff;

// 	// comment: 01111111 11110000 00000000 00000000 00000000 00000000 00000000 00000000
// 			// 	SE->	  ->|F->		S=Sign, E=Exponent, F=Fraction				->|
// 	// ex:
// 	// comment: 00111111 11111111 00000000 00000000 |<-high|low->| 00000000 00000000 00000000 00000000
// 	// shift down 20
// 	// comment: 11110000 00000000 00000011 11111111 |<-high|low->| 00000000 00000000 00000000 00000000
// 	// comment: 00000000 00000000 00000111 11111111 |<-0x7ff
// 	// comment: 00000000 00000000 00000011 11111111 |<- e
//     nd[0] = t.u32.hi & 0xfffff;
// 	// comment: 00000000 00001111 11111111 11111111 |<-0xfffff
// 	// comment: 00111111 11111111 00000000 00000000 |<-high
// 	// comment: 00000000 00001111 00000000 00000000 |<- nd[0]   fraction bits
//     if (e == 0) {
//       e++;
//     } else {
//       nd[0] |= 0x100000;
// 	// comment: 00000000 00010000 00000000 00000000 |<-0x100000   largest negative exp. -1022
// 	// comment: 00000000 00001111 00000000 00000000 |<- nd[0] old
// 	// comment: 00000000 00011111 00000000 00000000 |<- nd[0] new
//     }
//     e -= 1043;
//     if (t.u32.lo) {
//       e -= 32;
//       nd[0] = (nd[0] << 3) | (t.u32.lo >> 29);
//       ndhi = nd_mul2k(nd, ndhi, 29, t.u32.lo & 0x1fffffff);


// 	  		int32_t nd_mul2k(uint32_t* nd, int32_t ndhi, uint32_t k, uint32_t carry_in) {
// 				  			(			nd, 		ndhi, 		29, 		t.u32.lo & 0x1fffffff)
// 			while (k >= 29) {
// 				for (uint32_t i = 0; i <= (uint32_t)ndhi; i++) {
// 				uint64_t val = ((uint64_t)nd[i] << 29) | carry_in;
// 				carry_in = (uint32_t)(val / 1000000000);
// 				nd[i] = (uint32_t)val - carry_in * 1000000000;
// 				}
// 				if (carry_in) {
// 				nd[++ndhi] = carry_in; carry_in = 0;
// 				}
// 				k -= 29;
// 			}
// 			if (k) {
// 				for (uint32_t i = 0; i <= (uint32_t)ndhi; i++) {
// 				uint64_t val = ((uint64_t)nd[i] << k) | carry_in;
// 				carry_in = (uint32_t)(val / 1000000000);
// 				nd[i] = (uint32_t)val - carry_in * 1000000000;
// 				}
// 				if (carry_in) nd[++ndhi] = carry_in;
// 			}
// 			return ndhi;
// 	}
//     }
//     if (e >= 0) {
//       ndhi = nd_mul2k(nd, ndhi, (uint32_t)e, 0);
//     } else {
//       ndlo = nd_div2k(nd, ndlo, ndhi, (uint32_t)-e);
//     }
//     nd_print(buf, nd, ndlo, ndhi);


// 			void nd_print(char* p, uint32_t* nd, int32_t ndlo, int32_t ndhi) {
// 			int32_t i;
// 			for (i = ndhi; i >= 0; --i) {
// 				nasonov9(p, nd[i & 127]); p += 9;
// 			}
// 			*p++ = '.';
// 			for (; i >= ndlo; --i) {
// 				nasonov9(p, nd[i & 127]); p += 9;
// 			}
// 			*p = 0;
// 			}

//     printf("%s\n", buf);
//   }