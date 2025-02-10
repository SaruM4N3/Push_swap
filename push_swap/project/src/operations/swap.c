/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:00:30 by sarunomane        #+#    #+#             */
/*   Updated: 2025/02/10 16:35:50 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/push_swap.h"

static void swap(t_stack **stack)
{
	// t_stack *tmp;
	// if (!tmp)
	// 	return ;
	// tmp = *src;
	// *src = (*src)->p_next;
	// tmp->p_next = *dest;
	// *dest = tmp;

}

void	sa(t_stack **stack)
{
	swap(stack);
	write(1, "sa\n", 3);
}

void	sb(t_stack **stack)
{
	swap(stack);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a,t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
