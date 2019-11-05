/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bprado <bprado@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 17:51:21 by bprado        #+#    #+#                 */
/*   Updated: 2019/01/24 18:59:36 by bprado        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strjoin2(char const *s1, char const *s2, char *s3)
{
	while (*s1 != 0)
	{
		*s3 = *s1;
		s3++;
		s1++;
	}
	while (*s2 != 0)
	{
		*s3 = *s2;
		s3++;
		s2++;
	}
	return (s3);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
		++i;
	while (s2[j] != 0)
		++j;
	s3 = (char*)malloc(i + j + 1);
	if (!s3)
		return (NULL);
	if (*s1 != 0 || *s2 != 0)
		s3 = ft_strjoin2(s1, s2, s3);
	*s3 = 0;
	return (&s3[-(i + j)]);
}
