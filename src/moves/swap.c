/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:46:47 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/19 01:51:08 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	swap(t_stack **stack)
{
	t_node	*first;
	t_node	*second;

	if (*stack == NULL || (*stack)->top == NULL || (*stack)->top->next == NULL
		|| (*stack)->size < 2)
		return ;
	first = (*stack)->top;
	second = first->next;
	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	(*stack)->top = second;
	if ((*stack)->size == 2)
		((*stack)->bottom = first);
	update_position((*stack));
}

void	sa(t_stack **a)
{
	if ((*a)->top == NULL)
		return ;
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	if ((*b)->top == NULL)
		return ;
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	if ((*a)->top == NULL || (*b)->top == NULL)
		return ;
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
