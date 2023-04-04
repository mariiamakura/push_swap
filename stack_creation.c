#include "push_swap.h"

void    create_arrays(t_all_numbers *all_numbers, char **arr)
{
    int *sorted;
    int *not_sorted;
    int num;
    int size;
    int i;

    size = 0;
    i = 0;
    while (arr[size])
        size++;
    sorted = malloc(sizeof(int) * size);
    not_sorted = malloc(sizeof(int) * size);
    while (i < size)
    {
        num = ft_atoi(arr[i]);
        not_sorted[i] = num;
        sorted[i] = num;
        i++;
    }
    bubble_sort(all_numbers, sorted, not_sorted, size);
}

void    bubble_sort(t_all_numbers *all_numbers, int *sorted, int *not_sorted, int size)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < (size - 1 - i)) // -1 because we always want know that after j there is another elment
        {
            if (sorted[j] > sorted[j + 1])
            {
                temp = sorted[j + 1];
                sorted[j + 1] = sorted[j];
                sorted[j] = temp;
            }
            j++;
        }
        i++;
    }
    //printf("Bubble sort is done\n"); //DELETE
    create_stack_a(all_numbers, sorted, not_sorted, size);
}

void    create_stack_a(t_all_numbers *all_numbers, int *sorted, int *not_sorted, int size)
{
    int i;
    int j;
    t_one_number *new_list;

    i = 0;
    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (not_sorted[i] == sorted[j])
            {
                new_list = new_node(not_sorted[i], j + 1); // j + 1 because we want index to start from 1 not 0
                add_struct_back(&all_numbers->stack_a, new_list);
            }
            j++;
        }
        i++;
    }
    free(sorted);
    free(not_sorted);
    //printf("stacks created");
}

void    free_stack(t_all_numbers *all_numbers)
{
    t_one_number *temp;

    while (all_numbers->size_a--)
    {
        temp = all_numbers->stack_a->next;
        free(all_numbers->stack_a);
        all_numbers->stack_a = NULL;
        all_numbers->stack_a = temp;
    }
    while (all_numbers->size_b--)
    {
        temp = all_numbers->stack_b->next;
        free(all_numbers->stack_b);
        all_numbers->stack_b = NULL;
        all_numbers->stack_b = temp;
    }
    free(all_numbers);
    //printf("stacks are freed\n");
}