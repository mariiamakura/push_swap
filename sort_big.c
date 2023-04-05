#include "push_swap.h"

void push_down(t_all_numbers *all_numbers)
{
    all_numbers->stack_a->flag = -1;
    ra(all_numbers, 1);
}

void move_a_to_b(t_all_numbers *all_numbers)
{
    int flag;
    int min;

    flag = all_numbers->stack_a->flag;
    while (all_numbers->stack_a->flag == flag && flag != -1)
    {
        min = all_numbers->stack_a->previous->index + 1;
        if (all_numbers->size_b > 1)
            search_min_2(all_numbers);
        if (all_numbers->stack_a->index == min)
            push_down(all_numbers);
        else
            pb(all_numbers, 1);
    }
}

void search_min_2(t_all_numbers *all_numbers)
{
    int min;

    min = all_numbers->stack_a->previous->index + 1;
    if (all_numbers->stack_b->index == min)
    {
        pa(all_numbers, 1);
        push_down(all_numbers);
    }
    else if (all_numbers->stack_b->next->index == min)
    {
        sb(all_numbers, 1);
        pa(all_numbers, 1);
        push_down(all_numbers);
    }
    else if (all_numbers->stack_b->previous->index == min)
    {
        rrb(all_numbers, 1);
        pa(all_numbers, 1);
        push_down(all_numbers);
    }
    else if (all_numbers->stack_a->next->index == min)
    {
        sa(all_numbers, 1);
        push_down(all_numbers);
    }
}

int search_min(t_all_numbers *all_numbers)
{
    int min;

    min = all_numbers->stack_a->previous->index + 1;
    if (all_numbers->stack_b->index == min)
    {
        pa(all_numbers, 1);
        push_down(all_numbers);
        return (1);
    }
    else if (all_numbers->stack_a->index == min)
        push_down(all_numbers);
    else if (all_numbers->stack_a->next->index == min)
    {
        sa(all_numbers, 1);
        push_down(all_numbers);
    }
    return (0);
}

void sort_big(t_all_numbers *all_numbers)
{
    int i;

    i = all_numbers->size_b;
    b_median(all_numbers);
    while (i-- > 0)
    {
        if (search_min(all_numbers))
            continue ;
        if (all_numbers->stack_b->index > all_numbers->median)
        {
            all_numbers->stack_b->flag++;
            pa(all_numbers, 1);
        }
        else
        {
            all_numbers->stack_b->flag++;
            rb(all_numbers, 1);
        }
    }
}