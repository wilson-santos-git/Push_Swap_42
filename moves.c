/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:28:45 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/21 17:09:27 by wteles-d         ###   ########.fr       */
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
		(*head_a)->previous = *head_a;
		(*head_a)->next = *head_a;
	}
	else
	{
		temp_node = new_node((*head_b)->content);
		if (!temp_node)
			return ;
		temp_node->next = *head_a;
		temp_node->previous = (*head_a)->previous;
		(*head_a)->previous = temp_node;
		if (((*head_a)->next)->content == (*head_a)->content)
			(*head_a)->next = temp_node;
		*head_a = temp_node;
	}
	temp_node = *head_a;
	*head_a = (*head_a)->next;
	(*head_a)->previous = temp_node->previous;
	free(temp_node);
	printf("pb\n");
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
		(*head_b)->previous = *head_b;
		(*head_b)->next = *head_b;
	}
	else
	{
		temp_node = new_node((*head_a)->content);
		if (!temp_node)
			return ;
		temp_node->next = *head_b;
		temp_node->previous = (*head_b)->previous;
		(*head_b)->previous = temp_node;
		if (((*head_b)->next)->content == (*head_b)->content)
			(*head_b)->next = temp_node;
		*head_b = temp_node;
	}
	temp_node = *head_a;
	*head_a = (*head_a)->next;
	(*head_a)->previous = temp_node->previous;
	free(temp_node);
	printf("pb\n");
}

void	do_ra_or_rb(t_node **node, char c)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!*node)
		return ;
	temp_node = new_node((*node)->content);
	if (!temp_node)
		return ;
	current_node = (*node)->previous;
	current_node->next = temp_node;
	temp_node->previous = current_node;
	current_node = *node;
	*node = (*node)->next;
	free(current_node);
	(*node)->previous = temp_node;
	temp_node->next = *node;
	if (c == 'a')
		printf("ra\n");
	else if (c == 'b')
		printf("rb\n");
}

void	do_rr(t_node **head_a, t_node **head_b)
{
	do_ra_or_rb(head_a, 's');
	do_ra_or_rb(head_b, 's');
	printf("rr\n");
}

void	do_rra_or_rrb(t_node **node, char c)
{
	t_node	*temp_node;
	t_node	*current_node;

	if (!*node)
		return ;
	current_node = (*node)->previous;
	temp_node = new_node(current_node->content);
	if (!temp_node)
		return ;
	printf("REVERSE TEMP NODE CONTENT: %i\n", temp_node->content);
	temp_node->next = *node;
	temp_node->previous = current_node->previous;
	(*node)->previous = temp_node;
	temp_node->previous->next = temp_node;
	free(current_node);
	(*node) = temp_node;
	if (c == 'a')
		printf("rra\n");
	else if (c == 'b')
		printf("rrb\n");
}

void	do_rrr(t_node **head_a, t_node **head_b)
{
	do_rra_or_rrb(head_a, 's');
	do_rra_or_rrb(head_b, 's');
	printf("rrr\n");
}
