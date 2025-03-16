/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:33:04 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/07 11:35:16 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Reverse rotate stack a (last element becomes first)
void rra(t_stack *a)
{
    if (!a || a->size < 2)
        return;
    
    t_node *prev = NULL;
    t_node *last = a->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    
    prev->next = NULL;
    last->next = a->top;
    a->top = last;
    
    printf("rra\n");
}

// Reverse rotate stack b
void rrb(t_stack *b)
{
    if (!b || b->size < 2)
        return;
    
    t_node *prev = NULL;
    t_node *last = b->top;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    
    prev->next = NULL;
    last->next = b->top;
    b->top = last;
    
    printf("rrb\n");
}

// Reverse rotate both stacks
void rrr(t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
    printf("rrr\n");
}
