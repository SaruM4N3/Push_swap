/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:00:30 by sarunomane        #+#    #+#             */
/*   Updated: 2025/02/10 16:29:33 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

static void rotate(t_stack **stack)
{
	// t_stack *tmp;
	// if (!tmp)
	// 	return ;
	// tmp = *src;
	// *src = (*src)->p_next;
	// tmp->p_next = *dest;
	// *dest = tmp;

}

void	ra(t_stack **stack)
{
	rotate(stack);
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	rotate(stack);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a,t_stack **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
