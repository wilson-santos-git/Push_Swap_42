/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:45:12 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/28 17:06:12 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_algorithm(t_main *main)
{
	while (1)
	{
		if ((main->lista_a->head->content)
			> (main->lista_a->head->next->content))
			do_ra(main->lista_a);
		else
			do_pb(main);
		if (!main->lista_b->head)
		{
			do_pa(main);
			if (!main->lista_b->head)
				break ;
		}
	}
	printf("!!! DONE !!!\n");
}
