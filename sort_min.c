#include "push_swap.h"

int sort_ok(t_all_numbers *all_numbers)
{
    int i;
    t_one_number *start;

    start = all_numbers->stack_a;
    i = all_numbers->size_a - 1;
    while(i > 0)
    {
        if (start->index > start->next->index)
            return(0);
        start = start->next;
        i--;
    }
    //printf("this is sort ok\n");
    //print_struct(all_numbers);
    return(1);
}

/*void	three_sort_b(t_all_numbers *all_numbers)
{
    int	a;
    int	b;
    int	c;
    int	i;

    a = all_numbers->stack_b->index;
    b = all_numbers->stack_b->next->index;
    c = all_numbers->stack_b->previous->index;
    i = all_numbers->size_b;
    if (b > a && b > c)
        rrb(all_numbers, 1);
    else if (a > b && a > c)
        rb(all_numbers, 1);
    a = all_numbers->stack_b->index;
    b = all_numbers->stack_b->next->index;
    if (a > b)
        sb(all_numbers, 1);
    while (i-- > 0)
    {
        all_numbers->stack_b->flag = -1;
        pa(all_numbers, 1);
        ra(all_numbers, 1);
    }
}*/

void    three_sort_a(t_all_numbers *all_numbers)
{
    int a;
    int b;
    int c;

    a = all_numbers->stack_a->index;
    b = all_numbers->stack_a->next->index;
    c = all_numbers->stack_a->previous->index;
    if (a > b && a > c)
        ra(all_numbers, 1);
    else if (b > a && b > c)
        rra(all_numbers, 1);
    a = all_numbers->stack_a->index;
    b = all_numbers->stack_a->next->index;
    if (a > b)
        sa(all_numbers, 1);
}

void    five_sort(t_all_numbers *all_numbers)
{
    while (all_numbers->size_a > 3)
    {
        a_median(all_numbers);
        //print_struct(all_numbers);
        //printf("min: %i\n", all_numbers->min);
        if (all_numbers->stack_a->index == all_numbers->min)
        {
            pb(all_numbers, 1);
            continue ;
        }
        if (where_is_min(all_numbers))
            ra(all_numbers, 1);
        else
            rra(all_numbers, 1);
    }
    three_sort_a(all_numbers);
    pa(all_numbers, 1);
    pa(all_numbers, 1);
    //print_struct(all_numbers);
}

