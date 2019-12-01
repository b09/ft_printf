/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 18:59:41 by bprado         #+#    #+#                */
/*   Updated: 2019/12/01 21:58:51 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>

int		main(void)
{
	float f = 156489753252.0368168;
	f = 0;




	f = -0.0;

	printf(" <--%d padding 20f \n", printf("%20f", 1.06));
	printf(" <--%d padding -20f \n", printf("%-20f", 1.06));
	printf(" <--%d padding -20d \n", ft_printf("%-20d", 10000));

	// printf(" <--%d d\n", ft_printf("%5d", -42));
	// printf(" <--%d d\n", printf("%5d", -42));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%-5d", -42));
	// printf(" <--%d d\n", printf("%-5d", -42));
	// printf("\n");
	
	// printf(" <--%d d\n", ft_printf("%-05d", -42));
	// printf(" <--%d d\n", printf("%-05d", -42));
	// printf("\n");



	// printf(" <--%d d\n", ft_printf("%+10.5d", 42));
	// printf(" <--%d d\n", printf("%+10.5d", 42));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%lld", -9223372036854775808));
	// printf(" <--%d d\n", printf("%lld", -9223372036854775808));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%+10.5d", 4242));
	// printf(" <--%d d\n", printf("%+10.5d", 4242));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%0+5d", 42));
	// printf(" <--%d d\n", printf("%0+5d", 42));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%+5d", 0));
	// printf(" <--%d d\n", printf("%+5d", 0));
	// printf("\n");
	
	// printf(" <--%d d\n", ft_printf("%-+10.5d", 4242));
	// printf(" <--%d d\n", printf("%-+10.5d", 4242));
	// printf("\n");
	
	// printf(" <--%d d\n", ft_printf("%lu", -42));
	// printf(" <--%d d\n", printf("%lu", -42));
	// printf("\n");

	// printf(" <--%d c\n", ft_printf("% c", 0));
	// printf(" <--%d c\n", printf("% c", 0));
	// printf("\n");

	// printf(" <--%d s\n", ft_printf("%.12s", NULL));
	// printf(" <--%d s\n", printf("%.12s", NULL));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%+5.4d", 42));
	// printf(" <--%d d\n", printf("%+5.4d", 42));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("% d", -42));
	// printf(" <--%d d\n", printf("% d", -42));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%0+5d", -42));
	// printf(" <--%d d\n", printf("%0+5d", -42));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("% 10.15d", 4242));
	// printf(" <--%d d\n", printf("% 10.15d", 4242));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("% 10.5d", 4242));
	// printf(" <--%d d\n", printf("% 10.5d", 4242));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%+10.15d", -42));
	// printf(" <--%d d\n", printf("%+10.15d", -42));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%+10.5d", -42));
	// printf(" <--%d d\n", printf("%+10.5d", -42));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%03.2d", 0));
	// printf(" <--%d d\n", printf("%03.2d", 0));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%03.2d", 1));
	// printf(" <--%d d\n", printf("%03.2d", 1));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("%3.2d", 1));
	// printf(" <--%d d\n", printf("%3.2d", 1));
	// printf("\n");

	// printf(" <--%d d\n", ft_printf("@moulitest: %.10d", -42));
	// printf(" <--%d d\n", printf("@moulitest: %.10d", -42));
	// printf("\n");

	// printf(" <--%d x\n", ft_printf("%#08x", 42));
	// printf(" <--%d x\n", printf("%#08x", 42));
	// printf("\n");
	// printf(" <--%d o\n", ft_printf("%#.0o", 0));
	// printf(" <--%d o\n", printf("%#.0o", 0));
	// printf("\n");
	// printf(" <--%d p\n", ft_printf("%025p", 42));
	// printf(" <--%d p\n", printf("%025p", 42));
	// printf("\n");
	// printf(" <--%d X\n", ft_printf("%-5.20X", 42));
	// printf(" <--%d X\n", printf("%-5.20X", 42));
	// printf("\n");
	// printf(" <--%d\n", printf("%#05x", 42));


	return (0);
}
