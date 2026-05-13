/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:51:28 by zsonie            #+#    #+#             */
/*   Updated: 2025/03/21 20:06:16 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int	lenght_stack_a;

	lenght_stack_a = stack_lenght(*a);

	if (lenght_stack_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (lenght_stack_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		push_cheapest_from_a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		push_cheapest_from_b_to_a(a, b);
	}
	assign_index(*a);
	lowest_on_top(a);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = highest_value(*a);
	if (highest_node == *a)
		ra(a);
	else if ((*a)->next == highest_node)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}
