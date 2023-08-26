/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:15:29 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/26 18:28:21 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// create arg reads
// create nodes with arg reads
// create moves
// start sorting alg with moves

#include "push_swap.h"

t_lista	*init_lists()
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

int	is_atoiable(int argc, char **argv)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)argc)
	{
		j = 0;
		while ((j < ft_strlen(argv[i])))
		{
			if (((argv[i][j] == '-' || argv[i][j] == '+') && j != 0) && 
				(!ft_isdigit(argv[i][j])))
				return (1); 
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	check_dups(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			printf("%i\n", ft_atoi(argv[i]));
			printf("%i\n", ft_atoi(argv[j]));
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	parse_args(int argc, char **argv, t_lista *lista)
{
	// verify dups
	int		i;
	t_node	*temp_node;
	t_node	*current_temp_node;
	
	i = 1;
	while (i < argc)
	{
		temp_node = init_node(ft_atoi(argv[i]));
		if (!temp_node)
			return ;
		if (i == 1)
		{
			lista->head = temp_node;
			current_temp_node = lista->head;
		}
		printf("NUMBER: %i\n", temp_node->content);
		temp_node->previous = current_temp_node;
		current_temp_node->next = temp_node;
		current_temp_node = temp_node;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc < 2)
		return (0);
	if (!is_atoiable(argc, argv) && !check_dups(argc, argv))
		return (0);
	main.lista_a = init_lists();
	main.lista_b = init_lists();
	parse_args(argc, argv, main.lista_a);
	
	// head_node_a->previous = current_node;
	// current_node->next = head_node_a;
	// current_node = head_node_a;
	// while (i)
	// {
	// 	if ((head_node_a->content) > (head_node_a->next->content))
	// 		do_ra_or_rb(&head_node_a, 'a');
	// 	else
	// 		do_pb(&head_node_a, &head_node_b);
	// 	if (head_node_b == NULL)
	// 	{
	// 		do_pa(&head_node_a, &head_node_b);
	// 		if(head_node_b == NULL)
	// 			break ;
	// 	}
	// }
	// current_node = head_node_a;
	// i = 1;
	// while (i < argc)
	// {
	// 	temp_node = new_node(ft_atoi(argv[i]));
	// 	if (!temp_node)
	// 		return (0);
	// 	temp_node->previous = current_node;
	// 	current_node->next = temp_node;
	// 	current_node = temp_node;
	// 	printf("NUMBER: %i\n", current_node->content);
	// 	i++;
	// }
	// //CHOOSE MOVES TO TEST HERE----------------------------
	// do_pb(&head_node_a, &head_node_b);
	// do_pb(&head_node_a, &head_node_b);
	// do_pb(&head_node_a, &head_node_b);
	// do_pb(&head_node_a, &head_node_b);
	// i = 1;
	// current_node = head_node_a;
	// printf("LISTA A:\n");
	// while (i < argc - 4)
	// {
	// 	printf("NUMBER: %i\n", current_node->content);
	// 	current_node = current_node->next;
	// 	i++;
	// }
	// i = 1;
	// current_node = head_node_b;
	// printf("LISTA B:\n");
	// while (i < 5)
	// {
	// 	printf("NUMBER: %i\n", current_node->content);
	// 	current_node = current_node->next;
	// 	i++;
	// }
	// do_rra_or_rrb(&head_node_a, 'a');
	// do_rra_or_rrb(&head_node_b, 'b');
	// i = 1;
	// current_node = head_node_a;
	// printf("LISTA A:\n");
	// while (i < argc - 4)
	// {
	// 	printf("NUMBER: %i\n", current_node->content);
	// 	current_node = current_node->next;
	// 	i++;
	// }
	// i = 1;
	// current_node = head_node_b;
	// printf("LISTA B:\n");
	// while (i < 5)
	// {
	// 	printf("NUMBER: %i\n", current_node->content);
	// 	current_node = current_node->next;
	// 	i++;
	// }
	// //CHOOSE MOVES TO TEST HERE----------------------------

	return (0);
}
