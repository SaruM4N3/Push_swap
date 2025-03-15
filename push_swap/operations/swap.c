/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:31:11 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/07 11:34:26 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two elements of stack a
void sa(t_stack *a)
{
    if (!a || a->size < 2)
        return;
    
    t_node *first = a->top;
    t_node *second = first->next;
    
    first->next = second->next;
    second->next = first;
    a->top = second;
    
    printf("sa\n");
}

// Swap the first two elements of stack b
void sb(t_stack *b)
{
    if (!b || b->size < 2)
        return;
    
    t_node *first = b->top;
    t_node *second = first->next;
    
    first->next = second->next;
    second->next = first;
    b->top = second;
    
    printf("sb\n");
}

// Swap both a and b at the same time
void ss(t_stack *a, t_stack *b)
{
    sa(a);
    sb(b);
    printf("ss\n");
}
