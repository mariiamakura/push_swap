/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:36:09 by mishamakura       #+#    #+#             */
/*   Updated: 2023/04/14 15:42:56 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_print(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	arr_free(char **arr, int flag)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	if (flag)
		error_print();
}

char	**get_oneline(char **av)
{
	int		i;
	char	*line;
	char	*temp;
	char	**arr;

	line = ft_strdup(av[1]);
	i = 2;
	while (av[i])
	{
		temp = line;
		line = ft_strjoin(line, " ");
		free(temp);
		temp = line;
		line = ft_strjoin(line, av[i]);
		free(temp);
		i++;
	}
	arr = ft_split(line, ' ');
	free(line);
	return (arr);
}

int	num_errors(char	*arr)
{
	int			i;
	long long	num;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == '-')
			i++;
		if (!(ft_isdigit(arr[i])))
			return (1);
		num = ft_atoi(arr);
		if (num < INT_MIN || num > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

void	error_check(char **arr)
{
	int			i;
	int			j;

	i = 0;
	while (arr[i])
	{
		if (i == 0)
			if (num_errors(arr[i]) == 1)
				arr_free(arr, 1);
		j = i + 1;
		while (arr[j])
		{
			if (num_errors(arr[j]) == 1)
				arr_free(arr, 1);
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				arr_free(arr, 1);
			j++;
		}
		i++;
	}
}
