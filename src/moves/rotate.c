/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:36:19 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/12 21:54:05 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_node	*temp;

	temp = (*stack)->top;
	(*stack)->top = (*stack)->top->next;
	(*stack)->top->prev = NULL;
	temp->next = NULL;
	temp->prev = (*stack)->bottom;
	(*stack)->bottom->next = temp;
	(*stack)->bottom = temp;
}

void	ra(t_stack **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
