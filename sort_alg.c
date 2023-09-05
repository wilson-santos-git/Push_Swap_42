/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wteles-d <wteles-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:45:12 by wteles-d          #+#    #+#             */
/*   Updated: 2023/09/05 16:25:17 by wteles-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_algorithm(t_main *main)
{
	sort_alg(main);
	while (main->lista_b->size > 0)
		do_pa(main);
}

void	sort_alg(t_main *main)
{
	int	current_b_max;
	int	current_b_min;
	int	counter;

	counter = 0;
	do_pb(main);
	do_pb(main);
	if (main->lista_b->head->content < main->lista_b->head->next->content)
		do_rb(main->lista_b);
	current_b_max = main->lista_b->head->content;
	current_b_min = main->lista_b->head->next->content;
	while (main->lista_a->size > 0)
	{
		if (main->lista_a->head->content > current_b_max)
		{
			do_pb(main);
			current_b_max = main->lista_b->head->content;
		}
		else if (main->lista_a->head->content < current_b_min)
		{
			do_pb(main);
			current_b_min = main->lista_b->head->content;
			do_rb(main->lista_b);
		}
		else
		{
			counter = 0;
			if ((main->lista_a->head->content - current_b_min)
				< (current_b_max - main->lista_a->head->content))
			{
				while (1)
				{
					if ((main->lista_a->head->content
							< main->lista_b->tail->content)
						&& (main->lista_a->head->content
							> main->lista_b->head->content))
					{
						do_pb(main);
						counter++;
						break ;
					}
					else
					{
						do_rrb(main->lista_b);
						counter++;
					}
				}
				while (counter > 0)
				{
					do_rb(main->lista_b);
					counter--;
				}
			}
			else
			{
				while (1)
				{
					if ((main->lista_a->head->content
							< main->lista_b->tail->content)
						&& (main->lista_a->head->content
							> main->lista_b->head->content))
					{
						do_pb(main);
						break ;
					}
					else
					{
						do_rb(main->lista_b);
						counter++;
					}
				}
				while (counter > 0)
				{
					do_rrb(main->lista_b);
					counter--;
				}
			}
			if (main->lista_b->head->content > current_b_max)
				current_b_max = main->lista_b->head->content;
			else if (main->lista_b->tail->content < current_b_min)
				current_b_min = main->lista_b->tail->content;
		}
	}
}

// void	sort_alg(t_main *main)
// {
// 	int	current_b_max;
// 	int	current_b_min;

// 	do_pb(main);
// 	do_pb(main);
// 	if (main->lista_b->head->content < main->lista_b->head->next->content)
// 		do_rb(main->lista_b);
// 	current_b_max = main->lista_b->head->content;
// 	current_b_min = main->lista_b->head->next->content;
// 	while (main->lista_a->size > 0)
// 	{
// 		if (main->lista_a->head->content > current_b_max)
// 		{
// 			do_pb(main);
// 			current_b_max = main->lista_b->head->content;
// 		}
// 		else if (main->lista_a->head->content < current_b_min)
// 		{
// 			do_pb(main);
// 			current_b_min = main->lista_b->head->content;
// 			do_rb(main->lista_b);
// 		}
// 		else
// 		{
// 			if ((main->lista_a->head->content - current_b_min)
// 				< (current_b_max - main->lista_a->head->content))
// 			{
// 				while (1)
// 				{
// 					do_rrb(main->lista_b);
// 					if (main->lista_a->head->content
// 						> main->lista_b->head->content
// 						&& main->lista_a->head->content
// 						< main->lista_b->tail->content)
// 						break ;
// 				}
// 				do_pb(main);
// 				while (main->lista_b->head->content != current_b_min)
// 				{
// 					if (main->lista_a->head->content
// 						> main->lista_b->head->content
// 						&& main->lista_a->head->content
// 						< main->lista_b->tail->content)
// 					{
// 						do_pb(main);
// 						break ;
// 					}
// 					do_rb(main->lista_b);
// 				}
// 				do_rb(main->lista_b);
// 			}
// 			else
// 			{
// 				while (1)
// 				{
// 					do_rb(main->lista_b);
// 					if (main->lista_a->head->content
// 						> main->lista_b->head->content
// 						&& main->lista_a->head->content
// 						< main->lista_b->tail->content)
// 						break ;
// 				}
// 				do_pb(main);
// 				while (main->lista_b->head->content != current_b_max)
// 				{
// 					if (main->lista_a->head->content
// 						> main->lista_b->head->content
// 						&& main->lista_a->head->content
// 						< main->lista_b->tail->content)
// 					{
// 						do_pb(main);
// 						break ;
// 					}
// 					do_rrb(main->lista_b);
// 				}
// 				do_rrb(main->lista_b);
// 			}
// 		}
// 	}
// }

// void	sort_alg(t_main *main)
// {
// 	int	current_b_max;
// 	int	current_b_min;

// 	do_pb(main);
// 	do_pb(main);
// 	if (main->lista_b->head->content < main->lista_b->head->next->content)
// 		do_rb(main->lista_b);
// 	current_b_max = main->lista_b->head->content;
// 	current_b_min = main->lista_b->head->next->content;
// 	while (main->lista_a->size > 0)
// 	{
// 		if (main->lista_a->head->content > current_b_max)
// 		{
// 			do_pb(main);
// 			current_b_max = main->lista_b->head->content;
// 		}
// 		else if (main->lista_a->head->content < current_b_min)
// 		{
// 			do_pb(main);
// 			current_b_min = main->lista_b->head->content;
// 			do_rb(main->lista_b);
// 		}
// 		else
// 		{
// 			if ((main->lista_a->head->content > main->lista_b->head->content)
// 				&& (main->lista_a->head->content
// 					< main->lista_b->tail->content))
// 			{
// 				do_pb(main);
// 				continue ;
// 			}
// 			else
// 				do_rb(main->lista_b);
// 		}
// 	}
// }

// void	sort_alg(t_main *main)
// {
// 	if ((main->lista_a->size > 0)
// 		&& (main->lista_a->head->content > main->lista_a->head->next->content))
// 	{
// 		do_pb(main);
// 		if (main->lista_b->size > 1
// 			&& (main->lista_b->head->content
// 				> main->lista_b->head->next->content))
// 			do_rb(main->lista_b);
// 	}
// 	else
// 	{
// 		if ((main->lista_b->size > 0)
// 			&& (main->lista_a->head->content > main->lista_b->head->content))
// 			do_pa(main);
// 		if (main->lista_a->size == 1)
// 			do_pb(main);
// 		else
// 			do_ra(main->lista_a);
// 	}
// 	print_lists(main);
// }
