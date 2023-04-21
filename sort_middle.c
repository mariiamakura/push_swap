/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:42:36 by mparasku          #+#    #+#             */
/*   Updated: 2023/04/14 19:51:24 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	generation_order(t_all *all, int flag)
{
	if (all->stack_a->index > all->stack_a->next->index && \
	all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
		all->stack_a->flag == -1)
		{
			pa(all, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->stack_a->flag == flag && flag != -1 && \
	all->stack_a->index + 1 == all->stack_a->previous->index)
		push_down(all);
}

void	generation_order_2(t_all *all, int flag)
{
	if (all->stack_a->index > all->stack_a->next->index && \
		all->stack_a->flag == all->stack_a->next->flag)
		sa(all, 1);
	while (all->size_b != 0)
	{
		if (all->stack_a->index > all->stack_b->index || \
			all->stack_a->flag != flag)
		{
			pa(all, 1);
			push_down(all);
		}
		else
			push_down(all);
	}
	while (all->stack_a->flag == flag && flag != -1)
		push_down(all);
}

void	sort_three_b_to_a(t_all *all)
{
	int	a;
	int	b;
	int	c;

	if (all->size_b == 0)
		return ;
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	c = all->stack_b->previous->index;
	if (b > a && b > c)
		rrb(all, 1);
	else if (a > b && a > c)
		rb(all, 1);
	a = all->stack_b->index;
	b = all->stack_b->next->index;
	if (a > b)
		sb(all, 1);
}

void	five_sort_b(t_all *all)
{
	int	i;
	int	min;
	int	flag;

	i = all->size_b;
	min = all->stack_a->previous->index + 1;
	flag = all->stack_a->flag;
	while (i > 3)
	{
		if (all->stack_b->index == min)
		{
			pa(all, 1);
			push_down(all);
			min++;
		}
		else
			pa (all, 1);
		i--;
	}
	sort_three_b_to_a(all);
	generation_order(all, flag);
}

void	five_sort_a(t_all *all, int i, int flag, int min)
{
	t_node	*temp;

	min = all->stack_a->previous->index + 1;
	flag = all->stack_a->flag;
	temp = all->stack_a;
	while (temp->flag == flag && flag != -1)
	{
		temp = temp->next;
		i++;
	}
	if (i <= 5)
	{
		while (i-- > 2)
		{
			if (all->stack_a->index == min)
			{
				push_down(all);
				min++;
			}
			else
				pb(all, 1);
		}
		sort_three_b_to_a(all);
		generation_order_2(all, flag);
	}
}
