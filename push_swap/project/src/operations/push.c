/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:00:30 by sarunomane        #+#    #+#             */
/*   Updated: 2025/02/10 16:20:52 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void push(t_stack **src, t_stack **dest)
{
	t_stack *tmp;
	if (!tmp)
		return ;
	tmp = *src;
	*src = (*src)->p_next;
	tmp->p_next = *dest;
	*dest = tmp;

}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
