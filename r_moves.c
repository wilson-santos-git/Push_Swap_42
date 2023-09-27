/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:49:11 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/27 16:50:09 by wteles-d         ###   ########.fr       */
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

void	ra(t_lista *lista)
{
	if (do_rotate(lista))
		write(1, "ra\n", 3);
}

void	rb(t_lista *lista)
{
	if (do_rotate(lista))
		write(1, "rb\n", 3);
}

void	rr(t_lista *lista_a, t_lista *lista_b)
{
	if (do_rotate(lista_a) && do_rotate(lista_b))
		write(1, "rr\n", 3);
}
