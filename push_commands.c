#include "push_swap.h"

/*pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.*/

void push_a(t_all_numbers *all_numbers)
{
    t_one_number *temp;

    temp = all_numbers->stack_b->next;
    all_numbers->stack_b->previous->next = all_numbers->stack_b->next;
    all_numbers->stack_b->next->previous = all_numbers->stack_b->previous; //deleting node from stack b
    if (all_numbers->stack_a)
    {
        all_numbers->stack_b->previous = all_numbers->stack_a->previous;
        all_numbers->stack_b->next = all_numbers->stack_a;
        all_numbers->stack_a->previous->next = all_numbers->stack_b;
        all_numbers->stack_a->previous = all_numbers->stack_b;
        all_numbers->stack_a = all_numbers->stack_b;
    }
    else
    {
        all_numbers->stack_a = all_numbers->stack_b;
        all_numbers->stack_a->next = all_numbers->stack_a;
        all_numbers->stack_a->previous = all_numbers->stack_a;
    }
    all_numbers->stack_b = temp;
}

void push_b(t_all_numbers *all_numbers)
{
    t_one_number *temp;

    temp = all_numbers->stack_a->next;
    all_numbers->stack_a->previous->next = all_numbers->stack_a->next;
    all_numbers->stack_a->next->previous = all_numbers->stack_a->previous; //deleting node from stack b
    if (all_numbers->stack_b)
    {
        all_numbers->stack_a->previous = all_numbers->stack_b->previous;
        all_numbers->stack_a->next = all_numbers->stack_b;
        all_numbers->stack_b->previous->next = all_numbers->stack_a;
        all_numbers->stack_b->previous = all_numbers->stack_a;
        all_numbers->stack_b = all_numbers->stack_a;
    }
    else
    {
        all_numbers->stack_b = all_numbers->stack_a;
        all_numbers->stack_a->next = all_numbers->stack_b;
        all_numbers->stack_a->previous = all_numbers->stack_b;
    }
    all_numbers->stack_a = temp;
}

void    pa(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_b == 0)
        return ;
    push_a(all_numbers);
    if (all_numbers->size_b == 1)
        all_numbers->stack_b = NULL;
    all_numbers->size_b--;
    all_numbers->size_a++;
    if (flag)
        write(1, "pa\n", 3);
}

void    pb(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->size_a == 0)
        return ;
    push_b(all_numbers);
    if (all_numbers->size_a == 1)
        all_numbers->stack_a = NULL;
    all_numbers->size_a--;
    all_numbers->size_b++;
    if (flag)
        write(1, "pb\n", 3);
}