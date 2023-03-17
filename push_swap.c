/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:53:05 by mparasku          #+#    #+#             */
/*   Updated: 2023/03/17 17:42:18 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all_numbers *arg_checker(char **ag)
{
/* 	t_all_numbers	*all_numbers; */
	char	**array;

	array = get_oneline(ag);
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