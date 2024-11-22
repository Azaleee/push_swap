/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 01:28:44 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/22 17:34:31 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <signal.h>

void	check_and_sort(t_stack **a, t_stack **b)
{
	if ((*a)->size == 2)
	{
		if (stack_is_sorted(a) == 0)
			sa(a);
	}
	else if ((*a)->size == 3)
		three_sort(a);
	else if ((*a)->size > 3 && (*b)->size == 0)
	{
		turk_algo(a, b);
	}
}

void	ft_lstclear_stack(t_stack **stack)
{
	t_node	*temp;
	t_node	*current;

	current = (*stack)->top;
	while (current != NULL)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	(*stack)->top = NULL;
	(*stack)->bottom = NULL;
	(*stack)->min = NULL;
	(*stack)->cheapest = NULL;
	(*stack)->size = 0;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (av == NULL)
			exit_error();
	}
	check_input(ac, av);
	a = fill_stack(ac, av);
	b = init_stack();
	if (stack_is_sorted(&a) == 0)
		check_and_sort(&a, &b);
	ft_lstclear_stack(&a);
	return (0);
}
