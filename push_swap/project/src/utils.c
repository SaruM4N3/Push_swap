/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:36:01 by sarunomane        #+#    #+#             */
/*   Updated: 2025/02/10 16:48:01 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_list_size(t_stack **s)
{
	size_t	stack_size;

	stack_size = 0;
	
	while ((*s)->p_next)
	{
		stack_size++;
	}
}
