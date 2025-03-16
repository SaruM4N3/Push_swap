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

#include <push_swap.h>

int	compare(const int *a, const int *b)
{
	return (a - b);
}
int highest_value(t_stack *stack)
{
	t_node *current;
	int highest;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	highest = current->value;
	while (current)
	{
		if (current->value > highest)
			highest = current->value;
		current = current->next;
	}
	return (highest);
}

int lowest_value(t_stack *stack)
{
	t_node *current;
	int lowest;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	lowest = current->value;
	while (current)
	{
		if (current->value < lowest)
			lowest = current->value;
		current = current->next;
	}
	return (lowest);
}
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

	if (!a )
		return ;
	while (a->size > 1)
	{
		if (a->top->value < lowpivot)
		{
			//if value is less than pivot, push to bottom of stack B
			pb(a,b);
			rrb(b);
		}
		else if (a->top->value > highpivot)
		{
			//push to the top of stack B
			pb(a,b);
			if (b->top->value < b->top->next->value)
				sb(b);
		}
			
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

	// Sort the stacks
	while (b->size > 0)
	{
	}
	quicksort_stack(a, b);
}
