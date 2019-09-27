/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchar.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 17:49:51 by bprado        #+#    #+#                 */
/*   Updated: 2019/01/18 12:55:16 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*s != 0)
	{
		if (*s == (unsigned char)c)
			return ((char*)s);
		s++;
	}
	if (c == 0)
		return ((char*)s);
	return (NULL);
}
