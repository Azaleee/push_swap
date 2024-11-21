/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:24:06 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/21 19:06:56 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_target_node(t_stack **a)
{
	t_node	*current;
	int		i;

	current = (*a)->top;
	i = 1;
	while (current)
	{
		current = current->next;
		i++;
	}
	ft_printf("\n");
}

void	print_stack(t_stack **a, t_stack **b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		i;

	current_a = (*a)->top;
	current_b = (*b)->top;
	i = 1;
	if (current_a != NULL)
	{
		ft_printf("=================================");
		ft_printf("\nMedian : %d -- Size : %d Top : %d Bottom : %d Min : %d\n", (*a)->median, (*a)->size, (*a)->top->value, (*a)->bottom->value);
		while (current_a)
		{
			ft_printf("%d : (%p) %d next -> (%p) prev -> (%p)\n", current_a->pose, current_a, current_a->value, current_a->next, current_a->prev);
			current_a = current_a->next;
			i++;
		}
	}
	ft_printf("\n---------------------------------\n");
	if (current_b != NULL)
	{
		if ((*b)->top && (*b)->bottom)
			ft_printf("\nMedian : %d -- Size : %d Top : %d Bottom : %d Cheapest : %d -> %d\n", (*b)->median, (*b)->size, (*b)->top->value, (*b)->bottom->value, (*b)->cheapest->pose, (*b)->cheapest->target_node->pose);
		else
			ft_printf("\nMedian : %d -- Size : %d Top : NULL Bottom : NULL\n", (*b)->median, (*b)->size);
		while (current_b)
		{
			ft_printf("%d : (%p) %d next -> (%p) prev -> (%p)\n", current_b->pose, current_b, current_b->value, current_b->next, current_b->prev);
			current_b = current_b->next;
			i++;
		}
	}
	ft_printf("=================================\n\n\n\n");
	ft_printf("\n");
}