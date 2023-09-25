/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:10:22 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/25 23:59:54 by wteles-d         ###   ########.fr       */
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
	struct s_node	*next;
	int				content;
	struct s_node	*previous;
}					t_node;

typedef struct s_lista
{
	int				size;
	t_node			*tail;
	t_node			*head;
}					t_lista;

typedef struct s_main
{
	t_lista			*lista_a;
	t_lista			*lista_b;
}					t_main;

typedef struct s_list_utils
{
	bool	rev_rot_a;
	bool	rev_rot_b;
	int		max_number;
	int		min_number;
	int		cheapest_rots_a;
	int		cheapest_rots_b;
	int		cheapest_content;
}					t_list_utils;

void			pa(t_main *main);
void			pb(t_main *main);
t_lista			*init_lists(void);
void			ra(t_lista *lista);
void			rb(t_lista *lista);
void			sa(t_lista *lista);
void			sb(t_lista *lista);
void			rra(t_lista *lista);
void			rrb(t_lista *lista);
void			init_alg(t_main *main);
t_node			*init_node(int content);
bool			is_sorted(t_lista *lista);
void			free_list(t_lista *lista);
void			push_util(t_lista	**lista);
void			push_util_2(t_lista	**lista);
t_list_utils	init_list_utils(t_main *main);
t_list_utils	find_cheapest_node(t_main *main);
int				check_dups(int argc, char **argv);
int				check_argv(int argc, char **argv);
void			ss(t_lista *lista_a, t_lista *lista_b);
void			rr(t_lista *lista_a, t_lista *lista_b);
void			rrr(t_lista *lista_a, t_lista *lista_b);
void			find_max_min(t_lista *lista, t_list_utils *best);
void			parse_args(int argc, char **argv, t_lista *lista);
int				count_moves_max_min(t_lista	*lista, t_list_utils *best, int	current_number_a);
int				get_correct_counter(int size, int counter, t_list_utils *current, bool is_rot);
int				count_moves(t_lista	*lista, int	current_number_a, t_list_utils *best, t_list_utils *current);

#endif