/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:28:15 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/16 21:51:05 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	find_lower_than_pivot(t_stack *stack, int pivot)
{
	t_node *current;
	int count;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	count = 0;
	while (current)
	{
		if (current->value < pivot)
			count++;
		current = current->next;
	}
	return (count);
}

int	find_higher_than_pivot(t_stack *stack, int pivot)
{
	t_node *current;
	int count;

	if (!stack || stack->size == 0)
		return (0);
	current = stack->top;
	count = 0;
	while (current)
	{
		if (current->value >= pivot)
			count++;
		current = current->next;
	}
	return (count);
}
