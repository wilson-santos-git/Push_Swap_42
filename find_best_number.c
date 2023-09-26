/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:44:06 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/26 16:11:44 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_utils	init_list_utils(t_main *main)
{
	t_list_utils	util;

	util.rev_rot_a = false;
	util.rev_rot_b = false;
	util.cheapest_content = 0;
	util.moves_a = main->lista_a->size + 1;
	util.moves_b = main->lista_b->size + 1;
	util.max_number = main->lista_b->head->content;
	util.min_number = main->lista_b->head->content;
	return (util);
}

t_list_utils	find_cheapest_node(t_main *main)
{
	t_list_utils	best;
	t_list_utils	curr;
	int				i;
	t_node			*temp_node;

	temp_node = main->lista_b->head;
	best = init_list_utils(main);
	find_max_min(main->lista_a, &best);
	curr = best;
	i = 0;
	while (i < main->lista_b->size)
	{
		curr.rev_rot_a = false;
		curr.rev_rot_b = false;
		curr.moves_b = rectify_counter(main->lista_b->size, i, &curr, false);
		curr.moves_a = \
		count_moves(main->lista_a, temp_node->content, &best, &curr);
		curr.cheapest_content = temp_node->content;
		if (curr.moves_a + curr.moves_b
			< best.moves_a + best.moves_b)
			best = curr;
		i++;
		temp_node = temp_node->next;
	}
	return (best);
}
