/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_base.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/21 23:49:35 by bprado         #+#    #+#                */
/*   Updated: 2019/10/23 18:30:45 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long n, int base)
{
	char			a;
	long long		i;

	if (n < 0)
	{
		n = -n;
		// write(1, "-", 1);
	}
	i = n;
	if (i > (base - 1))
	{
		ft_putnbr_base(i / base, base);
		ft_putnbr_base(i % base, base);
	}
	if (i <= (base - 1) && i < 10)
	{
		a = '0' + i;
		write(1, &a, 1);
	}
	else if (i > 9 && i < 16 && base > 10)
	{
		a = 'a' + i - 10;
		write(1, &a, 1);
	}
}