/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:45:12 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/28 18:05:42 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_algorithm(t_main *main)
{
	while (1)
	{
		if (((main->lista_a->head->content)
				> (main->lista_a->head->next->content))
			&& main->lista_a->size > 1)
			do_ra(main->lista_a);
		else if (main->lista_a->head)
			do_pb(main);
		if (!main->lista_a->head)
		{
			printf("uh\n");
			while (main->lista_b->head)
				do_pa(main);
			break ;
		}
		print_lists(main);
	}
	printf("!!! DONE !!!\n");
}
