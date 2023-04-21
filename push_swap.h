/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mishamakura <mishamakura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:51:56 by mparasku          #+#    #+#             */
/*   Updated: 2023/04/17 14:23:28 by mishamakura      ###   ########.fr       */
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
typedef struct s_node
{
	int				num;
	int				index;
	int				flag;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_all
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
	int		min;
	int		max;
	int		median;
	int		min_index_a;
}	t_all;

//push_swap
t_all	*arg_checker(char **ag);
void	sorting(t_all *all);

//arg_checking
char	**get_oneline(char **av);
void	error_check(char **array);
void	arr_free(char **arr, int flag);
int		num_errors(char	*arr);
void	error_print(void);

//init_struct
t_all	*init_struct(char **arr);
t_node	*new_node(int num, int index);
void	add_struct_back(t_node **stack_a, t_node *new);

//stack_creation
void	free_stack(t_all *all);
void	create_arrays(t_all *all, char **arr);
void	bubble_sort(t_all *all, int *sorted, int *not_sorted, int size);
void	create_stack_a(t_all *all, int *sorted, int *not_sorted, int size);

//push cmds
void	push_a(t_all *all);
void	push_b(t_all *all);
void	pa(t_all *all, int flag);
void	pb(t_all *all, int flag);
//reverse cmds
void	rra(t_all *all, int flag);
void	rrb(t_all *all, int flag);
void	rrr(t_all *all, int flag);
//rotate
void	ra(t_all *all, int flag);
void	rb(t_all *all, int flag);
void	rr(t_all *all, int flag);
//swap
void	sa(t_all *all, int flag);
void	sb(t_all *all, int flag);
void	ss(t_all *all, int flag);

//median
void	a_median(t_all *all);
void	b_median(t_all *all);
void	first_move_to_stack_b(t_all *all);
void	move_generation_down(t_all *all);
int		where_is_min(t_all *all);

//sort_numbers
//small
void	three_sort_a(t_all *all);
void	five_sort(t_all *all);
int		sort_ok(t_all *all);

//middle
void	five_sort_b(t_all *all);
void	sort_three_b_to_a(t_all *all);
void	generation_order(t_all *all, int flag);
void	five_sort_a(t_all *all, int i, int flag, int min);
void	generation_order_2(t_all *all, int flag);

//big
void	push_down(t_all *all);
void	move_a_to_b(t_all *all);
void	sort_big(t_all *all);
int		search_min(t_all *all);
void	search_min_2(t_all *all);

#endif