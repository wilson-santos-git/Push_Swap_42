/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:45:39 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/29 15:39:07 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_min_max(t_lista *lista, t_list_utils *best, int current_number_b)
{
	int		counter;
	t_node	*temp_node;

	counter = 0;
	temp_node = lista->head;
	if (current_number_b > best->max_number)
	{
		while (counter < lista->size && temp_node->content != best->min_number)
		{
			temp_node = temp_node->next;
			counter++;
		}
	}
	else if (current_number_b < best->min_number)
	{
		while (counter < lista->size && temp_node->content != best->min_number)
		{
			temp_node = temp_node->next;
			counter++;
		}
	}
	return (counter);
}

int	count_moves(t_lista *lista, int curr_b, \
t_list_utils *best, t_list_utils *current)
{
	int		counter;
	t_node	*temp_node;

	counter = 0;
	(void) current;
	temp_node = lista->head;
	if (curr_b > best->max_number || curr_b < best->min_number)
		counter = count_min_max(lista, best, curr_b);
	else
	{
		while (counter < lista->size)
		{
			if (curr_b > temp_node->previous->content
				&& curr_b < temp_node->content)
				break ;
			temp_node = temp_node->next;
			counter++;
		}
	}
	return (rectify_counter(lista->size, counter, current, true));
}

int	rectify_counter(int size, int counter, t_list_utils *current, bool is_rot)
{
	if (counter >= size / 2)
	{
		if (is_rot)
			current->rev_rot_a = true;
		else
			current->rev_rot_b = true;
		counter = size - counter;
	}
	return (counter);
}

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
			best->max_number = current_node->content;
		else if (current_node->content < best->min_number)
			best->min_number = current_node->content;
		current_node = current_node->next;
		i++;
	}
}
