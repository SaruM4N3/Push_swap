/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:32:29 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/07 11:35:01 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate stack a upwards (first element becomes last)
void ra(t_stack *a)
{
    if (!a || a->size < 2)
        return;
    
    t_node *first = a->top;
    t_node *last = a->top;
    while (last->next)
        last = last->next;
    
    a->top = first->next;
    first->next = NULL;
    last->next = first;
    
    printf("ra\n");
}

// Rotate stack b upwards
void rb(t_stack *b)
{
    if (!b || b->size < 2)
        return;
    
    t_node *first = b->top;
    t_node *last = b->top;
    while (last->next)
        last = last->next;
    
    b->top = first->next;
    first->next = NULL;
    last->next = first;
    
    printf("rb\n");
}

// Rotate both stacks at the same time
void rr(t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
    printf("rr\n");
}
