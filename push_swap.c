/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:53:05 by mparasku          #+#    #+#             */
/*   Updated: 2023/03/21 17:43:35 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all_numbers *arg_checker(char **ag)
{
	t_all_numbers	*all_numbers;
	char	**array;

	array = get_oneline(ag);
	error_check(array);
	all_numbers = init_struct(array);
    create_arrays(all_numbers, array);
    print_struct(all_numbers);
	return(0);
}

int main(int ac, char **ag)
{
	t_all_numbers	*all_numbers;
	
	if(ac > 1)
	{
		all_numbers = arg_checker(ag);
	}
	return(0);
}