/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:05:56 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/26 18:14:19 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dups(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) >= 2147483647 || ft_atol(argv[i]) <= -2147483648)
			return (0);
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_argv(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while ((j < ft_strlen(argv[i])))
		{
			if (((argv[i][j] == '-' || argv[i][j] == '+') && j != 0) &&
				(!ft_isdigit(argv[i][j])))
				return (0);
			else
				j++;
		}
		i++;
	}
	if (check_dups(argc, argv))
		return (0);	
	return (1);
}

void	parse_args(int argc, char **argv, t_lista *lista)
{
	int		i;
	t_node	*temp_node;
	t_node	*current_temp_node;

	i = 1;
	while (i < argc)
	{
		temp_node = init_node(ft_atoi(argv[i]));
		if (!temp_node)
			return ;
		if (i == 1)
		{
			lista->head = temp_node;
			current_temp_node = lista->head;
		}
		temp_node->previous = current_temp_node;
		current_temp_node->next = temp_node;
		current_temp_node = temp_node;
		i++;
	}
	lista->tail = temp_node;
	lista->head->previous = lista->tail;
	lista->tail->next = lista->head;
	index_nodes(lista);
}
