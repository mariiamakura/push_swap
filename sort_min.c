/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:52:09 by mparasku          #+#    #+#             */
/*   Updated: 2023/04/14 19:53:26 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_ok(t_all *all)
{
	int		i;
	t_node	*start;

	start = all->stack_a;
	i = all->size_a - 1;
	while (i > 0)
	{
		if (start->index > start->next->index)
			return (0);
		start = start->next;
		i--;
	}
	return (1);
}

void	three_sort_a(t_all *all)
{
	int	a;
	int	b;
	int	c;

	a = all->stack_a->index;
	b = all->stack_a->next->index;
	c = all->stack_a->previous->index;
	if (a > b && a > c)
		ra(all, 1);
	else if (b > a && b > c)
		rra(all, 1);
	a = all->stack_a->index;
	b = all->stack_a->next->index;
	if (a > b)
		sa(all, 1);
}

void	five_sort(t_all *all)
{
	while (all->size_a > 3)
	{
		a_median(all);
		if (all->stack_a->index == all->min)
		{
			pb(all, 1);
			continue ;
		}
		if (where_is_min(all))
			ra(all, 1);
		else
			rra(all, 1);
	}
	three_sort_a(all);
	pa(all, 1);
	pa(all, 1);
}
