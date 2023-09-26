/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:51:59 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/26 17:52:52 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long int	ft_atol(char *nptr)
{
	long int	i;
	long int	total;
	long int	n;

	i = 0;
	n = 1;
	total = 0;
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
