/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:55:26 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/26 00:23:11 by wteles-d         ###   ########.fr       */
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
	temp_node = (*main)->lista_a->head;
	while ((*main)->lista_a->head->content != best.min_number)
	{
		i = 0;
		temp_node = (*main)->lista_a->head;
		while (temp_node->content != best.max_number)
		{
			temp_node = temp_node->next;
			i++;
		}
		if (i > (*main)->lista_a->size / 2)
			rra((*main)->lista_a);
		else
			ra((*main)->lista_a);
	}
}

void	init_alg(t_main *main)
{
	int				gap;
	t_list_utils	best;
	
	gap = 0;
	if (main->lista_a->size >= 100)
		gap = 65;
	else if (main->lista_a->size >= 450)
		gap = 88;
	while (main->lista_a->size > 2)
	{
		if (main->lista_a->head->id >= (main->lista_a->size - gap))
			pb(main);
		else
			ra(main->lista_a);
	}
	
	while (main->lista_b->size > 0)
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
		pa(main);
	}
	final_sort(&main, best);
}
