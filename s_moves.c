/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:45 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/27 16:49:31 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	do_swap(t_lista *lista)
{
	int		aux;

	if (!lista->head || !lista->head->next)
		return (false);
	aux = lista->head->content;
	lista->head->content = lista->head->next->content;
	lista->head->next->content = aux;
	return (true);
}

void	sa(t_lista *lista)
{
	if (do_swap(lista))
		write(1, "sa\n", 3);
}

void	sb(t_lista *lista)
{
	if (do_swap(lista))
		write(1, "sb\n", 3);
}

void	ss(t_lista *lista_a, t_lista *lista_b)
{
	if (do_swap(lista_a) && do_swap(lista_b))
		write(1, "ss\n", 3);
}
