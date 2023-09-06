/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:10:22 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/06 18:40:49 by wteles-d         ###   ########.fr       */
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

t_lista	*init_lists(void);
void	do_pa(t_main *main);
void	do_pb(t_main *main);
void	do_sa(t_lista *lista);
void	do_sb(t_lista *lista);
void	do_ra(t_lista *lista);
void	do_rb(t_lista *lista);
void	do_rra(t_lista *lista);
void	do_rrb(t_lista *lista);
void	sort_alg(t_main *main);
t_node	*init_node(int content);
bool	do_swap(t_lista *lista);
bool	is_sorted(t_lista *lista);
void	free_list(t_lista *lista);
void	print_lists(t_main *main);
bool	do_rotate(t_lista *lista);
t_node	*find_best_num(t_main *main);
void	print_head_tail(t_main *main);
void	sorting_algorithm(t_main *main);
void	fix_missing_head_a(t_main *main);
void	fix_missing_head_b(t_main *main);
int		check_argv(int argc, char **argv);
int		check_dups(int argc, char **argv);
bool	do_reverse_rotate(t_lista *lista);
int		count_moves(t_lista *lista, int nbr);
void	do_ss(t_lista *lista_a, t_lista *lista_b);
void	do_rrr(t_lista *lista_a, t_lista *lista_b);
void	parse_args(int argc, char **argv, t_lista *lista);

#endif