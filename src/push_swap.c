/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:29:16 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/21 19:12:52 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Pousser les deux premiers noeuds de stack a dans b tant que a n'est pas 3
// Tant que la taille de n'est pas de 3
	// Set les target node de la list a

void	set_target_node(t_stack **b, t_stack **a)
{
	t_node	*current;

	current = (*b)->top;
	while (current != NULL)
	{
		current->target_node = best_target_node(current, a);
		if (current->target_node == NULL)
			current->target_node = find_min_number(a);
		current = current->next;
	}
}

void	calculate_cost(t_stack **b, t_stack **a)
{
	t_node	*current;
	int		common_move;

	current = (*b)->top;
	while (current != NULL)
	{
		if (current->target_node->pose > (*a)->median + 1)
			current->cost_a = -((*a)->size - current->target_node->pose + 1);
		else if (current->target_node->pose <= (*a)->median + 1)
			current->cost_a = current->target_node->pose - 1;
		if (current->pose > (*b)->median + 1)
			current->cost_b = -((*b)->size - current->pose + 1);
		else if (current->pose <= (*b)->median + 1)
			current->cost_b = current->pose - 1;
		current->all_cost = c_common_move(current->cost_a, current->cost_b);
		current = current->next;
	}
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	if ((*b)->cheapest->all_cost == 0)
		return (pa(a, b));
	//sync_rotate(a, b);
	while ((*b)->cheapest->cost_a > 0 && (*b)->cheapest->cost_b > 0)
	{
		rr(a, b);
		(*b)->cheapest->cost_a--;
		(*b)->cheapest->cost_b--;
	}
	while ((*b)->cheapest->cost_a < 0 && (*b)->cheapest->cost_b < 0)
	{
		rrr(a, b);
		(*b)->cheapest->cost_a++;
		(*b)->cheapest->cost_b++;
	}
	while ((*b)->cheapest->cost_a > 0)
	{
		ra(a);
		(*b)->cheapest->cost_a--;
	}
	while ((*b)->cheapest->cost_a < 0)
	{
		rra(a);
		(*b)->cheapest->cost_a++;
	}
	while ((*b)->cheapest->cost_b > 0)
	{
		rb(b);
		(*b)->cheapest->cost_b--;
	}
	while ((*b)->cheapest->cost_b < 0)
	{
		rrb(b);
		(*b)->cheapest->cost_b++;
	}
	pa(a, b);
}

void	final_rotate(t_stack **a)
{
	int	move_for_a;

	if ((*a)->min->pose > (*a)->median + 1)
		(*a)->min->all_cost = (*a)->size - (*a)->min->pose + 1;
	else if ((*a)->min->pose <= (*a)->median + 1)
		(*a)->min->all_cost = (*a)->min->pose - 1;
	move_for_a = (*a)->min->all_cost;
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

// Push dans b
// Trier la pile a
// Update toutes les infos
	// Set toutes les targets node
	// Set tout les cout de push
	// Choisir le noeud avec le moins de mouvement
	// Refaire tout remonter en haut de la pile
	// Push dans a
// Si pas trier mettre lelment le plus petit en haut de la pile

void	turk_algo(t_stack **a, t_stack **b)
{
	t_node	*best_node;
	int		min_cost;
	t_node	*current;

	while ((*a)->size > 3)
		pb(a, b);
	three_sort(a);
	while ((*b)->size > 0)
	{
		set_target_node(b, a);
		calculate_cost(b, a);
		check_cheapest_node(b);
		push_b_to_a(a, b);
	}
	if (stack_is_sorted(a) == 0)
	{
		(*a)->min = find_min_number(a);
		final_rotate(a);
	}
	//print_stack(a, b);
}
