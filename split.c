/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 23:21:37 by wteles-d          #+#    #+#             */
/*   Updated: 2023/10/02 17:55:24 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	__ft_count_words(char const *s, char c)
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

int	__ft_size_word(char const *s, char c, int i)
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

void	__ft_free_all(char **p)
{
	while (p && *p)
		free(*p++);
	free (p);
}

int	__ft_alloc_word(char **p, char const *s, int i, char c)
{
	*p = ft_calloc((__ft_size_word(s, c, i) + 1), sizeof(char));
	if (!*p)
		return (0);
	ft_strlcpy(*p, s + i, (size_t)__ft_size_word(s, c, i) + 1);
	return (1);
}

char	**__ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**p;

	i = 0;
	j = 0;
	p = ft_calloc(((__ft_count_words(s, c)) + 1), sizeof(char *));
	if (!p || !s)
		return (p);
	while (s && s[i])
	{
		if (s[i] != c)
		{
			if (!(__ft_alloc_word(&p[j++], s, i, c)))
			{
				__ft_free_all(p);
				return (NULL);
			}
			i += __ft_size_word(s, c, i);
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

// char	**__split(char const *s, char c, int j, char **list)
// {
// 	char	*t;
// 	int		i;

// 	i = 0;
// 	t = 0;
// 	while (s && c == *s && *s)
// 		s++;
// 	while (s && s[i] != c && s[i])
// 		i++;
// 	if (i > 0)
// 		t = ft_calloc((i + 1), sizeof(char));
// 	if (i > 0)
// 		t[i] = 0;
// 	i = 0;
// 	while (s && t && s && *s != c && *s)
// 		t[i++] = *s++;
// 	if (++j >= 0 && i)
// 		list = __split(s, c, j, list);
// 	else if (!list)
// 		list = ft_calloc(j, sizeof(char *));
// 	if (list)
// 		list[--j] = t;
// 	return (list);
// }

// char	**ft_split(char const *s, char c)
// {
// 	return (__split(s, c, 0, 0));
// }