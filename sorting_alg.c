/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:55:26 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/29 16:59:28 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	single_rotations(t_main **main, t_list_utils *best)
{
	while (best->moves_a > 0 && (*main)->lista_a->size > 1)
	{
		if (best->rev_rot_a == true)
			rra((*main)->lista_a);
		else
			ra((*main)->lista_a);
		best->moves_a--;
	}
	while (best->moves_b > 0 && (*main)->lista_b->size > 1)
	{
		if (best->rev_rot_b == true)
			rrb((*main)->lista_b);
		else
			rb((*main)->lista_b);
		best->moves_b--;
	}
}

void	final_sort(t_main *main, t_list_utils best)
{
	int		i;
	t_node	*temp_node;

	i = 0;
	temp_node = main->lista_a->head;
	find_max_min(main->lista_a, &best);
	while (main->lista_a->head->content != best.min_number)
	{
		i = 0;
		temp_node = main->lista_a->head;
		while (temp_node->content != best.max_number)
		{
			temp_node = temp_node->next;
			i++;
		}
		if (i >= main->lista_a->size / 2)
			rra(main->lista_a);
		else
			ra(main->lista_a);
	}
}

void	gap_sort(t_main *main)
{
	int	gap;

	gap = main->lista_a->size;
	if (main->lista_a->size >= 100)
		gap = 65;
	else if (main->lista_a->size >= 300)
		gap = 87;
	while (main->lista_a->size > 2)
	{
		if (main->lista_a->head->id >= (main->lista_a->size - gap))
		{
			pb(main);
			if (main->lista_b->size == 3 && main->lista_b->head->content > main->lista_b->head->next->content)
				rb(main->lista_b);
		}
		else
			ra(main->lista_a);
	}
}

void	init_alg(t_main *main)
{
	t_list_utils	best;

	gap_sort(main);
	if (main->lista_b->size == 3 && is_sorted(main->lista_b))
	{
		sb(main->lista_b);
		rrb(main->lista_b);
	}
	while (main->lista_b->size > 0)
	{
		best = find_cheapest_node(main);
		while (best.moves_a > 0 && best.moves_b
			> 0 && best.rev_rot_a == best.rev_rot_b)
		{
			if (best.rev_rot_a)
				rrr(main->lista_a, main->lista_b);
			else
				rr(main->lista_a, main->lista_b);
			best.moves_a--;
			best.moves_b--;
		}
		single_rotations(&main, &best);
		pa(main);
	}
	final_sort(main, best);
}
