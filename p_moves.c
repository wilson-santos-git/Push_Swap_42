/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:29 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/28 17:57:45 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_missing_head_a(t_main *main)
{
	t_node	*temp_node;

	temp_node = main->lista_b->head;
	main->lista_b->head = main->lista_b->head->next;
	main->lista_b->head->previous = temp_node->previous;
	main->lista_a->head = temp_node;
	main->lista_a->head->next = main->lista_a->head;
	main->lista_a->head->previous = main->lista_a->head;
	main->lista_a->tail = main->lista_a->head;
	main->lista_a->tail->next = main->lista_a->head;
	main->lista_a->tail->previous = main->lista_a->head;
}

void	do_pa(t_main *main)
{
	t_node	*temp_node;

	if (!main->lista_b->head)
		return ;
	temp_node = main->lista_b->head;
	if (!main->lista_a->head)
		fix_missing_head_a(main);
	else
	{
		if (main->lista_b->size == 1)
			main->lista_b = NULL;
		else
		{
			main->lista_b->head = main->lista_b->head->next;
			main->lista_b->head->previous = temp_node->previous;
		}
		temp_node->previous = main->lista_a->head->previous;
		temp_node->next = main->lista_a->head;
		main->lista_a->head->previous = temp_node;
		main->lista_a->head = temp_node;
		if (main->lista_a->head->next->next->content
			== main->lista_a->head->next->content)
		{
			main->lista_a->head->next->next = main->lista_a->head;
			main->lista_a->tail->previous = main->lista_a->head->next;
		}
	}
	main->lista_a->size++;
	main->lista_b->size--;
	if (main->lista_b->size == 0)
		main->lista_b = NULL;
	printf("pa\n");
}

void	fix_missing_head_b(t_main *main)
{
	t_node	*temp_node;

	temp_node = main->lista_a->head;
	main->lista_a->head = main->lista_a->head->next;
	main->lista_a->head->previous = temp_node->previous;
	main->lista_b->head = temp_node;
	main->lista_b->head->next = main->lista_b->head;
	main->lista_b->head->previous = main->lista_b->head;
	main->lista_b->tail = main->lista_b->head;
	main->lista_b->tail->next = main->lista_b->head;
	main->lista_b->tail->previous = main->lista_b->head;
}

void	do_pb(t_main *main)
{
	t_node	*temp_node;

	if (!main->lista_a->head)
		return ;
	temp_node = main->lista_a->head;
	if (!main->lista_b->head)
		fix_missing_head_b(main);
	else if (main->lista_a->size == 1)
	{
		main->lista_a = NULL; 
	}
	else
	{
		if (main->lista_a->size == 1)
			main->lista_a = NULL;
		else
		{
			main->lista_a->head = main->lista_a->head->next;
			main->lista_a->head->previous = temp_node->previous;
		}
		temp_node->previous = main->lista_b->head->previous;
		temp_node->next = main->lista_b->head;
		main->lista_b->head->previous = temp_node;
		main->lista_b->head = temp_node;
		if (main->lista_b->head->next->next->content
			== main->lista_b->head->next->content)
		{
			main->lista_b->head->next->next = main->lista_b->head;
			main->lista_b->tail->previous = main->lista_b->head->next;
		}
	}
	main->lista_b->size++;
	main->lista_a->size--;
	if (main->lista_a->size == 0)
		main->lista_a = NULL;
	printf("pb\n");
}
