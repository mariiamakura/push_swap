#include "push_swap.h"

 void	print_2d_array(char **arr)
{
	int	i;

	i = 0; // initialize the counter
    while (arr[i] != NULL) // iterate over each string in the array
       {
            printf("%s ", arr[i]); // print the string followed by a space
            i++; // increment the counter
        }
    printf("\n");
}

void print_struct(t_all_numbers *all_numbers)
{
    int a_size = all_numbers->size_a;
    t_one_number *current_a = all_numbers -> stack_a;
    while(a_size--) //the last number in list or it will be infinite loop
    {
        printf("num: %i, index: %i\n", current_a->num, current_a->index);
        current_a = current_a->next;
    }
}