/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:10:22 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/22 17:28:43 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42_Libft-master/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdbool.h>

typedef struct s_node
{
	int				id;
	int				content;
	struct s_node	*next;
	struct s_node	*previous;
}					t_node;

typedef struct s_lista
{
	int				size;
	t_node			*head;
	t_node			*tail;
}					t_lista;

typedef struct s_main
{
	t_lista			*lista_a;
	t_lista			*lista_b;
}					t_main;

t_node	*init_node(int content);
void	do_sa_or_sb(t_node *node, char c);
void	do_ra_or_rb(t_node **node, char c);
void	do_rra_or_rrb(t_node **node, char c);
void	do_ss(t_node *node_a, t_node *node_b);
void	do_pb(t_node **head_a, t_node **head_b);
void	do_pa(t_node **head_a, t_node **head_b);
void	do_rr(t_node **head_a, t_node **head_b);
void	do_rrr(t_node **head_a, t_node **head_b);

#endif