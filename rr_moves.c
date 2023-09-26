/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:50:25 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/26 16:47:06 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	do_reverse_rotate(t_lista *lista)
{
	t_node	*temp_node;

	if (!lista->head || !lista->head->next)
		return (false);
	temp_node = lista->tail;
	lista->tail = lista->tail->previous;
	lista->head = temp_node;
	return (true);
}

void	rra(t_lista *lista)
{
	if (do_reverse_rotate(lista))
		printf("rra\n");
}

void	rrb(t_lista *lista)
{
	if (do_reverse_rotate(lista))
		printf("rrb\n");
}

void	rrr(t_lista *lista_a, t_lista *lista_b)
{
	if (do_reverse_rotate(lista_a) && do_reverse_rotate(lista_b))
		printf("rrr\n");
}
