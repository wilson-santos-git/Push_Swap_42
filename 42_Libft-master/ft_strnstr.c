/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:33:53 by wteles-d          #+#    #+#             */
/*   Updated: 2023/04/18 17:56:13 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strnstr(const char	*haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)haystack);
	else
	{
		while (haystack[i] != '\0' && i < len)
		{
			j = 0;
			while (haystack[i + j] == needle[j] && (i + j) < len)
			{
				if (needle[j] == '\0')
					return ((char *)haystack + i);
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)haystack + i);
			i++;
		}
	}
	return (NULL);
}
