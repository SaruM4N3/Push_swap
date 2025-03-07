/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:15:18 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/07 11:15:29 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    
    if (argc < 2)
        return (0); // No arguments, nothing to do
    
    a = parse_input(argc, argv);
    b = init_stack();
    if (!b)
    {
        free_stack(a);
        return (1);
    }
    
    if (!is_sorted(a))
        quicksort_stack(a, b);
    
    free_stack(a);
    free_stack(b);
    return (0);
}
