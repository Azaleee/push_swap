/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:44:21 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/18 02:41:29 by mosmont          ###   ########.fr       */
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
	return (stack);
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
	if (stack->bottom == NULL)
		stack->bottom = new_node;
	stack->size++;
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

void	print_stack(t_stack **stack)
{
	t_node	*current;
	int		i;

	current = (*stack)->top;
	i = 1;
	while (current)
	{
		ft_printf("%d : %d\n", i, current->value);
		current = current->next;
		i++;
	}
	ft_printf("\n");
}
