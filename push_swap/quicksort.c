/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:09:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/11 12:26:42 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Convert stack to an array for median calculation
int *stack_to_array(t_stack *stack)
{
    if (!stack || stack->size == 0)
        return NULL;
    
    int *arr = malloc(sizeof(int) * stack->size);
    if (!arr)
        return NULL;
    
    t_node *current = stack->top;
    for (int i = 0; i < stack->size; i++)
    {
        arr[i] = current->value;
        current = current->next;
    }
    
    // Sort the array to find median
    for (int i = 0; i < stack->size - 1; i++)
    {
        for (int j = i + 1; j < stack->size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

// Function to find the median as pivot
int find_median(t_stack *stack)
{
    int *arr = stack_to_array(stack);
    if (!arr)
        return stack ? stack->top->value : 0;
    int median = arr[stack->size / 2];
    free(arr);
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
