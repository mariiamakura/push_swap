#include "push_swap.h"

void    generation_order(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->stack_a->index > all_numbers->stack_a->next->index &&
    all_numbers->stack_a->flag == all_numbers->stack_a->next->flag)
        sa(all_numbers, 1);
    while (all_numbers->size_b != 0)
    {
        if (all_numbers->stack_a->index > all_numbers->stack_b->index ||
        all_numbers->stack_a->flag == -1)
        {
            pa(all_numbers, 1);
            push_down(all_numbers);
        }
        else
            push_down(all_numbers);
    }
    while (all_numbers->stack_a->flag == flag && flag != -1 &&
    !all_numbers->stack_a->index + 1 == all_numbers->stack_a->previous->index)
        push_down(all_numbers);
}

void generation_order_2(t_all_numbers *all_numbers, int flag)
{
    if (all_numbers->stack_a->index > all_numbers->stack_a->next->index &&
        all_numbers->stack_a->flag == all_numbers->stack_a->next->flag)
        sa(all_numbers, 1);
    while (all_numbers->size_b != 0)
    {
        if (all_numbers->stack_a->index > all_numbers->stack_b->index ||
            all_numbers->stack_a->flag != flag)
        {
            pa(all_numbers, 1);
            push_down(all_numbers);
        }
        else
            push_down(all_numbers);
        while (all_numbers->stack_a->flag == flag && flag != -1)
            push_down(all_numbers);
    }
}


void sort_three_b_to_a(t_all_numbers *all_numbers)
{
    int a;
    int b;
    int c;

    if (all_numbers->size_b == 0)
        return ;
    a = all_numbers->stack_b->index;
    b = all_numbers->stack_b->next->index;
    c = all_numbers->stack_b->previous->index;
    if (b > a && b > c)
        rrb(all_numbers, 1);
    else if (a > b && a > c)
        rb(all_numbers, 1);
    a = all_numbers->stack_b->index;
    b = all_numbers->stack_b->next->index;
    if (a > b)
        sb(all_numbers, 1);
}

void five_sort_b(t_all_numbers *all_numbers)
{
    int i;
    int min;
    int flag;
    t_one_number *temp;

    temp = all_numbers->stack_a; //maybe i dont need it
    i = all_numbers->size_b;
    min = all_numbers->stack_a->previous->index + 1;
    flag = all_numbers->stack_a->flag;

    while (i > 3)
    {
        if (all_numbers->stack_b->index == min)
        {
            pa(all_numbers, 1);
            push_down(all_numbers);
            min++;
        }
        else
            pa (all_numbers, 1);
        i--;
    }
    sort_three_b_to_a(all_numbers);
    generation_order(all_numbers, flag);
}

void five_sort_a(t_all_numbers *all_numbers)
{
    t_one_number *temp;
    int i;
    int flag;
    int min;

    i = 0;
    min = all_numbers->stack_a->previous->index + 1;
    flag = all_numbers->stack_a->flag;
    temp = all_numbers->stack_a;

    while (temp->flag == flag && flag != -1)
    {
        temp = temp->next;
        i++;
    }
    if (i <= 5)
    {
        while (i > 2)
        {
            if (all_numbers->stack_a->index == min)
            {
                push_down(all_numbers);
                min++;
            }
            else
                pb(all_numbers, 1);
            i--;
        }
        sort_three_b_to_a(all_numbers);
        generation_order_2(all_numbers, flag);
    }
}
