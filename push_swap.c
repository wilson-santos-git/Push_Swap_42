/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:15:29 by wteles-d          #+#    #+#             */
/*   Updated: 2023/10/02 18:13:57 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lista	*init_lists(void)
{
	t_lista	*lista;

	lista = malloc(sizeof(t_lista));
	if (!lista)
		return (NULL);
	lista->size = 0;
	lista->head = NULL;
	lista->tail = NULL;
	return (lista);
}

t_node	*init_node(int content)
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
	t_split_args	new;
	t_main			main;

	if (argc <= 2)
		return (0);
	new = ft_joinsplit(argc, argv);
	if (!check_argv(new.count, new.strings))
	{
		write(1, "Error\n", 6);
		free_arr_strings(new.strings);
		return (0);
	}
	main.lista_a = init_lists();
	main.lista_a->size = argc - 1;
	main.lista_b = init_lists();
	parse_args(new.count, new.strings, main.lista_a);
	free_arr_strings(new.strings);
	if (!is_sorted(main.lista_a))
		init_alg(&main);
	free_list(main.lista_b);
	free_list(main.lista_a);
	free(main.lista_b);
	free(main.lista_a);
	return (0);
}
