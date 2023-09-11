/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pocaralho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 23:15:16 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/11 19:30:45 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_max_min(t_lista *lista, t_list_utils *best)
{
	int		i;
	t_node	*current_node;

	current_node = lista->head;
	best->max_number = lista->head->content;
	best->min_number = lista->head->content;
	i = 0;
	while (i < lista->size)
	{
		if (current_node->content > best->max_number)
		{
			best->max_number = current_node->content;
		}
		else if (current_node->content < best->min_number)
		{
			best->min_number = current_node->content;	
		}
		current_node = current_node->next;
		i++;
	}
}

int	get_correct_counter(int size, int counter, t_list_utils *current, bool is_rot_b)
{
	
	if (counter >= size / 2)
	{
		if (is_rot_b)
			current->rev_rot_b = true;
		else
			current->rev_rot_a = true;
		counter = size - counter;
	}
	return (counter);
}

int	count_moves(t_lista	*lista, int	current_number_a, t_list_utils *best, t_list_utils *current)
{
	int		counter;
	t_node *temp_node;
	(void) current;
	
	counter = 0;
	temp_node = lista->head;
	if (current_number_a > best->max_number)
	{
		while (counter < lista->size && temp_node->content != best->max_number)
		{
			temp_node = temp_node->next;
			counter++;
		}
	}
	else if (current_number_a < best->min_number)
	{
		while (counter < lista->size && temp_node->content != best->max_number)
		{
			temp_node = temp_node->next;
			counter++;
		}
	}
	else
	{
		while (counter < lista->size)
		{
			if (current_number_a < temp_node->previous->content
				&& current_number_a > temp_node->content)
				break ;
			temp_node = temp_node->next;
			counter++;
		}
	}
	return (get_correct_counter(lista->size, counter, current, true));
}

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

	temp_node = main->lista_a->head;
	best = init_list_utils(main);
	find_max_min(main->lista_b, &best);
	current = best;
	counter = 0;
	while (counter < main->lista_a->size)
	{
		current.rev_rot_a = false;
		current.rev_rot_b = false;
		current.cheapest_rots_a = get_correct_counter(main->lista_a->size, counter, &current, false);
		current.cheapest_rots_b = count_moves(main->lista_b, temp_node->content, &best, &current);
		current.cheapest_content = temp_node->content;
		if (current.cheapest_rots_a + current.cheapest_rots_b
			< best.cheapest_rots_a + best.cheapest_rots_b)
			best = current;
		counter++;
		temp_node = temp_node->next;
	}
	return (best);
}

void	sorting_algorithm(t_main *main)
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
		while (best.cheapest_rots_a > 0)
		{
			if (best.rev_rot_a == true)
				rra(main->lista_a);
			else
				ra(main->lista_a);
			best.cheapest_rots_a--;
		}
		while (best.cheapest_rots_b > 0)
		{
			if (best.rev_rot_b == true)
				rrb(main->lista_b);
			else
				rb(main->lista_b);
			best.cheapest_rots_b--;
		}
		pb(main);
	}
	while (main->lista_b->head->content != best.max_number)
	{
		int		i;
		t_node	*temp_node;
		
		temp_node = main->lista_b->head;
		while (temp_node->content != best.max_number)
		{
			temp_node = temp_node->next;
			i++;
		}
		if (i > main->lista_b->size / 2)
			rrb(main->lista_b);
		else
			rb(main->lista_b);
	}
	while (main->lista_b->size > 0)
		pa(main);
}