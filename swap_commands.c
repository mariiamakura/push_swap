#include "push_swap.h"

/*
sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.
ss : sa and sb at the same time.*/

void sa(t_all_numbers *all_numbers, int flag)
{
    int temp;

    if (all_numbers-> size_a < 2)
        return ;
    temp = all_numbers->stack_a->num;
    all_numbers->stack_a->num = all_numbers->stack_a->next->num;
    all_numbers->stack_a->next->num = temp;
    temp = all_numbers->stack_a->index;
    all_numbers->stack_a->index = all_numbers->stack_a->next->index;
    all_numbers->stack_a->next->index = temp;
    temp = all_numbers->stack_a->flag;
    all_numbers->stack_a->flag = all_numbers->stack_a->next->flag;
    all_numbers->stack_a->next->flag = temp;
    if (flag)
        write(1, "sa\n", 3);
}

void sb(t_all_numbers *all_numbers, int flag)
{
    int temp;

    if (all_numbers-> size_b < 2)
        return ;
    temp = all_numbers->stack_b->num;
    all_numbers->stack_b->num = all_numbers->stack_b->next->num;
    all_numbers->stack_b->next->num = temp;
    temp = all_numbers->stack_b->index;
    all_numbers->stack_b->index = all_numbers->stack_b->next->index;
    all_numbers->stack_b->next->index = temp;
    temp = all_numbers->stack_b->flag;
    all_numbers->stack_b->flag = all_numbers->stack_b->next->flag;
    all_numbers->stack_b->next->flag = temp;
    if (flag)
        write(1, "sb\n", 3);
}

void ss(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_a > 1 && all_numbers->size_b)
    {
        sa(all_numbers, 0);
        sb(all_numbers, 0);
        if (flag)
            write(1, "ss\n", 3);
    }
}