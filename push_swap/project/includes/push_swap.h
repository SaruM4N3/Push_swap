/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:02:12 by zsonie            #+#    #+#             */
/*   Updated: 2025/02/10 16:42:26 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

#include<stddef.h>

typedef struct s_stack
{
	int	value;
	struct node *p_next;
	struct node *p_previous;
}	t_stack;


#endif 
