/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:54:37 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/27 16:45:18 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_spec_strcpy(char *dst, char *src, int i)
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

char	*new_strjoin(char *s1, char *s2)
{
	int		i;
	char	*p;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	p = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 2, 1);
	if (p == NULL)
		return (p);
	i = my_spec_strcpy(p, s1, i);
	p[i] = ' ';
	i++;
	i = my_spec_strcpy(p, s2, i);
	p[i] = '\0';
	return (p);
}

char	**ft_joinsplit(int argc, char **argv)
{
	int		i;
	char	*str;

	str = argv[0];
	if (argc < 3)
		return (argv);
	i = 1;
	while (argv[i])
	{
		str = new_strjoin(str, argv[i]);
		i++;
	}
	return (ft_split(str, ' '));
}

