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
    arr_free(array, 0);
    //printf("array freed\n");
    //print_struct(all_numbers); //DELETE
	return(all_numbers);
}

void sorting(t_all_numbers *all_numbers)
{
    if(sort_ok(all_numbers))
        free_stack(all_numbers);
    if (all_numbers->size_a < 6)
    {
        five_sort(all_numbers);
        free_stack(all_numbers);
    }

}

int main(int ac, char **ag)
{
	t_all_numbers	*all_numbers;
	if(ac > 1)
	{
		all_numbers = arg_checker(ag);
        sorting(all_numbers);
	}
	return(0);
}