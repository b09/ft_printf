/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/11/02 00:02:12 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// %[flags]     [width]             [precision]             [length]    [specifier]
// %[#,0,-, ,+] [1,2,3,4,5,6,7,8,9] [.,0,1,2,3,4,5,6,7,8,9] [h,hh,l,ll] [c,s,p,d,i,o,u,x,X,f,%]


void	print_character(char c, t_pf_object *obj)
{
	obj->ret++;
	ft_putchar(c);
}


void	parse_flags(t_pf_object *obj)
{
	while (ft_strchr_int("#0- +", obj->str[obj->i_str]) != -1)
	{
		obj->flags |= 1 << ft_strchr_int("#0- +", obj->str[obj->i_str]);
		obj->i_str++;
	}
	if (obj->flags & ZERO_F && obj->flags & MINUS_F)
		obj->flags ^= ZERO_F;
		// printf("parse_flags line 30\n");
	if (obj->flags & SPACE_F && obj->flags & PLUS_F)
		obj->flags ^= SPACE_F;
	
}

void	parse_width(t_pf_object *obj)
{
	obj->width = ft_atoi(&(obj->str[obj->i_str]));
	while (ft_isdigit(obj->str[obj->i_str]))
		++obj->i_str;
}


void	parse_precision(t_pf_object *obj)
{
	obj->precision = ft_atoi(&(obj->str[obj->i_str]));
	while (ft_isdigit(obj->str[obj->i_str]))
		++obj->i_str;
}


void	parse_width_precision(t_pf_object *obj, int *pointer)
{
	*pointer = ft_atoi(&(obj->str[obj->i_str]));
	while (ft_isdigit(obj->str[obj->i_str]))
		++obj->i_str;
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
	}
	else
	{
		obj->u_output.u_lnglng = obj->flags & H_F ? (short)obj->u_output.u_lnglng : obj->u_output.u_lnglng;
		obj->u_output.u_lnglng = obj->flags & HH_F ? (char)obj->u_output.u_lnglng : obj->u_output.u_lnglng;
		obj->u_output.u_lnglng = obj->flags & L_F ? (long)obj->u_output.u_lnglng : obj->u_output.u_lnglng;
		obj->u_output.u_lnglng = obj->flags & LL_F ? (long long)obj->u_output.u_lnglng : obj->u_output.u_lnglng;
	}
}


