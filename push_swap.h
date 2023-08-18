/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:10:22 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/18 18:25:49 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "42_Libft-master/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>

typedef struct s_lista
{
	struct s_lista	*next;
	int				content;
	struct s_lista	*previous;
}					t_lista;

t_lista	*new_node(int content);
void	do_sa_or_sb(t_lista *node, char c);
void	do_ss(t_lista *node_a, t_lista *node_b);
void	do_pb(t_lista **head_a, t_lista **head_b);
void	do_pa(t_lista **head_a, t_lista **head_b);

#endif