/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:36:10 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/07 11:36:27 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialize a new stack
t_stack *init_stack()
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
    stack->top = NULL;
    stack->size = 0;
    return (stack);
}

// Free all elements in a stack
void free_stack(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *next;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}

// Check if the stack is sorted in ascending order
bool is_sorted(t_stack *stack)
{
    if (!stack || stack->size < 2)
        return (true);
    
    t_node *current = stack->top;
    while (current->next)
    {
        if (current->value > current->next->value)
            return (false);
        current = current->next;
    }
    return (true);
}

// Push a value onto the stack (linked list implementation)
void push_stack(t_stack *stack, int value)
{
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}