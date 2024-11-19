/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:29:16 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/20 00:19:28 by mosmont          ###   ########.fr       */
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
	//(*a)->min = best_target_temp;
	return (best_target_temp);
}

void	set_target_node(t_node *b, t_stack **a)
{
	b->target_node = best_target_node(b, a);
	if (b->target_node == NULL)
		b->target_node = find_min_number(a);
}

void	calculate_cost(t_node *b, t_stack **a, int median_of_b)
{
	if (b->target_node == NULL)
		return ;
	if (b->prev == NULL && (*a)->top == b->target_node)
	{
		b->target_node->cost = 0;
		b->cost = 0;
	}
	if (b->target_node->pose > (*a)->median + 1)
		b->target_node->cost = b->target_node->pose - ((*a)->median + 1);
	else if (b->target_node->pose <= (*a)->median + 1)
		b->target_node->cost = b->target_node->pose - 1;

	if (b->pose > median_of_b + 1)
		b->cost = b->pose - (median_of_b + 1);
	else if (b->pose <= median_of_b + 1)
		b->cost = b->pose - 1;
}

void	push_b_to_a(t_stack **a, t_stack **b, t_node *current, t_node *target)
{
	int	move_for_b;
	int	move_for_a;


	if (target->cost + current->cost == 0)
		return (pa(a, b));
	move_for_a = target->cost;
	if (target->pose > (*a)->median + 1)
	{
		while (move_for_a-- != 0)
			rra(a);
	}
	else if (target->pose <= (*a)->median + 1)
	{
		while (move_for_a-- != 0)
			ra(a);
	}
	pa(a, b);
}

void	final_rotate(t_stack **a)
{
	int	move_for_a;

	if ((*a)->min->pose > (*a)->median + 1)
		(*a)->min->cost = (*a)->size - (*a)->min->pose + 1;
	else if ((*a)->min->pose <= (*a)->median + 1)
		(*a)->min->cost = (*a)->min->pose - 1;
	move_for_a = (*a)->min->cost;
	//ft_printf("============pose : %d  cost : %d===sadasdasdsadasd", (*a)->min->pose, (*a)->min->cost);
	if ((*a)->min->pose > (*a)->median + 1)
	{
		while (move_for_a-- != 0)
			rra(a);
	}
	else if ((*a)->min->pose <= (*a)->median + 1)
	{
		while (move_for_a-- != 0)
			ra(a);
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
		if (current->target_node != NULL)
			ft_printf("%d -> %d -> %d target : %d -> cost : %d -> pose : %d\n", current->pose, current->value, current->cost, current->target_node->value, current->target_node->cost, current->target_node->pose);
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
	}
	three_sort(a);
	while ((*b)->size > 0)
	{
		set_target_node((*b)->top, a);
		calculate_cost((*b)->top, a, (*b)->median);
		push_b_to_a(a, b, (*b)->top, (*b)->top->target_node);
	}
	if (stack_is_sorted(a) == 0)
	{
		(*a)->min = find_min_number(a);
		//print_stack(a, b);
		final_rotate(a);
	}
}
