/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/10/18 20:22:15 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// %[flags]     [width]             [precision]             [length]    [specifier]
// %[#,0,-, ,+] [1,2,3,4,5,6,7,8,9] [.,0,1,2,3,4,5,6,7,8,9] [h,hh,l,ll] [c,s,p,d,i,o,u,x,X,f,%]


void	parse_flags(t_pf_object *obj)
{
	while (ft_strchr_int("#0- +", obj->str[obj->i_str]) != -1)
	{
		obj->flags |= 1 << ft_strchr_int("#0- +", obj->str[obj->i_str]);
		obj->i_str++;
	}
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


void	parse_length(t_pf_object *obj)
{
	if (obj->str[obj->i_str] == 'l')
	{
		obj->flags |= (obj->str[obj->i_str + 1] == 'l') ? LL_FLAG : L_FLAG;
		obj->i_str += (obj->str[obj->i_str + 1] == 'l') ? 2 : 1;
	}
	if (obj->str[obj->i_str] == 'h')
	{
		obj->flags |= (obj->str[obj->i_str + 1] == 'h') ? HH_FLAG : H_FLAG;
		obj->i_str += (obj->str[obj->i_str + 1] == 'h') ? 2 : 1;

	}
}



int		size_of_number(t_pf_object *obj)
{

}



void	print_padding(t_pf_object *obj)
{
	int		length_to_print;

	length_to_print = obj->width - size_of_number(obj);
	while (0 < length_to_print--)
		ft_putchar(' ');
}




void	print_number(t_pf_object *obj)
{
	if (obj->flags & MINUS_FLAG)
	{
		printf("inside print_number line 64l\n");
		ft_putnbr((int)obj->u_output.u_int);
		print_padding(obj);
	}
	else
	{
		print_padding(obj);
		ft_putnbr((int)obj->u_output.u_int);
	}
	
}

// currently the function reaches parse_specifier and prints directly to the screen
// instead, the function should call child-functions which print the output, while
// also considering the flags which are on. In this case, a buffer should be populated

void	parse_specifier(t_pf_object *obj)
{
	if (ft_strchr_int("dscoiuxfp%", obj->str[obj->i_str]) > -1)
	{
		if (obj->str[obj->i_str] == 'd')
		{
			// obj->u_output.u_int = va_arg(obj->ap, int);
			// while (obj->width--)
			// 	ft_putchar(' ');
			// // printf("hey\n");
			// ft_putnbr(obj->u_output.u_int);
			print_number(obj);
		}

		else if (obj->str[obj->i_str] == 's')
			ft_putstr(va_arg(obj->ap, char*));

		else if (obj->str[obj->i_str] == 'c')
			ft_putchar(va_arg(obj->ap, int));

		else if (obj->str[obj->i_str] == 'o')
			ft_putnbr(va_arg(obj->ap, unsigned int));

		else if (obj->str[obj->i_str] == 'i')
			ft_putnbr(va_arg(obj->ap, int));

		else if (obj->str[obj->i_str] == 'u')
			ft_putnbr(va_arg(obj->ap, unsigned int));

		else if (obj->str[obj->i_str] == 'x')
			ft_putnbr(va_arg(obj->ap, unsigned int));

		else if (obj->str[obj->i_str] == 'X')
			ft_putnbr(va_arg(obj->ap, unsigned int));

		else if (obj->str[obj->i_str] == 'f')
			ft_putnbr(va_arg(obj->ap, unsigned int));

		else if (obj->str[obj->i_str] == 'p')
			ft_putnbr(va_arg(obj->ap, unsigned int));
			
		else if (obj->str[obj->i_str] == '%')
			ft_putnbr(va_arg(obj->ap, unsigned int));
		++obj->i_str;
	}
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
	parse_length(obj);
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
		// ft_putchar(obj.str[obj.i_str]);
		++obj.i_str;
	}
	va_end(obj.ap);
	return (0);
}














// // example 1
// void simple_printf(const char* fmt, ...)
// {
// 	va_list args;
// 	va_start(args, fmt);
 
// 	while (*fmt != '\0') {
// 		if (*fmt == 'd') {
// 			int i = va_arg(args, int);
// 			printf("%d\n", i);
// 		} else if (*fmt == 'c') {
// 			// A 'char' variable will be promoted to 'int'
// 			// A character literal in C is already 'int' by itself
// 			int c = va_arg(args, int);
// 			printf("%c\n", c);
// 		} else if (*fmt == 'f') {
// 			double d = va_arg(args, double);
// 			printf("%f\n", d);
// 		}
// 		++fmt;
// 	}
 
// 	va_end(args);
// }
 
// int main()
// {
// 	simple_printf("dcff", 3, 'a', 1.999, 42.5); 
// }

// // example 2
// int sum(int num_args, ...) {
//    int val = 0;
//    va_list ap;
//    int i;

//    va_start(ap, num_args);
//    for(i = 0; i < num_args; i++) {
// 	  val += va_arg(ap, int);
//    }
//    va_end(ap);
 
//    return val;
// }





/*
identify format specifier expression looking for %
header file contains struct
parse expression to populate struct 
struct members are format type, length modifier, flags, width, precision
   possible 
writing to output 
look up stdarg(3)





struct created containing
- length
- etc

input is a string
- string contains format specifiers
- f.s. define data type printed to screen?

output is a number




*/