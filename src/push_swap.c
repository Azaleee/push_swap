/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:44:21 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/20 01:04:39 by mosmont          ###   ########.fr       */
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
	new_node->cost = 0;
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
		ft_printf("\nMedian : %d -- Size : %d Top : %d Bottom : %d Min : %d\n", (*a)->median, (*a)->size, (*a)->top->value, (*a)->bottom->value, (*a)->min->value);
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
			ft_printf("\nMedian : %d -- Size : %d Top : %d Bottom : %d\n", (*b)->median, (*b)->size, (*b)->top->value, (*b)->bottom->value);
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
