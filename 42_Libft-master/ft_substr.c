/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 18:01:16 by wteles-d          #+#    #+#             */
/*   Updated: 2023/04/21 15:17:45 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;
	size_t	slen;

	i = start;
	j = 0;
	slen = ft_strlen(s);
	if (!s && !len)
		return (NULL);
	if (start >= slen)
		return (ft_strdup(""));
	slen = slen - i + 1;
	if (slen > len)
		slen = len + 1;
	p = (char *)ft_calloc(slen, 1);
	if (!p)
		return (NULL);
	while (j < len && s[j])
		p[j++] = s[i++];
	p[j] = '\0';
	return (p);
}
