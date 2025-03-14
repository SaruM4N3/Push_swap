/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:14:26 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/11 12:05:44 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

t_stack *parse_input(int argc, char **argv)
{
    t_stack *stack;
    int i;
    int num;

    stack = init_stack();
    if (!stack)
        return (NULL);
    i = 1;
    while (i < argc)
    {
        num = ft_atoi(argv[i]);  // Assuming ft_atoi converts string to int with error checking.
        if (num > INT_MAX || num < INT_MIN)
        {
            free_stack(stack);
            return (NULL);
        }
        push_bottom(stack, num);
        i++;
    }
    return (stack);
}
