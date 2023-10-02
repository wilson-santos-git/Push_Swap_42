/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:31:10 by wteles-d          #+#    #+#             */
/*   Updated: 2023/10/02 17:58:39 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	total;
	int	n;

	i = 0;
	total = 0;
	n = 1;
	if (!nptr)
		return (0);
	while (nptr[i] != '\0' && ft_isspace(nptr[i]))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			n = -n;
		i++;
	}
	while (nptr[i] != '\0' && (nptr[i] < 58 && nptr[i] > 47))
	{
		total = total * 10 + nptr[i] - '0';
		i++;
	}
	return (total * n);
}

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
