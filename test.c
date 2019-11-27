/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 18:59:41 by bprado         #+#    #+#                */
/*   Updated: 2019/11/28 00:23:07 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{

	// char *str = "hello";
	// printf(" <--%d\n", ft_printf("%#05x", 42));
	printf(" <--%d c\n", ft_printf("%.12c", NULL));
	printf(" <--%d c\n", printf("%.12c", NULL));
	printf("\n");
	printf(" <--%d d\n", ft_printf("%+10.5d", -42));
	printf(" <--%d d\n", printf("%+10.5d", -42));
	printf("\n");
	printf(" <--%d x\n", ft_printf("%#08x", 42));
	printf(" <--%d x\n", printf("%#08x", 42));
	printf("\n");
	printf(" <--%d o\n", ft_printf("%#.0o", 0));
	printf(" <--%d o\n", printf("%#.0o", 0));
	printf("\n");
	printf(" <--%d p\n", ft_printf("%025p", 42));
	printf(" <--%d p\n", printf("%025p", 42));
	printf("\n");
	printf(" <--%d X\n", ft_printf("%-5.20X", 42));
	printf(" <--%d X\n", printf("%-5.20X", 42));
	printf("\n");
	// printf(" <--%d\n", printf("%#05x", 42));


	return (0);
}
