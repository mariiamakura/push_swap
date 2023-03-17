/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:36:09 by mishamakura       #+#    #+#             */
/*   Updated: 2023/03/17 17:41:10 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**get_oneline(char **av)
{
	int		i;
	char	*line;
	char	*temp;
	char	**arr;

	line = ft_strdup(av[1]); //copying the 1 element after program name
	i = 2; //since we want the 2 element of av in the loop
	while (av[i])
	{
		temp = line;
		line = ft_strjoin(line, " "); //adding space to the end of argument
		free(temp);
		temp = line;
		line = ft_strjoin(line, av[i]); //adding next argument to the string
		free(temp);
		i++;
	}
	arr = ft_split(line, ' ');
	free(line);
	print_2d_array(arr);
	return(arr);	
}

void	print_2d_array(char **array)
{
	int	i;
	
	i = 0; // initialize the counter
    while (array[i] != NULL) // iterate over each string in the array
       {
            printf("%s ", array[i]); // print the string followed by a space
            i++; // increment the counter
        }
    printf("\n");
}
