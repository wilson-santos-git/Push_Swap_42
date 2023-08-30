/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:49:11 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/30 15:18:24 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	do_rotate(t_lista *lista)
{
	t_node	*temp_node;

	if (!lista->head || !lista->head->next)
		return (false);
	temp_node = lista->head;
	lista->head = lista->head->next;
	lista->tail = temp_node;
	return (true);
}

void	do_ra(t_lista *lista)
{
	if (do_rotate(lista))
		printf("ra\n");
}

void	do_rb(t_lista *lista)
{
	if (do_rotate(lista))
		printf("rb\n");
}

void	do_rr(t_lista *lista_a, t_lista *lista_b)
{
	if (do_rotate(lista_a) && do_rotate(lista_b))
		printf("rr\n");
}
