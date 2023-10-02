/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:31:12 by wteles-d          #+#    #+#             */
/*   Updated: 2023/10/02 18:17:38 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_arr(int *arr, t_lista *lista)
{
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	while (i < lista->size - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			aux = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = aux;
			i = 0;
			continue ;
		}
		i++;
	}
	return (arr);
}

int	*create_arr(t_lista *lista)
{
	int		i;
	int		*arr;
	t_node	*temp_node;

	arr = malloc(lista->size * sizeof(int));
	if (!arr)
		return (arr);
	temp_node = lista->head;
	i = 0;
	while (i < lista->size)
	{
		arr[i] = temp_node->content;
		temp_node = temp_node->next;
		i++;
	}
	return (arr = sort_arr(arr, lista));
}

void	index_nodes(t_lista *lista)
{
	int		i;
	int		aux;
	int		*arr;
	t_node	*temp_node;

	arr = create_arr(lista);
	temp_node = lista->head;
	aux = 0;
	while (aux < lista->size)
	{
		i = 0;
		while (arr[i] != temp_node->content)
			i++;
		temp_node->id = i;
		temp_node = temp_node->next;
		aux++;
	}
	free(arr);
}

void	free_list(t_lista *lista)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (lista->size < 1)
		return ;
	current_node = lista->head;
	while (lista->size)
	{
		if (current_node->next)
			temp_node = current_node->next;
		else
			temp_node = NULL;
		free(current_node);
		lista->size--;
		current_node = temp_node;
	}
}

bool	is_sorted(t_lista *lista)
{
	int		i;
	t_node	*temp_node;

	i = 0;
	if (lista->size == 0)
		return (false);
	temp_node = lista->head;
	while (i < lista->size - 1)
	{
		if (temp_node->content > temp_node->next->content)
			return (false);
		temp_node = temp_node->next;
		i++;
	}
	return (true);
}
