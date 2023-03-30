/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:33:54 by mishamakura       #+#    #+#             */
/*   Updated: 2023/03/21 17:55:16 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all_numbers	*init_struct(char **arr)
{
	t_all_numbers	*all_numbers;
	int	i;

	i = 0;
	while (arr[i])
		i++;
	all_numbers = malloc(sizeof(t_all_numbers));
	if (!all_numbers)
		return (NULL);
	all_numbers->stack_a = NULL;
    all_numbers->stack_b = NULL;
    all_numbers->size_a = i;
    all_numbers->size_b = 0;
    all_numbers->min_index = 1;
    return(all_numbers);
}

t_one_number *new_node(int num, int index)
{
    t_one_number *list;
    list = malloc(sizeof(t_one_number));
    if (!list)
        return (NULL);
    list->num = num;
    list->index = index;
    list->flag = 0;
    list->next = NULL;
    list->previous = NULL;
    //printf("new node is done\n");
    return (list);
}

void add_struct_back(t_one_number **stack_a, t_one_number *new_list)
{
    t_one_number *start;

    //mb if (!new_list) ?
    start = *stack_a;
    if (start) //if there is already 1 note at least
    {
        if (start->previous) //if there is more than 1 node
        {
            start->previous->next = new_list;
            new_list->previous = start->previous;
            new_list->next = start;
            start->previous = new_list;
        }
        else //if there is 1 node
        {
            start->next = new_list;
            start->previous = new_list;
            new_list->next = start;
            new_list->previous = start;
        }
    }
    else
        *stack_a = new_list;
    //printf("stack b and a created\n");
}