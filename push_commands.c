/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:58:05 by mparasku          #+#    #+#             */
/*   Updated: 2023/04/14 19:37:20 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_all *all)
{
	t_node	*temp;

	temp = all->stack_b->next;
	all->stack_b->previous->next = all->stack_b->next;
	all->stack_b->next->previous = all->stack_b->previous;
	if (all->stack_a)
	{
		all->stack_b->previous = all->stack_a->previous;
		all->stack_b->next = all->stack_a;
		all->stack_a->previous->next = all->stack_b;
		all->stack_a->previous = all->stack_b;
		all->stack_a = all->stack_b;
	}
	else
	{
		all->stack_a = all->stack_b;
		all->stack_a->next = all->stack_a;
		all->stack_a->previous = all->stack_a;
	}
	all->stack_b = temp;
}

void	push_b(t_all *all)
{
	t_node	*temp;

	temp = all->stack_a->next;
	all->stack_a->previous->next = all->stack_a->next;
	all->stack_a->next->previous = all->stack_a->previous;
	if (all->stack_b)
	{
		all->stack_a->previous = all->stack_b->previous;
		all->stack_a->next = all->stack_b;
		all->stack_b->previous->next = all->stack_a;
		all->stack_b->previous = all->stack_a;
		all->stack_b = all->stack_a;
	}
	else
	{
		all->stack_b = all->stack_a;
		all->stack_a->next = all->stack_b;
		all->stack_a->previous = all->stack_b;
	}
	all->stack_a = temp;
}

void	pa(t_all *all, int flag)
{
	if (all->size_b == 0)
		return ;
	push_a(all);
	if (all->size_b == 1)
		all->stack_b = NULL;
	all->size_b--;
	all->size_a++;
	if (flag)
		write(1, "pa\n", 3);
}

void	pb(t_all *all, int flag)
{
	if (all->size_a == 0)
		return ;
	push_b(all);
	if (all->size_a == 1)
		all->stack_a = NULL;
	all->size_a--;
	all->size_b++;
	if (flag)
		write(1, "pb\n", 3);
}
