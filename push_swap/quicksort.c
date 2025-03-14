/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:09:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/14 21:42:26 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to find the median as pivot
int find_median(t_stack *stack)
{
	//should define the median
    if (!stack)
        return 1;
    int median = stack->size / 2;
    return median;
}

// Partition function to divide stack correctly
void partition(t_stack *a, t_stack *b, int pivot)
{
    if (!a || a->size < 2) // Prevent operations on empty or single-element stack
        return;
    
    int size = a->size;
    int count = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (a->top->value < pivot)
        {
            pb(a, b); // Push to stack B if less than pivot
        }
        else
        {
            ra(a); // Rotate elements >= pivot
            count++;
        }
    }
    
    // Restore stack order
    while (count-- > 0)
        rra(a);
}

// Improved Quicksort implementation
void quicksort_stack(t_stack *a, t_stack *b)
{
    if (!a || is_sorted(a) || a->size < 2)
        return;
    
    int pivot = find_median(a); // Choose median as pivot
    partition(a, b, pivot);
    
    quicksort_stack(a, b); // Sort remaining elements in A
    quicksort_stack(b, a); // Sort elements in B
    
    while (b->size > 0)
    {
        pa(a, b); // Push back from B to A
    }
}
