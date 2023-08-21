/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:15:29 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/21 14:20:31 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// create arg reads
// create nodes with arg reads
// create moves
// start sorting alg with moves

#include "push_swap.h"

t_node	*new_node(int content)
{
	t_node	*p;

	p = malloc(sizeof(t_node));
	if (!p)
		return (NULL);
	p->next = NULL;
	p->previous = NULL;
	p->content = content;
	return (p);
}

int	main(int argc, char **argv)
{
	t_node	*temp_node;
	t_node	*head_node_a;
	t_node	*head_node_b;
	t_node	*current_node;
	int		i;

	i = 1;
	if (argc < 2)
		return (0);
	head_node_a = new_node(ft_atoi(argv[i++]));
	if (!head_node_a)
		return (0);
	current_node = head_node_a;
	head_node_b = NULL;
	printf("NUMBER: %i\n", current_node->content);
	while (i < argc)
	{
		temp_node = new_node(ft_atoi(argv[i]));
		if (!temp_node)
			return (0);
		temp_node->previous = current_node;
		current_node->next = temp_node;
		current_node = temp_node;
		printf("NUMBER: %i\n", current_node->content);
		i++;
	}
	head_node_a->previous = current_node;
	current_node->next = head_node_a;
	do_ra(&head_node_a);
	do_ra(&head_node_a);
	do_ra(&head_node_a);
	i = 1;
	current_node = head_node_a;
	printf("LISTA A:\n");
	while (i < argc)
	{
		printf("NUMBER: %i\n", current_node->content);
		current_node = current_node->next;
		i++;
	}
	return (0);
}
