/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:51:56 by mparasku          #+#    #+#             */
/*   Updated: 2023/03/21 17:46:23 by mishamakura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "printf/libft/libft.h"
# include "printf/includes/ft_printf.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//struct for a node with 1 number
typedef struct	s_one_number
{
	int	num;
	int	index;
	int	flag; //in which generation is number
	struct	s_one_number *next;
	struct	s_one_number *previous;
}	t_one_number;

typedef struct	s_all_numbers
{
	t_one_number	*stack_a;
	t_one_number	*stack_b;
	int				size_a;
	int				size_b;
	int				min;
	int				max;
	int				median;//middle of numbers index
	int				min_index;//index of min number
}	t_all_numbers;

//parsing
t_all_numbers *arg_checker(char **ag);
char	**get_oneline(char **av);
void	error_check(char **array);
void	arr_free(char **arr, int flag);
void    free_stack(t_all_numbers *all_numbers);
int		num_errors(char	*arr);
t_all_numbers	*init_struct(char **arr);
void    create_arrays(t_all_numbers *all_numbers, char **arr);
t_one_number *new_node(int num, int index);
void bubble_sort(t_all_numbers *all_numbers, int *sorted, int *not_sorted, int size);
void    create_stack_a(t_all_numbers *all_numbers, int *sorted, int *not_sorted, int size);
void add_struct_back(t_one_number **stack_a, t_one_number *new);

//sorting
void sorting(t_all_numbers *all_numbers);
int sort_ok(t_all_numbers *all_numbers);
//push cmds
void push_a(t_all_numbers *all_numbers);
void push_b(t_all_numbers *all_numbers);
void    pa(t_all_numbers *all_numbers, int flag);
void    pb(t_all_numbers *all_numbers, int flag);
//reverse cmds
void rra(t_all_numbers *all_numbers, int flag);
void    rrb(t_all_numbers *all_numbers, int flag);
void rrr(t_all_numbers *all_numbers, int flag);
//rotate
void ra(t_all_numbers *all_numbers, int flag);
void rb(t_all_numbers *all_numbers, int flag);
void rr(t_all_numbers *all_numbers, int flag);
//swap
void sa(t_all_numbers *all_numbers, int flag);
void sb(t_all_numbers *all_numbers, int flag);
void ss(t_all_numbers *all_numbers, int flag);
//median
void a_median(t_all_numbers *all_numbers);
void b_median(t_all_numbers *all_numbers);
//sort_numbers
//small
void    three_sort_a(t_all_numbers *all_numbers);
void	three_sort_b(t_all_numbers *all_numbers);
void    five_sort(t_all_numbers *all_numbers);
int where_is_min(t_all_numbers *all_numbers);


//for checking DELETE WHEN SUBMIT
void	print_2d_array(char **array);
void print_struct(t_all_numbers *all_numbers);

#endif