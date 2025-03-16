/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:14:26 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/14 20:36:40 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// check if a string is a valid integer
static int	is_valid_number(const char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

// check for duplicates in the stack
static int	has_duplicates(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

// parse input arguments into stack
t_stack	*parse_input(int argc, char **argv)
{
	t_stack	*stack;
	long	num;
	int i = argc;

	stack = init_stack();
	if (!stack)
		return (NULL);
	while (--i > 0)
	{
		if (!is_valid_number(argv[i]))
		{
			write(2, "Error\n", 6);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN || has_duplicates(stack, (int)num))
		{
			write(2, "Error\n", 6);
			free_stack(stack);
			exit(EXIT_FAILURE);
		}
		push_stack(stack, (int)num);
	}
	return (stack);
}
