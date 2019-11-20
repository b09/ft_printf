/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   play_with_printf.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 18:59:41 by bprado         #+#    #+#                */
/*   Updated: 2019/11/20 23:46:57 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		main(void)
{
	char *str = "hello";
	long double num = 3.14159265358979323;
	int num2 = 5926;
	int num3 = 1;
	t_pf_object str2;
	int bitmask = 8;


	char *flags;
	
	flags = "#0- +";


	char *pstr = "This will be a long enough string to be different";

	int number = 0;
	long double ddd = 3.556468404;
	// number = 1;
	// number = number << 31;
	// number = 1023;
	// number = 255;
	// printf("float:    %.200Lf\n", ddd);
	// ft_printf("ft octal: %.200Lf\n", ddd);

	typedef union s_value
	{
		long double dvalue;
		char		cvalue;
	}		f_value;

	f_value example;
	example.cvalue = 1;
	number = 10;
	// what is the return value of printf if there is width with zero precision?

	printf("%d\n", ft_printf("%-010dend\n", number));
	// printf("%d\n", ft_printf("%cend\n", number));
	// printf("char: %.15000Lf\n", example.dvalue);
	// ft_printf("char: %.15000Lf\n", example.dvalue);
	// ft_printf("string13:%20.13s\n", "hello world");
	// printf("string13:%20.13s\n\n", "hello world");

	// printf("%d\n", ft_printf("%25s\n", "hello world again"));
	// printf("%d\n", printf("%25s\n", "hello world again"));
	return (0);
}

// length of output without malloc
// write a function which returns the lenght of integer variables

/*
	buffer holds numbeer
	size_of_number() subtracted from obj.width
	 

 */










/*
	0011
	0110
	nothing comes after format specifier letters (ex: %f4.4 will ignore the 4.4)
*/


// void	ft_putnbr2(int n)
// {
// 	char			a;
// 	unsigned int	i;

// 	if (n < 0)
// 	{
// 		n = -n;
// 		write(1, "-", 1);
// 	}
// 	i = n;
// 	if (i > 9)
// 	{
// 		ft_putnbr(i / 10);
// 		ft_putnbr(i % 10);
// 	}
// 	if (i <= 9)
// 	{
// 		a = '0' + i;
// 		write(1, &a, 1);
// 	}
// }

// use sizeof the measure size of parameter
// the type of the parameter does not matter 

void	ft_putnbr2(long long n)
{
	char			a;
	long long 	i;

	// printf("lld: %lld\n", n);

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	i = n;
	if (i > 9)
	{
		ft_putnbr2(i / 10);
		ft_putnbr2(i % 10);
	}
	if (i <= 9)
	{
		a = '0' + i;
		write(1, &a, 1);
	}
}