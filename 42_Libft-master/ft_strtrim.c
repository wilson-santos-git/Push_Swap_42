/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:20:21 by wteles-d          #+#    #+#             */
/*   Updated: 2023/04/21 16:40:48 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	if (!s1[i])
		return (ft_strdup(s1 + i));
	j = ft_strlen(s1);
	while (j != i && ft_strchr(set, s1[j]))
		j--;
	p = (char *)ft_calloc(j - i + 2, 1);
	if (p == NULL)
		return (p);
	ft_strlcpy(p, s1 + i, j - i + 2);
	return (p);
}
