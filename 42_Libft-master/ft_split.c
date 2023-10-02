/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 15:36:59 by wteles-d          #+#    #+#             */
/*   Updated: 2023/10/02 17:53:35 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	h;
	int	count;

	h = 0;
	count = 0;
	while (s && s[h])
	{
		if (s[h] == c)
		{
			while (s[h] == c && s[h])
				h++;
			count += (s[h] != '\0');
			continue;
		}
		else if(count == 0)
			count++;
		h++;
	}
	return (count);
}

int	size_word(char const *s, char c, int i)
{
	int	size;

	size = 0;
	while (s[i] != c && s[i])
	{
		i++;
		size++;
	}
	return (size);
}

void	ft_free_all(char **p)
{
	while (p && *p)
		free(*p++);
	free (p);
}

int	ft_alloc_word(char **p, char const *s, int i, char c)
{
	*p = malloc((size_word(s, c, i) + 1) * sizeof(char));
	if (!*p)
		return (0);
	ft_strlcpy(*p, s + i, (size_t)size_word(s, c, i) + 1);
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**p;

	i = 0;
	j = 0;
	p = ft_calloc(((ft_count_words(s, c)) + 1), sizeof(char *));
	if (!p || !s)
		return (p);
	while (s && s[i])
	{
		if (s[i] != c)
		{
			if (!(ft_alloc_word(&p[j++], s, i, c)))
			{
				ft_free_all(p);
				return (NULL);
			}
			i += size_word(s, c, i);
		}
		else
			i++;
	}
	return (p);
}

// int	main(void)
// {
// 	char	**str = ft_split("       olol", ' ');
// 	int		x = 0;
// 	while	(str[x])
// 	{		
// 		printf("%s\n", str[x]);
// 		x++;
// 	}
// }
