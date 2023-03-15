/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mparasku <mparasku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:53:05 by mparasku          #+#    #+#             */
/*   Updated: 2023/03/15 17:14:48 by mparasku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int arg_checker(int num_arg, char *str)
{
    if (num_arg == 1)
    {
        return(1);
    }
    return(0);
}

int main(int ac, char *ag[])
{
    char *c;

    arg_checker(ac);
    return(0);
}