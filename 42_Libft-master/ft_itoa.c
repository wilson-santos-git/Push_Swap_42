/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 17:50:32 by wteles-d          #+#    #+#             */
/*   Updated: 2023/04/24 15:38:41 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	static char	p[13];
	int			j;
	long		nj;

	j = 11;
	p[12] = 0;
	p[11] = '0';
	nj = n;
	if (nj < 0)
		nj = -nj;
	while (nj != 0)
	{
		p[j] = (nj % 10 + '0');
		j--;
		nj /= 10;
	}
	if (n < 0)
		p[j--] = '-';
	return (ft_strdup(&p[j + (n != 0)]));
}
