/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:44:37 by wteles-d          #+#    #+#             */
/*   Updated: 2023/04/20 16:47:03 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	ft_spec_strcpy(char *dst, const char *src, int i)
{
	size_t	j;

	j = 0;
	while (src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*p;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	p = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (p == NULL)
		return (p);
	i = ft_spec_strcpy(p, s1, i);
	i = ft_spec_strcpy(p, s2, i);
	p[i] = '\0';
	return (p);
}
