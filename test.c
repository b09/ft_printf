/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/13 18:59:41 by bprado         #+#    #+#                */
/*   Updated: 2019/11/26 22:18:19 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{

	char *str = "hello";
	// printf(" <--%d\n", ft_printf("%#05x", 42));
	printf(" <--%d\n", ft_printf("%#0.5x", 42));
	printf("\n");
	// printf(" <--%d\n", printf("%#05x", 42));
	printf(" <--%d\n", printf("%#0.5x", 42));


	return (0);
}
