/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:09:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/07 11:09:53 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Partition function to divide stack using allowed push_swap operations
void partition(t_stack *a, t_stack *b, int pivot)
{
    int size = a->size;
    int pushed = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (a->top->value < pivot)
        {
            pb(a, b); // Push to stack B if less than pivot
            pushed++;
        }
        else
            ra(a); // Rotate if greater or equal to pivot
    }
    
    // Bring back rotated elements
    while (size - pushed > 0)
    {
        rra(a);
        size--;
    }
}

// Quicksort implementation using only allowed operations
void quicksort_stack(t_stack *a, t_stack *b)
{
    if (is_sorted(a) || a->size < 2)
        return;
    
    int pivot = a->top->value; // Choose top element as pivot
    partition(a, b, pivot);
    
    quicksort_stack(a, b); // Sort remaining elements in A
    
    while (b->size > 0) // Push back elements from B to A
        pa(a, b);
}
