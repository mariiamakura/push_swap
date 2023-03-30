#include "push_swap.h"

/*
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.*/

void rra(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_a > 1)
        all_numbers->stack_a = all_numbers->stack_a->previous;
    if (flag)
        write(1, "rra\n", 4);
}

void    rrb(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_b > 1)
        all_numbers->stack_b = all_numbers->stack_b->previous;
    if (flag)
        write(1, "rrb\b", 4);
}

void rrr(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_b > 1 && all_numbers->size_a > 1) {
        rra(all_numbers, 0);
        rrb(all_numbers, 0);
        if (flag)
            write(1, "rrr\n", 4);
    }
}