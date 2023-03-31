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

    if (all_numbers->size_b== 0)
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