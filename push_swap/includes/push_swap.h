/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 06:02:12 by zsonie            #+#    #+#             */
/*   Updated: 2025/03/11 11:48:04 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

// Stack Node Structure
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

// Stack Structure
typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;

// Stack Management Functions
t_stack *init_stack();
void push_stack(t_stack *stack, int value);
int pop_stack(t_stack *stack);
void free_stack(t_stack *stack);
bool is_sorted(t_stack *stack);

// Parsing Function
t_stack *parse_input(int argc, char **argv);

// Sorting Algorithm
int *stack_to_array(t_stack *stack);
int find_median(t_stack *stack);
void partition(t_stack *a, t_stack *b, int pivot);
void quicksort_stack(t_stack *a, t_stack *b);

// Push Swap Operations
void sa(t_stack *a);
void sb(t_stack *b);
void ss(t_stack *a, t_stack *b);
void pa(t_stack *a, t_stack *b);
void pb(t_stack *a, t_stack *b);
void ra(t_stack *a);
void rb(t_stack *b);
void rr(t_stack *a, t_stack *b);
void rra(t_stack *a);
void rrb(t_stack *b);
void rrr(t_stack *a, t_stack *b);

#endif
