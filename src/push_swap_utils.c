/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:16:02 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/21 18:59:51 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
		}
		current = current->next;
	}
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

int	c_common_move(int cost_a, int cost_b)
{
	int	common_move;

	if (cost_a < 0 && cost_b < 0
		|| cost_a > 0 && cost_b > 0)
	{
		common_move = ft_min(ft_abs(cost_a), ft_abs(cost_b));
		return (ft_abs(cost_a) + ft_abs(cost_b) - common_move);
	}
	else
		return (ft_abs(cost_a) + ft_abs(cost_b));
}

void	sync_rotate(t_stack **a, t_stack **b)
{
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
}
