/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:09:48 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/14 21:42:26 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_medians_value(t_stack *stack)
{
	int median_value;
	int highest;
	int lowest;

	if (!stack || stack->size == 0)
		return (0);

	highest = highest_value(stack);
	lowest = lowest_value(stack);
	median_value = (highest + lowest) / 3;
	return (median_value);
}

// Partition function to divide stack correctly
void	partition(t_stack *a, t_stack *b, int lowpivot, int highpivot)
{
	int	count;

	count = find_lower_than_pivot(a, lowpivot);
	if (count == 0)
		count = find_higher_than_pivot(a, highpivot);
	if (!a )
		return ;
	while (a->size > 0)
	{
		if (a->top->value < lowpivot)
			pb(a,b);
		else if (a->top->value >= lowpivot && a->top->value < highpivot)
			pb(a,b);
		else
			ra(a);
		a->size--;
	}
}

void	quicksort_stack(t_stack *a, t_stack *b)
{
	if (!a || is_sorted(a) || a->size < 2)
		return ;
	int lowpivot = find_medians_value(a); // Choose median value as pivot
	int highpivot = lowpivot *2;
	// Partition the stack
	partition(a, b, lowpivot, highpivot);

	// Sort the stack
	quicksort_stack(a, b);
}
