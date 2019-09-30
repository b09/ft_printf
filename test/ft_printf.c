/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/03 16:49:24 by bprado         #+#    #+#                */
/*   Updated: 2019/09/30 19:21:57 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


// %[flags]     [width]             [precision]             [length]    [specifier]
// %[#,0,-, ,+] [1,2,3,4,5,6,7,8,9] [.,0,1,2,3,4,5,6,7,8,9] [h,hh,l,ll] [c,s,p,d,i,o,u,x,X,f,%]


// void	parse_specifier()



void	parse_flags(t_pf_object *obj)
{
	char *flags;
	
	flags = "#0- +";
	while (ft_strchr_int(flags, obj->str[obj->i_str]) != -1)
	{
		obj->flags |= 1 << ft_strchr_int(flags, obj->str[obj->i_str]);
		obj->i_str++;
	}

}










// void	parse_length(t_pf_object *obj)
// {
// 	if (obj->str[obj->i_str] == 'h')

// }







// void	parse_precision(t_pf_object *obj)
// {

// }







// void	parse_width(t_pf_object *obj)
// {
	
// }









void	parse_specifier(t_pf_object *obj, va_list ap)
{
	if (obj->str[obj->i_str] == 'd')
		ft_putnbr(va_arg(ap, int));
	if (obj->str[obj->i_str] == 's')
		ft_putstr(va_arg(ap, char*));
	if (obj->str[obj->i_str] == 'c')
		ft_putchar(va_arg(ap, int));
	if (obj->str[obj->i_str] == 'o')
		ft_putnbr(va_arg(ap, unsigned int));
	if (obj->str[obj->i_str] == 'i')
		ft_putnbr(va_arg(ap, int));
	if (obj->str[obj->i_str] == 'u')
		ft_putnbr(va_arg(ap, unsigned int));
	if (obj->str[obj->i_str] == 'x')
		ft_putnbr(va_arg(ap, unsigned int));
	if (obj->str[obj->i_str] == 'X')
		ft_putnbr(va_arg(ap, unsigned int));
	if (obj->str[obj->i_str] == 'f')
		ft_putnbr(va_arg(ap, unsigned int));
	if (obj->str[obj->i_str] == 'p')
		ft_putnbr(va_arg(ap, unsigned int));
	if (obj->str[obj->i_str] == '%')
		ft_putnbr(va_arg(ap, unsigned int));
}








void	parse_general(t_pf_object *obj, va_list ap)
{
	// this could send to different functions depending on format specifier.
	char	*flags;
	// char	*length;
	// char	*specifier;

	flags = "#0- +";
	// length = "lh"; <-- no needed
	// specifier = "cspdiouxXf%";
	
	while (obj->str[obj->i_str + 1] != ' ' && obj->str[obj->i_str + 1] != 0)
	{
		if (ft_strchr(flags, obj->str[obj->i_str]))
			parse_flags(obj);
		// if (ft_strchr(obj->str[obj->i_str] == '.'))
		// 	parse_precision(obj);
		// if (ft_isdigit(obj->str[obj->i_str]))
		// 	parse_width(obj);
		// if (ft_strchr(length, obj->str[obj->i_str]))
		// 	parse_length(obj);
		++obj->i_str;
	}
	// if (ft_strchr(specifier, obj->str[obj->i_str]))
	// 	parse_specifier(obj, ap);
}











void	print_output(t_pf_object *obj)
{

}















int		ft_printf(const char * restrict format, ...)
{
	long long	i;
	// va_list		ap;
	t_pf_object	obj;

	ft_bzero(&obj, sizeof(obj));
	obj.str = format;
	i = 0;
	va_start(obj.ap, format);
	while (obj.str[obj.i_str] != 0)
	{
		if (obj.str[obj.i_str] == '%')
		{
			++obj.i_str;
			// parse_general(&obj, obj.ap);
			parse_flags(&obj);
			// print_output(&obj);
		}
		/*
			a buffer func should be called where ft_putchar is, which loads buffer and when full prints output.
		 */
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