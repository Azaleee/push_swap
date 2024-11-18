/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:29:16 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/18 21:10:25 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Pousser les deux premiers noeuds de stack a dans b tant que a n'est pas 3
// Tant que la taille de n'est pas de 3
	// Set les target node de la list a

t_node	*best_target_node(t_node *b, t_stack **a)
{
	t_node	*current_a;
	t_node	*best_target;
	int		diff;
	int		min;

	min = INT_MIN;
	current_a = (*a)->top;
	best_target = NULL;
	while (current_a != NULL)
	{
		diff = b->value - current_a->value;
		if (diff < 0 && diff > min)
		{
			min = diff;
			best_target = current_a;
		}
		current_a = current_a->next;
	}
	return (best_target);
}

t_node	*find_min_number(t_stack **a)
{
	t_node	*current_a;
	t_node	*best_target_temp;

	current_a = (*a)->top;
	best_target_temp = NULL;
	while (current_a != NULL)
	{
		if (best_target_temp == NULL
			|| current_a->value < best_target_temp->value)
			best_target_temp = current_a;
		current_a = current_a->next;
	}
	return (best_target_temp);
}

void	set_target_node(t_node *b, t_stack **a)
{
	b->target_node = best_target_node(b, a);
	if (b->target_node == NULL)
		b->target_node = find_min_number(a);
}

void	calculate_cost(t_node *b, t_stack **a)
{
	int	cost;

	cost = 0;
	if (b->target_node == NULL)
		return ;
	if (b->prev == NULL && (*a)->top == b->target_node)
		b->cost = 0;
}

void	print_target_node(t_stack **a)
{
	t_node	*current;
	int		i;

	current = (*a)->top;
	i = 1;
	while (current)
	{
		if (current->target_node != NULL)
			ft_printf("%d -> %d target : %d -> cost : %d\n", i, current->value, current->target_node->value, current->cost);
		else
			ft_printf("%d -> %d target : pas verif\n", i, current->value);
		current = current->next;
		i++;
	}
	ft_printf("\n");
}

void	turk_algo(t_stack **a, t_stack **b)
{
	while ((*a)->size > 3)
	{
		pb(a, b);
		print_stack(a);
		print_stack(b);
	}
	three_sort(a);
	print_stack(a);
	print_stack(b);
	set_target_node((*b)->top, a);
	calculate_cost((*b)->top, a);
	// if ((*b)->top->cost == 0)
	// 	pb(a, b);
	ft_printf("-------- B stack final --------\n");
	print_target_node(b);
}
