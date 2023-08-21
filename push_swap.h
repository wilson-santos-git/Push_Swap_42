/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:10:22 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/21 17:09:43 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42_Libft-master/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_node
{
	struct s_node	*next;
	int				content;
	struct s_node	*previous;
}					t_node;

t_node	*new_node(int content);
void	do_sa_or_sb(t_node *node, char c);
void	do_rra_or_rrb(t_node **node, char c);
void	do_ss(t_node *node_a, t_node *node_b);
void	do_pb(t_node **head_a, t_node **head_b);
void	do_pa(t_node **head_a, t_node **head_b);
void	do_rr(t_node **head_a, t_node **head_b);
void	do_rrr(t_node **head_a, t_node **head_b);

#endif