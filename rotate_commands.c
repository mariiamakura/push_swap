#include "push_swap.h"

/*
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.*/

void ra(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_a > 1)
        all_numbers->stack_a = all_numbers->stack_a->next;
    if (flag)
        write (1, "ra\n", 3);
}

void rb(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_b > 1)
        all_numbers->stack_b = all_numbers->stack_b->next;
    if (flag)
        write (1, "rb\n", 3);
}

void rr(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_a > 1 && all_numbers->size_b > 1)
    {
        ra(all_numbers, 0);
        rb(all_numbers, 0);
        if (flag)
            write (1, "rr\n", 3);
    }
}
