/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:33:54 by mishamakura       #+#    #+#             */
/*   Updated: 2023/04/14 19:57:09 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*init_struct(char **arr)
{
	t_all	*all;
	int		i;

	i = 0;
	while (arr[i])
		i++;
	all = malloc(sizeof(t_all));
	if (!all)
		return (NULL);
	all->stack_a = NULL;
	all->stack_b = NULL;
	all->size_a = i;
	all->size_b = 0;
	all->min_index_a = 1;
	return (all);
}

t_node	*new_node(int num, int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (!list)
		return (NULL);
	list->num = num;
	list->index = index;
	list->flag = 0;
	list->next = NULL;
	list->previous = NULL;
	return (list);
}

void	add_struct_back(t_node **stack_a, t_node *new_list)
{
	t_node	*start;

	start = *stack_a;
	if (start)
	{
		if (start->previous)
		{
			start->previous->next = new_list;
			new_list->previous = start->previous;
			new_list->next = start;
			start->previous = new_list;
		}
		else
		{
			start->next = new_list;
			start->previous = new_list;
			new_list->next = start;
			new_list->previous = start;
		}
	}
	else
		*stack_a = new_list;
}
