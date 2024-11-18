/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:15:36 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/18 00:04:37 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort(t_stack **a)
{
	int	top;
	int	mid;
	int	bottom;

	if (stack_is_sorted(a) == 1 || (*a)->size == 0 || (*a)->size == 1)
		return ;
	top = (*a)->top->value;
	mid = (*a)->top->next->value;
	bottom = (*a)->bottom->value;
	if (top < mid && mid > bottom && top < bottom)
	{
		rra(a);
		sa(a);
	}
	else if (top > mid && mid < bottom && top < bottom)
		sa(a);
	else if (top < mid && mid > bottom && top > bottom)
		rra(a);
	else if (top > mid && mid < bottom && top > bottom)
		ra(a);
	else if (top > mid && mid > bottom && mid < top)
	{
		ra(a);
		sa(a);
	}
}
//	1 2 3  *1 3 2  *2 1 3  *2 3 1  3 1 2  3 2 1
