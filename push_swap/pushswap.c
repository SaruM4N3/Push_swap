/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 11:15:18 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/14 20:37:18 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2)
		return (0);
	a = parse_input(argc, argv);
	if (!a)
		return (1);
	b = init_stack();
	if (!b)
	{
		free_stack(a);
		return (1);
	}
	if (!is_sorted(a))
		quicksort_stack(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
