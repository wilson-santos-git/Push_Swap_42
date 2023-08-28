/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:05:56 by wteles-d          #+#    #+#             */
/*   Updated: 2023/08/28 17:05:14 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				printf("FOUND DUP X(\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_argv(int argc, char **argv)
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
			{
				printf("FOUND NON DIGIT X(\n");
				return (0); 
			}
			else
				j++;
		}
		i++;
	}
	if (check_dups(argc, argv))
		return (0);
	printf("ALL GOOD :D\n");
	return (1);
}

void	parse_args(int argc, char **argv, t_lista *lista)
{
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
	lista->tail = temp_node;
	lista->head->previous = lista->tail;
	lista->tail->next = lista->head;
}

void	free_list(t_lista *lista)
{
	t_node	*temp_node;
	t_node	*delete_node;

	if (!lista->head)
		return ;
	temp_node = lista->head->previous;
	lista->head->previous = NULL;
	while (1)
	{
		if (temp_node->previous == NULL)
			break ;
		delete_node = temp_node;
		temp_node = temp_node->previous;
		printf("DELETED NODE: %i\n", delete_node->content);
		free(delete_node);
	}
	printf("DELETED NODE: %i\n", temp_node->content);
	free(temp_node);
}

void	print_lists(t_main *main)
{
	t_node	*temp_node;

	if (main->lista_a->head)
	{
		temp_node = main->lista_a->head;
		printf("LISTA A: ");
		while (1)
		{
			printf("%i, ", temp_node->content);
			if (temp_node->next->content == main->lista_a->tail->content)
				break ;
			temp_node = temp_node->next;
		}
		printf("%i\n", main->lista_a->tail->content);
	}
	if (main->lista_b->head)
	{
		temp_node = main->lista_b->head;
		printf("LISTA B: ");
		while (1)
		{
			printf("%i, ", temp_node->content);
			if (temp_node->next->content == main->lista_b->tail->content)
				break ;
			temp_node = temp_node->next;
		}
		printf("%i\n", main->lista_b->tail->content);
	}
}
