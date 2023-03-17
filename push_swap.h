/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:51:56 by mparasku          #+#    #+#             */
/*   Updated: 2023/03/17 17:41:55 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/libft/libft.h"
# include "printf/includes/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

//struct for a node with 1 number
typedef struct	s_one_number
{
	int	num;
	int	index;
	int	flag;
	struct	s_one_number *next;
	struct	s_one_number *previous;
}	t_one_number;

typedef struct	s_all_numbers
{
	t_one_number	*stack_a;
	t_one_number	*stack_b;
	int				length_a;
	int				length_b;
	int				min;
	int				max;
	int				middle;
	int				min_a;
}	t_all_numbers;

char	**get_oneline(char **av);

//for checking
void	print_2d_array(char **array);

#endif