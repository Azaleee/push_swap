/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:36:56 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/18 21:43:13 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <stddef.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	int				cost;
	int				pose;
	struct s_node	*target_node;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	t_node	*median;
	int		size;
}			t_stack;

void	push(t_stack **src, t_stack **dest);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	swap(t_stack **stack);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	rotate(t_stack **stack);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	reverse_rotate(t_stack **stack);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	print_stack(t_stack **stack);
void	push_stack(t_stack *stack, int value);
t_stack	*init_stack(void);
t_stack	*fill_stack(int ac, char **av);
void	update_position(t_stack *stack);

void	check_input(int ac, char **av);
int		is_num(const char *str);

void	exit_error(void);

void	three_sort(t_stack **a);
void	turk_algo(t_stack **a, t_stack **b);
void	set_target_node(t_node *b, t_stack **a);
t_node	*best_target_node(t_node *b, t_stack **a);
t_node	*find_min_number(t_stack **a);

int		stack_is_sorted(t_stack **stack);

int		main(int ac, char **av);

#endif