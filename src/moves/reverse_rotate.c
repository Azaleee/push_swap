/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:36:19 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/12 23:13:01 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_node	*temp;

	if ((*stack)->size <= 1)
		return ;
	temp = (*stack)->bottom;
	(*stack)->bottom = (*stack)->bottom->prev;
	(*stack)->bottom->next = NULL;
	temp->prev = NULL;
	temp->next = (*stack)->top;
	(*stack)->top->prev = temp;
	(*stack)->top = temp;
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
