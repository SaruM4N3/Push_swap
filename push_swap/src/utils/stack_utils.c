/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 16:01:46 by zsonie            #+#    #+#             */
/*   Updated: 2025/03/21 16:01:46 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//calculates and returns the length of a stack
int	stack_lenght(t_stack_node *stack)
{
	int	lenght;

	if (!stack) 
		return (0);
	lenght = 0;
	while (stack)
	{
		stack = stack->next;
		lenght++;
	}
	return (lenght);
}

//returns the pointer to the last node
t_stack_node	*find_last(t_stack_node *stack) 
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

//checks if the stack is sorted in ascending order
bool	is_sorted(t_stack_node *stack) 
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//searches a stack and returns the node with the smallest number
t_stack_node	*lowest_value(t_stack_node *stack) 
{
	long			lowest;
	t_stack_node	*lowest_node;

	if (!stack)
		return (NULL);
	lowest = LONG_MAX;
	while (stack)
	{
		if (stack->value < lowest)
		{
			lowest = stack->value;
			lowest_node = stack;
		}
		stack = stack->next;
	}
	return (lowest_node); 
}

// searches a stack and returns the node with the biggest number
t_stack_node	*highest_value(t_stack_node *stack) 
{
	long			highest;
	t_stack_node	*highest_node;

	if (!stack)
		return (NULL);
	highest = LONG_MIN;
	while (stack) 
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}