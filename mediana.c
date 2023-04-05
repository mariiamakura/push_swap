#include "push_swap.h"

void a_median(t_all_numbers *all_numbers)
{
    int i;
    int min;
    int max;

    if (all_numbers->size_a == 0)
        return ;
    i = all_numbers->size_a;
    min = all_numbers->stack_a->index;
    max = all_numbers->stack_a->index;

    while (i > 0)
    {
        if (min > all_numbers->stack_a->index)
            min = all_numbers->stack_a->index;
        if (max < all_numbers->stack_a->index)
            max = all_numbers->stack_a->index;
        all_numbers->stack_a = all_numbers->stack_a->next;
        i--;
    }
    all_numbers->min = min;
    all_numbers->max = max;
    all_numbers->median = (min + max) / 2;
}

void b_median(t_all_numbers *all_numbers)
{
    int i;
    int min;
    int max;

    if (all_numbers->size_b == 0)
        return ;
    i = all_numbers->size_b;
    min = all_numbers->stack_b->index;
    max = all_numbers->stack_b->index;

    while (i > 0)
    {
        if (min > all_numbers->stack_b->index)
            min = all_numbers->stack_b->index;
        if (max < all_numbers->stack_b->index)
            max = all_numbers->stack_b->index;
        all_numbers->stack_b = all_numbers->stack_b->next;
        i--;
    }
    //all_numbers->min = min;
    all_numbers->max = max;
    all_numbers->median = (min + max) / 2;
}

void move_generation_down(t_all_numbers *all_numbers)
{
        while (all_numbers->stack_b->previous->flag == -1)
            rrb(all_numbers, 1);
        while (all_numbers->stack_b->flag == -1) {
            pa(all_numbers, 1);
            ra(all_numbers, 1);
        }
}


void first_move_to_stack_b(t_all_numbers *all_numbers)
{
    int i;

    a_median(all_numbers);
    i = all_numbers->size_a;
    while (i-- > 0)
    {
        if (all_numbers->stack_a->index <= all_numbers->median)
        {
            pb(all_numbers, 1);
            if (all_numbers->stack_b->index == all_numbers->min)
            {
                all_numbers->stack_b->flag = -1;
                rb(all_numbers, 1);
            }
        }
        else
        {
            if (all_numbers->size_b == all_numbers->max - all_numbers->median + 1)
                break ;
            else
                ra(all_numbers, 1);
        }
    }
    if (all_numbers->stack_b)
        move_generation_down(all_numbers);
}

int where_is_min(t_all_numbers *all_numbers)
{
    int i;
    int j;
    t_one_number *temp;

    temp = all_numbers->stack_a;
    i = 0;
    while (++i)
    {
        if (temp->index == all_numbers->min)
            break ;
        temp = temp->next;
    }
    temp = all_numbers->stack_a;
    j = 0;
    while(++j)
    {
        if (temp->index == all_numbers->min)
            break ;
        temp = temp->previous;
    }
    if (j >= i)
        return (1);
    return (0);
}