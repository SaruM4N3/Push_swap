/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: sarunomane <sarunomane@student.42.fr>      +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/03/16 21:44:15 by sarunomane        #+#    #+#             */
/*   Updated: 2025/03/16 21:44:15 by sarunomane       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: zsonie <zsonie@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/02/07 06:02:12 by zsonie            #+#    #+#             */
/*   Updated: 2025/03/14 20:35:57 by zsonie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/headers/ft_printf.h"
# include "../libft/headers/libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# ifdef _WIN32
#  include <io.h>
#  define ACCESS _access
# else
#  include <unistd.h>
# endif

// Stack Structure
typedef struct s_stack_node
{
	int					value;
	int					index;
	int					cost;
	bool				is_above_median;
	bool				is_cheapest;
	struct s_stack_node	*target;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

///////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------//
//------------------------ALGORITHM----------------------------------------//
//------------------------------------------------------------------------//
///////////////////////////////////////////////////////////////////////////

// algo_utils.c
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			push_cheapest_from_a_to_b(t_stack_node **a, t_stack_node **b);
void			push_cheapest_from_b_to_a(t_stack_node **a, t_stack_node **b);
void			lowest_on_top(t_stack_node **a);

// sort_stacks.c
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

///////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------//
//------------------------OPERATIONS---------------------------------------//
//------------------------------------------------------------------------//
///////////////////////////////////////////////////////////////////////////

// push.c
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
// reverserotate.c
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
// rotate.c
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
// swap.c
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);

///////////////////////////////////////////////////////////////////////////////
//--------------------------------------------------------------------------//
//------------------------UTILS--------------------------------------------//
//------------------------------------------------------------------------//
///////////////////////////////////////////////////////////////////////////

// errors.c
int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_and_print_error(t_stack_node **a);
// init_a_to_b.c
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			current_index(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);

// init_b_to_a.c
void			init_nodes_b(t_stack_node *a, t_stack_node *b);

// stack_init.c
void			init_stack_a(t_stack_node **a, char **argv);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);

// split.c
char			**split(char *s, char c);

// stack_utils.c
int				stack_lenght(t_stack_node *stack);
t_stack_node	*get_last_node(t_stack_node *stack);
bool			is_sorted(t_stack_node *stack);
t_stack_node	*lowest_value(t_stack_node *stack);
t_stack_node	*highest_value(t_stack_node *stack);

#endif
