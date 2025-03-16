/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 10:30:21 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/07 11:34:44 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// Push the top element from stack b to stack a
void	pa(t_stack *a, t_stack *b)
{
	t_node	*top_b;

	if (!b || b->size == 0)
		return ;
	top_b = b->top;
	b->top = top_b->next;
	b->size--;
	top_b->next = a->top;
	a->top = top_b;
	a->size++;
	printf("pa\n");
}

// Push the top element from stack a to stack b
void	pb(t_stack *a, t_stack *b)
{
	if (!a || a->size == 0)
		return ;

	t_node *top_a = a->top;
	a->top = top_a->next;
	a->size--;

	top_a->next = b->top;
	b->top = top_a;
	b->size++;

	printf("pb\n");
}