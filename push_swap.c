/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:15:29 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/27 17:01:51 by wteles-d         ###   ########.fr       */
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
	int		i;
	t_main	main;
	int		new_argc;
	char	**new_argv;

	if (argc <= 2)
		return (0);
	new_argv = ft_joinsplit(argc, argv);
	i = 1;
	while (new_argv[i])
		i++;
	new_argc = i;
	if (!check_argv(new_argc, new_argv))
	{
		write(1, "Error\n", 6);
		free(new_argv);
		return (0);
	}
	main.lista_a = init_lists();
	main.lista_a->size = argc - 1;
	main.lista_b = init_lists();
	parse_args(new_argc, new_argv, main.lista_a);
	free(new_argv);
	if (!is_sorted(main.lista_a))
		init_alg(&main);
	free_list(main.lista_b);
	free_list(main.lista_a);
	free(main.lista_b);
	free(main.lista_a);
	return (0);
}
