/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_argv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:54:37 by wteles-d          #+#    #+#             */
/*   Updated: 2023/10/02 18:20:40 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_spec_strcpy(char *dst, char *src, int i)
{
	size_t	j;

	j = 0;
	if (!src)
		return (0);
	while (src[j])
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
	p = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1 + (s1 != NULL)), 1);
	if (p == NULL)
		return (p);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	if (s1)
		p[i++] = ' ';
	while (s2 && *s2)
		p[i++] = *s2++;
	p[i] = '\0';
	return (p);
}

t_split_args	ft_joinsplit(int argc, char **argv)
{
	int				i;
	char			*str;
	char			*str_tmp;
	t_split_args	temp;

	temp.count = argc;
	temp.strings = argv;
	if (argc < 3)
		return (temp);
	str = argv[0];
	i = 1;
	while (argv[i])
	{
		str_tmp = str;
		str = new_strjoin(str, argv[i]);
		if(i > 1)
			free(str_tmp);
		i++;
	}
	temp.count = i;
	temp.strings = __ft_split(str, ' ');
	free(str);
	return (temp);
}
