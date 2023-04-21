/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:41:14 by mparasku          #+#    #+#             */
/*   Updated: 2023/04/14 19:42:26 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_down(t_all *all)
{
	all->stack_a->flag = -1;
	ra(all, 1);
}

void	move_a_to_b(t_all *all)
{
	int	flag;
	int	min;

	flag = all->stack_a->flag;
	while (all->stack_a->flag == flag && flag != -1)
	{
		min = all->stack_a->previous->index + 1;
		if (all->size_b > 1)
			search_min_2(all);
		if (all->stack_a->index == min)
			push_down(all);
		else
			pb(all, 1);
	}
}

void	search_min_2(t_all *all)
{
	int	min;

	min = all->stack_a->previous->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_b->next->index == min)
	{
		sb(all, 1);
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_b->previous->index == min)
	{
		rrb(all, 1);
		pa(all, 1);
		push_down(all);
	}
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		push_down(all);
	}
}

int	search_min(t_all *all)
{
	int	min;

	min = all->stack_a->previous->index + 1;
	if (all->stack_b->index == min)
	{
		pa(all, 1);
		push_down(all);
		return (1);
	}
	else if (all->stack_a->index == min)
		push_down(all);
	else if (all->stack_a->next->index == min)
	{
		sa(all, 1);
		push_down(all);
	}
	return (0);
}

void	sort_big(t_all *all)
{
	int	i;

	i = all->size_b;
	b_median(all);
	while (i-- > 0)
	{
		if (search_min(all))
			continue ;
		if (all->stack_b->index > all->median)
		{
			all->stack_b->flag++;
			pa(all, 1);
		}
		else
		{
			all->stack_b->flag++;
			rb(all, 1);
		}
	}
}
