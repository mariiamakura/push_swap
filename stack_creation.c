/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:54:52 by mparasku          #+#    #+#             */
/*   Updated: 2023/04/14 19:55:23 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_arrays(t_all *all, char **arr)
{
	int	*sorted;
	int	*not_sorted;
	int	num;
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (arr[size])
		size++;
	sorted = malloc(sizeof(int) * size);
	not_sorted = malloc(sizeof(int) * size);
	while (i < size)
	{
		num = ft_atoi(arr[i]);
		not_sorted[i] = num;
		sorted[i] = num;
		i++;
	}
	bubble_sort(all, sorted, not_sorted, size);
}

void	bubble_sort(t_all *all, int *sorted, int *not_sorted, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < (size - 1 - i))
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j + 1];
				sorted[j + 1] = sorted[j];
				sorted[j] = temp;
			}
			j++;
		}
		i++;
	}
	create_stack_a(all, sorted, not_sorted, size);
}

void	create_stack_a(t_all *all, int *sorted, int *not_sorted, int size)
{
	int		i;
	int		j;
	t_node	*new_list;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (not_sorted[i] == sorted[j])
			{
				new_list = new_node(not_sorted[i], j + 1);
				add_struct_back(&all->stack_a, new_list);
			}
			j++;
		}
		i++;
	}
	free(sorted);
	free(not_sorted);
}

void	free_stack(t_all *all)
{
	t_node	*temp;

	while (all->size_a--)
	{
		temp = all->stack_a->next;
		free(all->stack_a);
		all->stack_a = NULL;
		all->stack_a = temp;
	}
	while (all->size_b--)
	{
		temp = all->stack_b->next;
		free(all->stack_b);
		all->stack_b = NULL;
		all->stack_b = temp;
	}
	free(all);
	exit(0);
}
