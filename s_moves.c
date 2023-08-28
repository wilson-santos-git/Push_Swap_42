/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:45 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/28 15:49:40 by wteles-d         ###   ########.fr       */
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

void	do_sa(t_lista *lista)
{
	if (do_swap(lista))
		printf("sa\n");
}

void	do_sb(t_lista *lista)
{
	if (do_swap(lista))
		printf("sb\n");
}

void	do_ss(t_lista *lista_a, t_lista *lista_b)
{
	if (do_swap(lista_a) && do_swap(lista_b))
		printf("ss\n");
}
