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

// Function to compare two integers for qsort
int	compare(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

// Function to find the median value of the stack
int	find_median_value(t_stack *stack)
{
	int		*values;
	t_node	*current;
	int		median_value;

	int i, j, temp;
	if (!stack || stack->size == 0)
		return (0);
	values = malloc(stack->size * sizeof(int));
	if (!values)
		return (0);
	current = stack->top;
	i = 0;
	while (i < stack->size)
	{
		values[i] = current->value;
		current = current->next;
		i++;
	}
	// Bubble sort to sort the values
	i = 0;
	while (i < stack->size - 1)
	{
		j = 0;
		while (j < stack->size - i - 1)
		{
			if (values[j] > values[j + 1])
			{
				temp = values[j];
				values[j] = values[j + 1];
				values[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	median_value = values[stack->size / 2];
	free(values);
	return (median_value);
}

// Partition function to divide stack correctly
void	partition(t_stack *a, t_stack *b, int pivot)
{
	int	size;
	int	count;

	if (!a || a->size < 2)
		return ;
	size = a->size;
	count = 0;
	while (size > 0)
	{
		if (a->top->value < pivot)
		{
			pb(a, b); // Push to stack B if less than pivot
		}
		else
		{
			ra(a); // Rotate elements >= pivot
			count++;
		}
		size--;
	}
	// Restore stack order
	while (count > 0)
	{
		rra(a);
		count--;
	}
}

void	quicksort_stack(t_stack *a, t_stack *b)
{
	int	size_a;

	if (!a || is_sorted(a) || a->size < 2)
		return ;
	int pivot = find_median_value(a); // Choose median value as pivot
	partition(a, b, pivot);
	// Sort the part of stack 'a' that is less than the pivot
	size_a = a->size;
	while (size_a > 0)
	{
		if (a->top->value >= pivot)
			break ;
		ra(a);
		size_a--;
	}
	// Sort the part of stack 'b' that is less than the pivot
	quicksort_stack(b, a);
	// Push back from B to A
	while (b->size > 0)
	{
		pa(a, b);
	}
	// Sort the part of stack 'a' that is greater than or equal to the pivot
	quicksort_stack(a, b);
}
