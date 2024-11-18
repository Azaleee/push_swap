/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 00:36:44 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/18 21:46:11 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_node	*temp;

	if ((*src)->top == NULL)
		return ;
	temp = (*src)->top;
	(*src)->top = (*src)->top->next;
	(*src)->top->prev = NULL;
	(*src)->size--;
	(*src)->median = (*src)->size / 2;
	if ((*src)->top != NULL)
		update_position((*src));
	temp->next = (*dest)->top;
	temp->prev = NULL;
	if ((*dest)->top != NULL)
	{
		(*dest)->top->prev = temp;
		update_position((*dest));
	}
	(*dest)->top = temp;
	if ((*dest)->bottom == NULL)
		(*dest)->bottom = temp;
	(*dest)->size++;
	(*dest)->median = (*dest)->size / 2;
}

void	pb(t_stack **a, t_stack **b)
{
	if ((*a)->top == NULL)
		return ;
	push(a, b);
	ft_printf("pb\n");
}

void	pa(t_stack **a, t_stack **b)
{
	if ((*b)->top == NULL)
		return ;
	push(b, a);
	ft_printf("pa\n");
}
