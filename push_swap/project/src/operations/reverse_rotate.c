/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:00:30 by sarunomane        #+#    #+#             */
/*   Updated: 2025/02/10 16:28:22 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void reverse_rotate(t_stack **stack)
{
	// t_stack *tmp;
	// if (!tmp)
	// 	return ;
	// tmp = *src;
	// *src = (*src)->p_next;
	// tmp->p_next = *dest;
	// *dest = tmp;

}

void	rra(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "ra\n", 4);
}

void	rrb(t_stack **stack)
{
	reverse_rotate(stack);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a,t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
