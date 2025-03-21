/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:29:29 by zsonie            #+#    #+#             */
/*   Updated: 2025/03/21 17:29:29 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate_both(t_stack_node **a,t_stack_node **b,t_stack_node *cheapest_node) 
{
	while (*b != cheapest_node->target && *a != cheapest_node)
		rr(a, b);
	current_index(*a);
	current_index(*b);
}

void	rev_rotate_both(t_stack_node **a,t_stack_node **b,t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target
		&& *a != cheapest_node)
		rrr(a, b);
	current_index(*a);
	current_index(*b);
}

//prepares the cheapest nodes on top of the stacks for pushing `a` nodes to stack `b`, until there are three nodes left in `a`
void	move_a_to_b(t_stack_node **a, t_stack_node **b) 
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median 
		&& cheapest_node->target->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) 
		&& !(cheapest_node->target->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target, 'b');
	pb(b, a);
}

//prepares `b`'s target `a` nodes for pushing all `b` nodes back to stack `a` 
void	move_b_to_a(t_stack_node **a, t_stack_node **b) 
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, false); 
}

 //moves the lowest number to the top
void	lowest_on_top(t_stack_node **a)
{
	while ((*a)->value != lowest_value(*a)->value)
	{
		if (lowest_value(*a)->above_median)
			ra(a, false);
		else
			rra(a, false);
	}
}
