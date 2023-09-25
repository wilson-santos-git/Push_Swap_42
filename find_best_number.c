/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:06 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/25 23:58:47 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_utils	init_list_utils(t_main *main)
{
	t_list_utils	util;
	
	util.rev_rot_a = false;
	util.rev_rot_b = false;
	util.cheapest_content = 0;
	util.cheapest_rots_a = main->lista_a->size + 1;
	util.cheapest_rots_b = main->lista_b->size + 1;
	util.max_number = main->lista_b->head->content;
	util.min_number = main->lista_b->head->content;
	return (util);
}

t_list_utils	find_cheapest_node(t_main *main)
{
	t_list_utils	best;
	t_list_utils	current;
	int				counter;
	t_node			*temp_node;

	temp_node = main->lista_b->head;
	best = init_list_utils(main);
	find_max_min(main->lista_a, &best);
	current = best;
	counter = 0;
	while (counter < main->lista_b->size)
	{
		current.rev_rot_a = false;
		current.rev_rot_b = false;
		current.cheapest_rots_b = get_correct_counter(main->lista_b->size, counter, &current, false);
		current.cheapest_rots_a = count_moves(main->lista_a, temp_node->content, &best, &current);
		current.cheapest_content = temp_node->content;
		if (current.cheapest_rots_a + current.cheapest_rots_b
			< best.cheapest_rots_a + best.cheapest_rots_b)
			best = current;
		counter++;
		temp_node = temp_node->next;
	}
	return (best);
}
