/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:48:47 by mparasku          #+#    #+#             */
/*   Updated: 2023/04/17 15:10:05 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_median(t_all *all)
{
	int	i;
	int	min;
	int	max;

	if (all->size_a == 0)
		return ;
	i = all->size_a;
	min = all->stack_a->index;
	max = all->stack_a->index;
	while (i > 0)
	{
		if (min > all->stack_a->index)
			min = all->stack_a->index;
		if (max < all->stack_a->index)
			max = all->stack_a->index;
		all->stack_a = all->stack_a->next;
		i--;
	}
	all->min = min;
	all->max = max;
	all->median = (min + max) / 2;
}

void	b_median(t_all *all)
{
	int	i;
	int	min;
	int	max;

	if (all->size_b == 0)
		return ;
	i = all->size_b;
	min = all->stack_b->index;
	max = all->stack_b->index;
	while (i > 0)
	{
		if (min > all->stack_b->index)
			min = all->stack_b->index;
		if (max < all->stack_b->index)
			max = all->stack_b->index;
		all->stack_b = all->stack_b->next;
		i--;
	}
	all->max = max;
	all->median = (min + max) / 2;
}

void	move_generation_down(t_all *all)
{
	while (all->stack_b->previous->flag == -1)
		rrb(all, 1);
	while (all->stack_b->flag == -1)
	{
		pa(all, 1);
		ra(all, 1);
	}
}

void	first_move_to_stack_b(t_all *all)
{
	int	i;

	a_median(all);
	i = all->size_a;
	while (i-- > 0)
	{
		if (all->stack_a->index <= all->median)
		{
			pb(all, 1);
			if (all->stack_b->index == all->min)
			{
				all->stack_b->flag = -1;
				rb(all, 1);
			}
		}
		else
		{
			if (all->size_b == all->max - all->median + 1)
				break ;
			else
				ra(all, 1);
		}
	}
	move_generation_down(all);
}

int	where_is_min(t_all *all)
{
	int		i;
	int		j;
	t_node	*temp;

	temp = all->stack_a;
	i = 0;
	while (++i)
	{
		if (temp->index == all->min)
			break ;
		temp = temp->next;
	}
	temp = all->stack_a;
	j = 0;
	while (++j)
	{
		if (temp->index == all->min)
			break ;
		temp = temp->previous;
	}
	if (j >= i)
		return (1);
	return (0);
}
