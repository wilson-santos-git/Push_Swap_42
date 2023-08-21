/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:45 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/21 14:23:50 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_sa_or_sb(t_node *node, char c)
{
	int		t;
	t_node	*temp_node;

	if (!node || !node->next)
		return ;
	temp_node = node->next;
	t = node->content;
	node->content = temp_node->content;
	temp_node->content = t;
	if (c == 'a')
		printf("sa\n");
	else if (c == 'b')
		printf("sb\n");
}

void	do_ss(t_node *node_a, t_node *node_b)
{
	do_sa_or_sb(node_a, 's');
	do_sa_or_sb(node_b, 's');
	printf("ss\n");
}

void	do_pa(t_node **head_a, t_node **head_b)
{
	t_node	*temp_node;

	if (!*head_b)
		return ;
	if (*head_a == NULL)
	{
		*head_a = new_node((*head_b)->content);
		if (!*head_a)
			return ;
	}
	else
	{
		temp_node = new_node((*head_b)->content);
		if (!temp_node)
			return ;
		temp_node->previous = (*head_a)->previous;
		(*head_a)->previous = temp_node;
		temp_node->next = *head_a;
		*head_a = temp_node;
	}
	temp_node = *head_b;
	*head_b = (*head_b)->next;
	free(temp_node);
	printf("pa\n");
}

void	do_pb(t_node **head_a, t_node **head_b)
{
	t_node	*temp_node;

	if (!*head_a)
		return ;
	if (*head_b == NULL)
	{
		*head_b = new_node((*head_a)->content);
		if (!*head_b)
			return ;
	}
	else
	{
		temp_node = new_node((*head_a)->content);
		if (!temp_node)
			return ;
		temp_node->previous = (*head_b)->previous;
		(*head_b)->previous = temp_node;
		temp_node->next = *head_b;
		*head_b = temp_node;
	}
	temp_node = *head_a;
	*head_a = (*head_a)->next;
	free(temp_node);
	printf("pb\n");
}

void	do_ra(t_node **head_a)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!*head_a)
		return ;
	temp_node = new_node((*head_a)->content);
	if (!temp_node)
		return ;
	current_node = (*head_a)->previous;
	current_node->next = temp_node;
	temp_node->previous = current_node;
	current_node = *head_a;
	*head_a = (*head_a)->next;
	free(current_node);
	(*head_a)->previous = temp_node;
	temp_node->next = *head_a;
	printf("ra\n");
}

void	do_rb(t_node **head_b)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!*head_b)
		return ;
	temp_node = new_node((*head_b)->content);
	if (!temp_node)
		return ;
	current_node = (*head_b)->previous;
	current_node->next = temp_node;
	temp_node->previous = current_node;
	current_node = *head_b;
	*head_b = (*head_b)->next;
	free(current_node);
	(*head_b)->previous = temp_node;
	temp_node->next = *head_b;
	printf("rb\n");
}

void	do_rr(t_node **head_a, t_node **head_b)
{
	do_ra((*head_a));
	do_rb((*head_b));
}
