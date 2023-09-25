/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:45:39 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/26 00:15:33 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_moves_max_min(t_lista	*lista, t_list_utils *best, int	current_number_b)
{
	int		counter;
	t_node *temp_node;
	
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

int	count_moves(t_lista	*lista, int	current_number_b, t_list_utils *best, t_list_utils *current)
{
	(void) current;
	int		counter;
	t_node *temp_node;
	
	counter = 0;
	temp_node = lista->head;
	if (current_number_b > best->max_number || current_number_b < best->min_number)
		counter = count_moves_max_min(lista, best, current_number_b);
	else
	{
		while (counter < lista->size)
		{
			if (current_number_b > temp_node->previous->content
				&& current_number_b < temp_node->content)
				break ;
			temp_node = temp_node->next;
			counter++;
		}
	}
	return (get_correct_counter(lista->size, counter, current, true));
}

int	get_correct_counter(int size, int counter, t_list_utils *current, bool is_rot)
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