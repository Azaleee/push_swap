/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:29:16 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/21 04:30:00 by mosmont          ###   ########.fr       */
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

void	set_target_node(t_stack **b, t_stack **a)
{
	t_node	*current;

	current = (*b)->top;
	while (current != NULL)
	{
		current->target_node = best_target_node(current, a);
		if (current->target_node == NULL)
			current->target_node = find_min_number(a);
		//ft_printf("%d --> %d \n", current->value, current->target_node->value);
		current = current->next;
	}
}

void	calculate_cost(t_stack **b, t_stack **a)
{
	t_node	*current;

	current = (*b)->top;
	while (current != NULL)
	{
		if (current->target_node->pose > (*a)->median + 1)
			current->cost_a = (*a)->size - current->target_node->pose + 1;
		else if (current->target_node->pose <= (*a)->median + 1)
			current->cost_a = current->target_node->pose - 1;
		if (current->pose > (*b)->median + 1)
			current->cost_b = (*b)->size - current->pose + 1;
		else if (current->pose <= (*b)->median + 1)
			current->cost_b = current->pose - 1;
		current->all_cost = current->cost_a + current->cost_b;
		//print_stack(a, b);
		//ft_printf("Node %d -> %d: Cost for a: %d, Cost for b: %d, Total cost: %d\n", 
		//	current->value, current->target_node->value, current->cost_a, current->cost_b, current->all_cost);
		current = current->next;
	}
}

void	rotate_for_top(t_stack **src, t_node *target)
{
	int	move_for_src;

	if (target == (*src)->top)
		return ;
	if (target->pose > (*src)->median)
	{
		move_for_src = target->pose;
		while (move_for_src-- > 0)
			rra(src);
	}
	else
	{
		move_for_src = (*src)->size - target->pose;
		while (move_for_src-- > 0)
			ra(src);
	}
}

void	push_b_to_a(t_stack **a, t_stack **b)
{
	int	cost_a;
	int	cost_b;
	if ((*b)->cheapest->all_cost == 0)
		return (pa(a, b));

	if ((*b)->cheapest->pose <= (*b)->median + 1 && (*b)->cheapest->target_node->pose <= (*a)->median + 1)
	{
		while ((*b)->cheapest->cost_a > 0 && (*b)->cheapest->cost_b > 0)
		{
			rr(a, b);
			(*b)->cheapest->cost_a--;
			(*b)->cheapest->cost_b--;
		}
	}
	else if ((*b)->cheapest->pose > (*b)->median + 1 && (*b)->cheapest->target_node->pose > (*a)->median + 1)
	{
		while ((*b)->cheapest->cost_a > 0 && (*b)->cheapest->cost_b > 0)
		{
			rrr(a, b);
			(*b)->cheapest->cost_a--;
			(*b)->cheapest->cost_b--;
		}
	}
	
	if ((*b)->cheapest->pose <= (*b)->median + 1 && (*b)->cheapest->cost_b != 0)
	{
		while ((*b)->cheapest->cost_b-- != 0)
			rb(b);
	}
	else
	{
		while ((*b)->cheapest->cost_b-- != 0)
			rrb(b);
	}
	if ((*b)->cheapest->target_node->pose <= (*a)->median + 1 && (*b)->cheapest->cost_a != 0)
	{
		while ((*b)->cheapest->cost_a-- != 0)
			ra(a);
	}
	else
	{
		while ((*b)->cheapest->cost_a-- != 0)
			rra(a);
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
	//ft_printf("============pose : %d  cost : %d===sadasdasdsadasd", (*a)->min->pose, (*a)->min->all_cost);
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
		// if (current->target_node != NULL)
		// 	ft_printf("%d -> %d -> %d target : %d -> cost : %d -> pose : %d\n", current->pose, current->value, current->all_cost, current->target_node->value, current->target_node->all_cost, current->target_node->pose);
		// else
		// 	ft_printf("%d -> %d target : pas verif\n", i, current->value);
		current = current->next;
		i++;
	}
	ft_printf("\n");
}

void	check_cheapest_node(t_stack **b)
{
	t_node	*current;
	t_node	*cheapest_node;
	int		min_cost;

	if ((*b) == NULL)
		return ;
	current = (*b)->top;
	min_cost = INT_MAX;
	while (current)
	{
		if (min_cost > current->all_cost)
		{
			min_cost = current->all_cost;
			(*b)->cheapest = current;
			//printf("Cheapest node value : %d", (*b)->cheapest->value);
		}
		current = current->next;
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
		//print_stack(a, b);
		push_b_to_a(a, b);
		//print_target_node(b);
	}
	// 	best_node = (*b)->top;
	// 	current = best_node->next;
	// 	min_cost = best_node->cost;
	// 	while (current != NULL)
	// 	{
	// 		if (current->cost < min_cost)
	// 		{
	// 			min_cost = current->cost;
	// 			best_node = current;
	// 		}
	// 		current = current->next;
	// 	}
	// 	push_b_to_a(a, b, best_node);
	// }
		//ft_printf("Push b -> a: Node b = (%d) %d, Target a = (%d) %d ; cost -> %d\n", 
                  //(*b)->top->pose, (*b)->top->value, (*b)->top->target_node->pose ,(*b)->top->target_node->value, (*b)->top->target_node->cost);
	//push_b_to_a(a, b, (*b)->top, (*b)->top->target_node);s
	if (stack_is_sorted(a) == 0)
	{
		(*a)->min = find_min_number(a);
		final_rotate(a);
	}
	// print_stack(a, b);
	// t_node *test = (*a)->top;
	// while (test && test->next)
	// {
	// 	printf("%d\n", test->value);
	// 	if (test->value > test->next->value)
	// 		printf("bw ta nerer");
	// 	test = test->next;
	// }
}
