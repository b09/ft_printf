/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   play_with_printf.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 18:59:41 by bprado         #+#    #+#                */
/*   Updated: 2019/11/05 18:02:20 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int		main(void)
{
	char *str = "hello";
	double num = 3.14159265358979323;
	int num2 = 5926;
	int num3 = 1;
	t_pf_object str2;
	int bitmask = 8;


	char *flags;
	
	flags = "#0- +";


	char *pstr = "This will be a long enough string to be different";

	long int number = num * 10000;

	// d -> print_number -> print_sign -> | <- print_padding -> length_of_number 

	printf("%d:<-end\n", number);
	// ft_printf("hello %10x", number);
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