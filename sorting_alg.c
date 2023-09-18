/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:55:26 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/18 16:34:06 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_rotations(t_main **main, t_list_utils *best)
{
	while (best->cheapest_rots_a > 0)
	{
		if (best->rev_rot_a == true)
			rra((*main)->lista_a);
		else
			ra((*main)->lista_a);
		best->cheapest_rots_a--;
	}
	while (best->cheapest_rots_b > 0)
	{
		if (best->rev_rot_b == true)
			rrb((*main)->lista_b);
		else
			rb((*main)->lista_b);
		best->cheapest_rots_b--;
	}
}

void	final_sort(t_main **main, t_list_utils best)
{
	int		i;
	t_node	*temp_node;

	i = 0;
	temp_node = (*main)->lista_b->head;
	while ((*main)->lista_b->head->content != best.max_number)
	{
		i = 0;
		temp_node = (*main)->lista_b->head;
		while (temp_node->content != best.max_number)
		{
			temp_node = temp_node->next;
			i++;
		}
		if (i > (*main)->lista_b->size / 2)
			rrb((*main)->lista_b);
		else
			rb((*main)->lista_b);
	}
	while ((*main)->lista_b->size > 0)
		pa((*main));
}

void	init_alg(t_main *main)
{
	t_list_utils	best;
	
	pb(main);
	pb(main);
	while (main->lista_a->size > 0)
	{
		best = find_cheapest_node(main);
		while (best.cheapest_rots_a > 0 && best.cheapest_rots_b > 0 && best.rev_rot_a == best.rev_rot_b)
		{
			if (best.rev_rot_a)
				rrr(main->lista_a, main->lista_b);
			else
				rr(main->lista_a, main->lista_b);
			best.cheapest_rots_a--;
			best.cheapest_rots_b--;
		}
		single_rotations(&main, &best);
		pb(main);
	}
	final_sort(&main, best);
}