char	get_base(char format_specifier)
{
	char	base;

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

// output must be cast according to h, hh, l, ll flags, signed and unsigned
// void	ft_putnbr_base(long long n, int base)
// {
// 	char			a;
// 	long long		i;
	
// sign must be printed by other function to ensure correct placement, ie. -0000042 instead of 00000-42
// 	if (n < 0)
// 		n = -n;
// 	i = n;
// 	if (i > (base - 1))
// 	{
// 		ft_putnbr_base(i / base, base);
// 		ft_putnbr_base(i % base, base);
// 	}
// 	if (i <= (base - 1) && i < 10)
// 	{
// 		a = '0' + i;
// 		write(1, &a, 1);
// 	}
// 	else if (i > 9 && i < 16 && base > 10)
// 	{
// 		a = 'a' + i - 10;
// 		write(1, &a, 1);
// 	}
// }

// length_of_number not protected against negative numbers, larger than int numbers, etc



















// this fuction will not work for unsigned long long variables
int		length_of_number(t_pf_object *obj, char base)
{
	long long original_int;
	long long holder;
	int	counter;

	counter = 1;
	original_int = obj->u_output.u_lnglng;

	if (original_int < 0)
		original_int = -original_int;
	// printf("line 157: %d<-original_int, %d<-base, %d<-counter\n", original_int, base, counter);
	while ( original_int > (base - 1))
	{
		// printf("line 160 while loop: %d<-original, %d<-counter\n", original_int, counter);
		original_int /= base;
		++counter;
	}
	// printf("line 163, counter: %d<-number\n", counter);
	return (counter);
}


// can be used for strings as well, not just numbers
void	print_padding(t_pf_object *obj, int length_of_output, char character)
{
	int		length_to_print;

	length_to_print = obj->width - length_of_output;
	if (obj->flags & PLUS_F && length_to_print > 0)
		--length_to_print;
	// printf("line 179, print_padding: %d<-number\n", length_to_print);
	while (0 < length_to_print--)
		print_character(character, obj);
}




// print_sign();   only for d, i convervion
// where does this need to happen? 
// parse_specifier -> 	print_number -> putnbr_base -> print_padding
// 								or 	 -> print_padding -> putnbr_base



void	print_sign(t_pf_object *obj)
{
	
	if ((long long)obj->u_output.u_lnglng >= 0 && obj->flags & PLUS_F)
		print_character('+', obj);
	else if ((long long)obj->u_output.u_lnglng < 0)
		print_character('-', obj);
}

void	print_space_flag(t_pf_object *obj)
{
	if (obj->flags & SPACE_F)
		print_character(' ', obj);
}

void	print_hash_flag(t_pf_object *obj)
{
	if (obj->specifier == 'o')
		print_character('0', obj);
	else if (obj->specifier == 'x' || obj->specifier == 'p')
	{
		print_character('0', obj);
		print_character('x', obj);
	}
	else if (obj->specifier == 'X')
	{
		print_character('0', obj);
		print_character('X', obj);
	}
	else if (obj->specifier == 'f')
		print_character('.', obj);
}




// how can a i print all numbers?
// what formats can be printed? d, i, 
// putnbr can do long long
// unsigned long long must also be printed

// if 0 padded and outout negative, - sign printed before 0's
// if 0 padded and + flag, + sign printed before 0's







// void	print_number(t_pf_object *obj, char base)
// {
// 	parse_length(obj, 0);


// 	if (obj->flags & MINUS_F && !(obj->flags & ZERO_F))
// 	{
// 		if (obj->flags & SIGNED_F && obj->flags & PLUS_F)
// 			print_sign(obj);

// 		ft_putnbr_base(obj->u_output.u_lnglng, base);
// 		print_padding(obj, length_of_number(obj, base), ' ');
// 	}

// 	else if (!(obj->flags & MINUS_F) && !(obj->flags & ZERO_F))
// 	{
// 		print_padding(obj, length_of_number(obj, base), ' ');
// 		if (obj->flags & SIGNED_F)
// 			print_sign(obj);

// 		ft_putnbr_base(obj->u_output.u_lnglng, base);
// 	}


// 	if (obj->flags & MINUS_F && obj->flags & ZERO_F)
// 	{
// 		if (obj->flags & SIGNED_F)
// 			print_sign(obj);

// 		ft_putnbr_base(obj->u_output.u_lnglng, base);
// 		print_padding(obj, length_of_number(obj, base), '0');
// 	}

// 	else if (!(obj->flags & MINUS_F) && obj->flags & ZERO_F)
// 	{
// 		if (obj->flags & SIGNED_F)
// 			print_sign(obj);
// 		// printf("line 251, length_of_nuber: %dnumbers\n", length_of_number(obj, base));
// 		print_padding(obj, length_of_number(obj, base), '0');
// 		ft_putnbr_base(obj->u_output.u_lnglng, base);
// 	}
// }

// %[#,0,-, ,+] [1,2,3,4,5,6,7,8,9] [.,0,1,2,3,4,5,6,7,8,9] [h,hh,l,ll] [c,s,p,d,i,o,u,x,X,f,%]
// d / i ==   - + ' ' 0

/*

#,
0,
-, 
space
+

# 0
# -
# space
# +

# 0 -
# 0 space
# 0 +

# 0 - space
# 0 - +

# 0 - space +

 */
// if - and 0, 0 off
// if ' ' and +, ' ' off
// order of priority 
// +,	-,	sp,	#	
void	print_d(t_pf_object *obj)
{
	obj->u_output.u_lnglng = va_arg(obj->ap, int);
	// printf("arrived print_d number->%d\n", va_arg(obj->ap, int));
	parse_length(obj, 0);
	int base = 10;

	if (obj->flags & MINUS_F)
	{
		if (obj->flags & PLUS_F)
			print_sign(obj);

		ft_putnbr_base(obj->u_output.u_lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}

	else if (obj->flags & ZERO_F)
	{
		if (obj->flags & SIGNED_F)
			print_sign(obj);
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
	else
	{
		print_sign(obj);
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
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
	char *str;

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
	long long pointer = va_arg(obj->ap, void*);
	parse_length(obj, 0);
	int base = 16;

	if (obj->flags & MINUS_F)
	{
		print_hash_flag(obj);
		ft_putnbr_base(obj->u_output.u_lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}

	else if (obj->flags & ZERO_F)
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
	else
	{
		print_hash_flag(obj);
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
}


void	print_o(t_pf_object *obj)
{
	obj->u_output.u_lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	int base = 8;

	if (obj->flags & MINUS_F)
	{
		if (obj->flags & HASH_F)
			print_hash_flag(obj);
		ft_putnbr_base(obj->u_output.u_lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}

	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
	
}

void	print_u(t_pf_object *obj)
{
	obj->u_output.u_lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	int base = 10;

	if (obj->flags & MINUS_F)
	{
		ft_putnbr_base(obj->u_output.u_lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}

	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
}

void	print_x(t_pf_object *obj)
{
	obj->u_output.u_lnglng = va_arg(obj->ap, unsigned int);
	parse_length(obj, 0);
	int base = 16;

	if (obj->flags & MINUS_F)
	{
		if (obj->flags & HASH_F)
			print_hash_flag(obj);
		ft_putnbr_base(obj->u_output.u_lnglng, base);
		print_padding(obj, length_of_number(obj, base), ' ');
	}

	else if (obj->flags & ZERO_F)
	{
		print_padding(obj, length_of_number(obj, base), '0');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
	else
	{
		print_padding(obj, length_of_number(obj, base), ' ');
		ft_putnbr_base(obj->u_output.u_lnglng, base);
	}
}

void	print_f(t_pf_object *obj)
{
	exit ;
}

void	print_percent(t_pf_object *obj)
{
	print_character('%', obj);
}


void	populate_func_pointer(func_pointer *arrPointer)
{
	char	i;

	i = 0;
	while (i < 31)
		arrPointer[i++] = invalid_format;
		// c,s,p,d,i,o,u,x,X,f,%
	arrPointer['c' - 'a'] = print_char;
	arrPointer['s' - 'a'] = print_str;
	arrPointer['p' - 'a'] = print_ptr;
	arrPointer['d' - 'a'] = print_d;
	arrPointer['i' - 'a'] = print_d;
	arrPointer['o' - 'a'] = print_o;
	arrPointer['u' - 'a'] = print_u;
	arrPointer['x' - 'a'] = print_x;
	arrPointer['X' - 'a'] = print_x;
	arrPointer['f' - 'a'] = print_f;
	arrPointer['%' - 'a'] = print_percent;
}

// currently the function reaches parse_specifier and prints directly to the screen
// instead, the function should call child-functions which print the output, while
// also considering the flags which are on. In this case, a buffer should be populated

// print_number needs some reference as to what ot 
void	parse_specifier(t_pf_object *obj)
{
	char 			specifier;
	func_pointer	arrPointer[32];


	populate_func_pointer(arrPointer);

	specifier = obj->str[obj->i_str];
	if (specifier == 'd' || specifier == 'i')
		obj->flags |= SIGNED_F;
	printf("arrived populate_func_pointer, specifier %c\n", obj->str[obj->i_str]);
	arrPointer[specifier - 'a'](obj);
}


















void	parse_general(t_pf_object *obj)
{
	parse_flags(obj);
	parse_width(obj);
	if (obj->str[obj->i_str] == '.')
	{
		obj->i_str++;
		parse_precision(obj);
	}
	parse_length(obj, 1);
	parse_specifier(obj);
}


// void	print_output(t_pf_object *obj)
// {

// }

int		ft_printf(const char * restrict format, ...)
{
	t_pf_object	obj;

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
		// print_character(obj.str[obj.i_str]);
		++obj.i_str;
	}
	va_end(obj.ap);
	return (0);
}

