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