/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 18:59:41 by bprado         #+#    #+#                */
/*   Updated: 2019/12/13 19:37:54 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <math.h>
#include <float.h>
#include <limits.h>

int		main(void)
{
	float f = 156489753252.0368168;
	f = 0;

	f = ft_pow(2.0, 8.0);


	// int n;
	// ft_printf("%s: %nFoo\n", "hello", &n);
	// ft_printf("%*sBar\n", n, "");

// testing line 121 on specifier_functions on no_minus_flag()


	printf("<--%d ft_printf\n", ft_printf("%#4.5x", 0xeaef));
	printf("<--%d printf\n", printf("%#4.5x", 0xeaef));
	printf("\n");

	printf("<--%d ft_printf\n", ft_printf("%#.5x", 0xeaef));
	printf("<--%d printf\n", printf("%#.5x", 0xeaef));
	printf("\n");

	printf("<--%d ft_printf\n", ft_printf("%#7x", 0xeaef));
	printf("<--%d printf\n", printf("%#7x", 0xeaef));
	printf("\n");

	printf("<--%d ft_printf\n", ft_printf("%#010.f", 546.3929));
	printf("<--%d printf\n", printf("%#010.f", 546.3929));
	printf("\n");

	printf("<--%d ft_printf\n", ft_printf("%#09.10X", 5463929));
	printf("<--%d printf\n", printf("%#09.10X", 5463929));
	printf("\n");

	printf("<--%d ft_printf\n", ft_printf("%#09.10x", 5463929));
	printf("<--%d printf\n", printf("%#09.10x", 5463929));
	printf("\n");

	printf("<--%d ft_printf\n", ft_printf("%#09.10p", 5463929));
	printf("<--%d printf\n", printf("%#09.10p", 5463929));
	printf("\n");

	printf("<--%d ft_printf\n", ft_printf("%#09.10o", 5463929));
	printf("<--%d printf\n", printf("%#09.10o", 5463929));
	printf("\n");

	printf("<--%d ft_printf\n", ft_printf("%#0.10X", 5463929));
	printf("<--%d printf\n", printf("%#0.10X", 5463929));
	printf("\n");
	
	printf("<--%d ft_printf\n", ft_printf("%.1u %5.3u", 10, 10));
	printf("<--%d printf\n", printf("%.1u %5.3u", 10, 10));
	printf("\n");

	// while (1)
	// {
	// 	if (getchar())
	// 		exit (0);
	// }


	// printf(" <--%d ft_printf\n", ft_printf("%#o", 0));
	// printf(" <--%d printf\n", printf("%#o", 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%#4o", 0));
	// printf(" <--%d printf\n", printf("%#4o", 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%#-4o", 0));
	// printf(" <--%d printf\n", printf("%#-4o", 0));
	// printf("\n");
	// printf(" <--%d ft_printf\n", ft_printf("%#o", 0));
	// printf(" <--%d printf\n", printf("%#o", 0));
	// printf("\n");
	
	// printf(" <--%d ft_printf\n", ft_printf("%ld", LONG_MIN));
	// printf(" <--%d printf\n", printf("%ld", LONG_MIN));
	// printf("\n");
	
	// printf(" <--%d ft_printf\n", ft_printf("%lld", LLONG_MIN));
	// printf(" <--%d printf\n", printf("%lld", LLONG_MIN));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("% 03d", 0));
	// printf(" <--%d printf\n", printf("% 03d", 0));
	// printf("\n");

	// // printf(" <--%d printf\n", printf("%.5c", 42)); // bullshit
	// // printf(" <--%d printf\n", ft_printf("%.5c", 42));
	// // printf("\n");

	// // printf(" <--%d printf\n", printf("%.5p", 0)); // bullshit
	// // printf(" <--%d printf\n", ft_printf("%.5p", 0));
	// // printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%-#5.0o", 0));
	// printf(" <--%d printf\n", printf("%-#5.*o", 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%#.o, %#.0o", 0, 0));
	// printf(" <--%d printf\n", printf("%#.o, %#.0o", 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%s", "42"));
	// printf(" <--%d printf\n", printf("%.*s", -5, "42"));
	// printf("\n");

	// // printf(" <--%d printf\n", printf("%*3d", 5, 0));  // bullshit
	// // printf(" <--%d printf\n", ft_printf("%*3d", 5, 0));
	// // printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%#.o %#.0o", 0, 0));
	// printf(" <--%d printf\n", printf("%#.o %#.0o", 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("% 5.0f", -7.3));
	// printf(" <--%d printf\n", printf("% 5.0f", -7.3));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("% 5.1f", -7.3));
	// printf(" <--%d printf\n", printf("% 5.1f", -7.3));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("% -5.0f", -7.3));
	// printf(" <--%d printf\n", printf("% -5.0f", -7.3));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("% -5.1f", -7.3));
	// printf(" <--%d printf\n", printf("% -5.1f", -7.3));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%Lf", -56.2012685l));
	// printf(" <--%d printf\n", printf("%Lf", -56.2012685l));
	// printf("\n");

	// passing 1203 A test
	// printf(" <--%d \n", ft_printf("%.f", 1.6));
	// printf(" <--%d \n", printf("%.f", 1.6));
	// printf(" <--%d \n", ft_printf("%.0f", 1.6));
	// printf(" <--%d \n", printf("%.0f", 1.6));

	// printf(" <--%d ft_printf\n", ft_printf("%f", -3.85));
	// printf(" <--%d printf\n", printf("%f", -3.85));
	// printf("\n");


	// printf(" <--%d ft_printf\n", ft_printf("%.*x", 20, 142424242));
	// printf(" <--%d printf\n", printf("%.*x", 20, 142424242));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%#.*x", 15, 142424242));
	// printf(" <--%d printf\n", printf("%#.*x", 15, 142424242));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%#*p", 20, "142424242"));
	// printf(" <--%d printf\n", printf("%#*p", 20, "142424242"));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%#.*X", 20, 142424242));
	// printf(" <--%d printf\n", printf("%#.*X", 20, 142424242));
	// printf("\n");
	// printf(" <--%d ft_printf\n", ft_printf("%.o %.o", 0, 0));
	// printf(" <--%d printf\n", printf("%.o %.o", 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%o", 142424242));
	// printf(" <--%d printf\n", printf("%.o %.o", 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%.o %.o", 0, 0));
	// printf(" <--%d ft_printf\n", printf("%.o %.o", 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%-#*.*o", 5, 0, 0));
	// printf(" <--%d printf\n", printf("%-#*.*o", 5, 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%-#*.*x", 0, 0, 0));
	// printf(" <--%d printf\n", printf("%-#*.*x", 0, 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%-#*.*o", 0, 0, 0));
	// printf(" <--%d printf\n", printf("%-#*.*o", 0, 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%-*.*o", 0, 0, 0));
	// printf(" <--%d printf\n", printf("%-*.*o", 0, 0, 0));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%#*.9X", 20, 142424242));
	// printf(" <--%d printf\n", printf("%#*.9X", 20, 142424242));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%*.9X", 20, 142424242));
	// printf(" <--%d printf\n", printf("%*.9X", 20, 142424242));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%020.10f", (double)-((double)10 / 3)));
	// printf(" <--%d printf\n", printf("%020.10f", (double)-((double)10 / 3)));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%+020.10f", (double)((double)10 / 3)));
	// printf(" <--%d printf\n", printf("%+020.10f", (double)((double)10 / 3)));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%+.60f", (double)((double)10 / 3)));
	// printf(" <--%d printf\n", printf("%+.60f", (double)((double)10 / 3)));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%- .0f", (double)9.5));
	// printf(" <--%d printf\n", printf("%- .0f", (double)9.5));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%.7f", 0.999999));
	// printf(" <--%d printf\n", printf("%.7f", 0.999999));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%f", 0.000039));
	// printf(" <--%d printf\n", printf("%f", 0.000039));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%-5.1f", 7.3));
	// printf(" <--%d printf\n", printf("%-5.1f", 7.3));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%+5.1f", 7.3));
	// printf(" <--%d printf\n", printf("%+5.1f", 7.3));
	// printf("\n");

	// printf(" <--%d ft_printf\n", ft_printf("%+5.10f", 7.3));
	// printf(" <--%d printf\n", printf("%+5.10f", 7.3));
	// printf("\n");
	// // printf(" <--%d ft_printf\n", ft_printf("%f", 5665.9999999));
	// // printf(" <--%d printf\n", printf("%f", 5665.9999999));

	// printf(" <--%d ft_printf\n", ft_printf("%0*.*d", -5, -7, 42));
	// printf(" <--%d printf\n", printf("%0*.*d", -5, -7, 42));
	// printf("\n");

    // printf("printf:		[%+020.10f]\n", (double)((double)10 / 3));
	// ft_printf("ft_printf:	[%+020.10f]\n", (double)((double)10 / 3));
	// printf("\n");

    // printf("printf:		[%-f]\n", -0.0);
	// ft_printf("ft_printf:	[%-f]\n", -0.0);
	// printf("\n");

    // printf("printf:		[%-10f]\n", 0.0 / 0.0);
	// ft_printf("ft_printf:	[%-10f]\n", 0.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%-10.10f]\n", -1.0 / 0.0);
	// ft_printf("ft_printf:	[%-10.10f]\n", -1.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%-f]\n", 1.0 / 0.0);
	// ft_printf("ft_printf:	[%-f]\n", 1.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%-10.10f]\n", 1.0 / 0.0);
	// ft_printf("ft_printf:	[%-10.10f]\n", 1.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%-f]\n", 0.0 / 0.0);
	// ft_printf("ft_printf:	[%-f]\n", 0.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%-10.10f]\n", 0.0 / 0.0);
	// ft_printf("ft_printf:	[%-10.10f]\n", 0.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%f]\n", -1.0 / 0.0);
	// ft_printf("ft_printf:	[%f]\n", -1.0 / 0.0);
	// printf("\n");
	
    // printf("printf:		[%10.10f]\n", -1.0 / 0.0);
	// ft_printf("ft_printf:	[%10.10f]\n", -1.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%f]\n", 1.0 / 0.0);
	// ft_printf("ft_printf:	[%f]\n", 1.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%10.10f]\n", 1.0 / 0.0);
	// ft_printf("ft_printf:	[%10.10f]\n", 1.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%f]\n", 0.0 / 0.0);
	// ft_printf("ft_printf:	[%f]\n", 0.0 / 0.0);
	// printf("\n");

    // printf("printf:		[%10.10f]\n", 0.0 / 0.0);
	// ft_printf("ft_printf:	[%10.10f]\n", 0.0 / 0.0);
	// printf("\n");
	
    // printf("printf:		[%.500lf]\n", DBL_TRUE_MIN);
	// ft_printf("ft_printf:	[%.500lf]\n", DBL_TRUE_MIN);
	// printf("\n");

    // printf("printf:		[%lf]\n", DBL_MAX);
	// ft_printf("ft_printf:	[%lf]\n", DBL_MAX);
	// printf("\n");

    // printf("printf:		[%.500lf]\n", DBL_MIN);
	// ft_printf("ft_printf:	[%.500lf]\n", DBL_MIN);
	// printf("\n");

    // printf("printf:		[%.200f]\n", FLT_TRUE_MIN);
	// ft_printf("ft_printf:	[%.200f]\n", FLT_TRUE_MIN);
	// printf("\n");

    // printf("printf:		[%lf]\n", FLT_MAX);
	// ft_printf("ft_printf:	[%lf]\n", FLT_MAX);
	// printf("\n");

    // printf("printf:		[%.200lf]\n", FLT_MIN);
	// ft_printf("ft_printf:	[%.200lf]\n", FLT_MIN);
	// printf("\n");


	// int64_t ulng = -1;
	// printf(" <--%d end \n", printf("pow %Lf", ft_pow(2.0, 3.0)));

	// printf(" <--%d end \n", ft_printf("%#.x %#.0x", 0, 0));
	// printf(" <--%d end \n", printf("%#.x %#.0x", 0, 0));
	// printf(" <--%d end \n", ft_printf("%#.p %.p", 0, 0));
	// printf(" <--%d end \n", printf("%#.p %.p", 0, 0));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%15X", 0));
	// printf(" <--%d end \n", printf("%15X", 0));
	// printf("\n");

	// char *yo = "yo";
	// printf(" <--%d end \n", ft_printf("%#18.15p", yo));
	// printf(" <--%d end \n", printf("%#18.15p", yo));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%18p", yo));
	// printf(" <--%d end \n", printf("%18p", yo));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%p", yo));
	// printf(" <--%d end \n", printf("%p", yo));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%.15p", yo));
	// printf(" <--%d end \n", printf("%.15p", yo));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%#u", 34));
	// printf(" <--%d end \n", printf("%#u", 34));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%0+5d", 42));
	// printf(" <--%d end \n", printf("%0+5d", 42));
	// printf("\n");


	// printf(" <--%d end \n", ft_printf("%05d", -42));
	// printf(" <--%d end \n", printf("%05d", -42));
	// printf("\n");


	// printf(" <--%d end \n", ft_printf("%0+5d", -42));
	// printf(" <--%d end \n", printf("%0+5d", -42));
	// printf("\n");


	// printf(" <--%d end \n", ft_printf("%6.5i", -84735555));
	// printf(" <--%d end \n", printf("%6.5i", -84735555));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%08.6i", -8473));
	// printf(" <--%d end \n", printf("%08.6i", -8473));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%10.5i", -216));
	// printf(" <--%d end \n", printf("%10.5i", -216));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%03.2d", -1));
	// printf(" <--%d end \n", printf("%03.2d", -1));
	// printf("\n");

  	// printf(" <--%d end \n", ft_printf("%5d", -42));
  	// printf(" <--%d end \n", printf("%5d", -42));
	// printf("\n");

  	// printf(" <--%d end \n", ft_printf("%-5d", -42));
  	// printf(" <--%d end \n", printf("%-5d", -42));
	// printf("\n");

  	// printf(" <--%d end \n", ft_printf("%-05d", -42));
  	// printf(" <--%d end \n", printf("%-05d", -42));
	// printf("\n");

  	// printf(" <--%d end \n", ft_printf("%03.2d", 0));
  	// printf(" <--%d end \n", printf("%03.2d", 0));
	// printf("\n");

  	// printf(" <--%d end \n", ft_printf("%+03.2d", 1));
  	// printf(" <--%d end \n", printf("%+03.2d", 1));
	// printf("\n");

	// printf(" <--%d end \n", ft_printf("%+5i", 35));
	// printf(" <--%d end \n", printf("%+5i", 35));
	// printf("\n");

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
	// printf(" <--%d\n", ft_printf("%ld", LONG_MIN));
	// printf(" <--%d\n", printf("%ld", LONG_MIN));


	return (0);
}
