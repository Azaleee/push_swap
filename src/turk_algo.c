/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:29:16 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/18 02:50:15 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Pousser les deux premiers noeuds de stack a dans b tant que a n'est pas 3
// Tant que la taille de n'est pas de 3
	// Set les target node de la list a

t_node	*best_target_node(t_node *a, t_stack **b)
{
	t_node	*current_b;
	t_node	*best_target;
	int		diff;
	int		min;

	min = INT_MAX;
	current_b = (*b)->top;
	best_target = NULL;
	while (current_b != NULL)
	{
		diff = a->value - current_b->value;
		if (diff > 0 && diff < min)
		{
			min = diff;
			best_target = current_b;
		}
		current_b = current_b->next;
	}
	return (best_target);
}

t_node	*find_max_number(t_stack **b)
{
	t_node	*current_b;
	t_node	*best_target_temp;

	current_b = (*b)->top;
	best_target_temp = NULL;
	while (current_b != NULL)
	{
		if (best_target_temp == NULL
			|| current_b->value > best_target_temp->value)
			best_target_temp = current_b;
		current_b = current_b->next;
	}
	return (best_target_temp);
}

void	set_target_node(t_stack **a, t_stack **b)
{
	t_node	*current_a;

	current_a = (*a)->top;
	while (current_a != NULL)
	{
		current_a->target_node = best_target_node(current_a, b);
		if (current_a->target_node == NULL)
			current_a->target_node = find_max_number(b);
		current_a = current_a->next;
	}
}

void	print_target_node(t_stack **a)
{
	t_node	*current;
	int		i;

	current = (*a)->top;
	i = 1;
	while (current)
	{
		ft_printf("%d -> %d target : %d\n", i, current->value, current->target_node->value);
		current = current->next;
		i++;
	}
	ft_printf("\n");
}

void	turk_algo(t_stack **a, t_stack **b)
{
	while ((*b)->size != 2)
		pb(a, b);
	set_target_node(a, b);
	print_target_node(a);
}
