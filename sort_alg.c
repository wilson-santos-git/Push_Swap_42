/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:45:12 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/30 18:25:07 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_algorithm(t_main *main)
{
	while (1)
	{
		while (main->lista_a->size > 0)
		{
			if (main->lista_a->size > 1 && ((main->lista_a->head->content)
					> (main->lista_a->head->next->content)))
				do_ra(main->lista_a);
			else if (main->lista_a->size > 0)
				do_pb(main);
			print_lists(main);
		}
		if (main->lista_a->size == 0)
		{
			while (main->lista_b->size > 0)
			{
				if (main->lista_b->size > 1
					&& (main->lista_b->head->content)
					< (main->lista_b->head->next->content))
					do_ra(main->lista_b);
				else if (main->lista_b->size > 0)
					do_pa(main);
				print_lists(main);
			}
			break ;
		}
	}
	printf("!!! DONE !!!\n");
}
