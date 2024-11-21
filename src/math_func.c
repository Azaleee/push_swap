/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosmont <mosmont@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:35:50 by mosmont           #+#    #+#             */
/*   Updated: 2024/11/21 18:39:15 by mosmont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	else
		return (number);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
