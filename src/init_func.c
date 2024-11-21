/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:44:21 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/21 18:34:55 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (stack == NULL)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	stack->median = 0;
	stack->min = NULL;
	return (stack);
}

void	update_position(t_stack *stack)
{
	t_node	*current;
	int		i;

	stack->median = stack->size / 2;
	current = stack->top;
	i = 1;
	while (current != NULL)
	{
		current->pose = i++;
		current = current->next;
	}
}

void	push_stack(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		return ;
	new_node->value = value;
	new_node->next = stack->top;
	new_node->prev = NULL;
	new_node->target_node = NULL;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->all_cost = 0;
	if (stack->top != NULL)
		stack->top->prev = new_node;
	stack->top = new_node;
	stack->min = NULL;
	stack->top->pose = 0;
	if (stack->bottom == NULL)
		stack->bottom = new_node;
	if (stack->top != NULL)
		update_position(stack);
	stack->size++;
	stack->cheapest = NULL;
	stack->median = stack->size / 2;
}

t_stack	*fill_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack;

	stack = init_stack();
	if (ac == 2)
	{
		i = 0;
		while (av[i])
			i++;
		while (--i >= 0)
			push_stack(stack, ft_atoi(av[i]));
	}
	else
	{
		i = ac;
		while (--i > 0)
			push_stack(stack, ft_atoi(av[i]));
	}
	return (stack);
}
