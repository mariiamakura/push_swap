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
        //if (all_numbers->size_b > 1)
        if (all_numbers->stack_a->index == min)
            push_down(all_numbers);
        else
            pb(all_numbers, 1);
    }
    return ;
}