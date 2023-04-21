/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:53:05 by mparasku          #+#    #+#             */
/*   Updated: 2023/04/14 19:57:01 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*arg_checker(char **ag)
{
	t_all	*all;
	char	**array;

	array = get_oneline(ag);
	error_check(array);
	all = init_struct(array);
	create_arrays(all, array);
	arr_free(array, 0);
	return (all);
}

void	sorting(t_all *all)
{
	if (sort_ok(all))
		return ;
	if (all->size_a < 6)
	{
		five_sort(all);
		free_stack(all);
	}
	first_move_to_stack_b(all);
	while (!(sort_ok(all) && all->size_b == 0))
	{
		if (all->size_b < 6)
			five_sort_b(all);
		else if (all->size_b >= 6)
			sort_big(all);
		if (all->size_b == 0)
		{
			five_sort_a(all, 0, 0, 0);
			move_a_to_b(all);
		}
	}
}

int	main(int ac, char **ag)
{
	t_all	*all;

	if (ac > 1)
	{
		all = arg_checker(ag);
		sorting(all);
		free_stack(all);
	}
	return (0);
}
